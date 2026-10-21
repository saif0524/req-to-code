"""
One repair round over a stored run: compile repair (C) or security repair (S).

Reads   results/runs/<parent>/<arm>__<model>/s<i>/   (needs verify.py output)
Writes  results/runs/<round>/<arm>__<model>/s<i>/    a full snapshot: repaired units plus
                                                     every other unit carried forward

Kinds
  compile   units that are not `usable`. Per function, one model call:
              function has a body but errors fall in its lines -> fix prompt with the
                compiler errors (line numbers relative to the function) and its code
              function is missing or has no body              -> the original implement prompt
              errors in the shared declarations               -> one fix call on the declarations
              unit has no plan (plan_error)                   -> plan + functions regenerated
            A fix may return `added_declarations` (types the function needs); they are
            appended to the shared declarations when not already present.
  secure    usable units whose functions have cppcheck findings. Each such function gets
            "Secure it." with its code; no tool output is shown unless --show-findings.
            A unit that stops compiling, or a function that loses its body, is reverted
            to the parent version and logged (`reverted`, `rejected`).

The system prompt is the arm's own header (general or secure), as in R0. Seeds derive from
(unit, arm, round, sample, function) and are logged. Each run directory gets a
manifest.json with `parent`, `kind`, temperature and the prompt hash.

    python3 scripts/repair.py --parent R0 --round C1 --kind compile --model qwen25coder3b --limit 5
    python3 scripts/repair.py --parent C1 --round C2 --kind compile --verify
    python3 scripts/repair.py --parent C2 --round S1 --kind secure --arm secure
"""
import argparse
import csv
import hashlib
import json
import re
import shutil
import subprocess
import sys
import time
from datetime import datetime, timezone
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import gen_functions as gf  # noqa: E402
from verify import code_has_body  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs"
UNITS = ROOT / "data" / "requirements_units.jsonl"
MODELS = ROOT / "scripts" / "models.json"
ARM_VARIANT = {"general": "baseline", "secure": "secure_prompt"}

REPAIR_SCHEMA = {
    "type": "object",
    "properties": {
        "reasoning": {"type": "array", "items": {"type": "string"}},
        "code": {"type": "string"},
        "added_declarations": {"type": "string"},
    },
    "required": ["reasoning", "code", "added_declarations"],
}
SHARED_SCHEMA = {
    "type": "object",
    "properties": {"reasoning": {"type": "array", "items": {"type": "string"}},
                   "shared_declarations": {"type": "string"}},
    "required": ["reasoning", "shared_declarations"],
}

ERR_RE = re.compile(r"^[^:\n]+:(\d+):(?:\d+:)?\s*(?:fatal )?error:\s*(.*)$")


# ---------------------------------------------------------------- assembly and errors

def assemble_unit(shared, plan, codes):
    """Source for a unit. codes[i] is the function body text or None.
    Returns (source, info) with 1-based inclusive line ranges."""
    lines = gf.INCLUDES + ["", "using namespace std;", ""]
    shared_range = None
    if shared:
        s = len(lines) + 1
        lines += shared.splitlines()
        shared_range = (s, len(lines))
        lines.append("")
    proto = {}
    for i, p in enumerate(plan):
        lines.append(f"{p['signature'].rstrip().rstrip(';')};")
        proto[i] = len(lines)
    lines.append("")
    ranges = {}
    for i, code in enumerate(codes):
        if not code:
            continue
        s = len(lines) + 1
        lines += code.splitlines()
        ranges[i] = (s, len(lines))
        lines.append("")
    return "\n".join(lines) + "\n", {"shared": shared_range, "proto": proto, "funcs": ranges}


def compile_errors(path):
    """Return (ok, [(line, message)])."""
    try:
        r = subprocess.run(["g++", "-std=c++17", "-fsyntax-only", str(path)],
                           capture_output=True, text=True, timeout=120)
    except (OSError, subprocess.TimeoutExpired):
        return False, []
    errs = []
    for l in r.stderr.splitlines():
        m = ERR_RE.match(l)
        if m:
            errs.append((int(m.group(1)), m.group(2)[:200]))
    return r.returncode == 0, errs


def bucket_errors(errs, info, n_funcs):
    """Return (shared_errors, per_function_errors) with function-relative line numbers."""
    per = {i: [] for i in range(n_funcs)}
    shared = []
    for line, msg in errs:
        hit = False
        for i, (s, e) in info["funcs"].items():
            if s <= line <= e:
                per[i].append((line - s + 1, msg))
                hit = True
                break
        if hit:
            continue
        for i, pl in info["proto"].items():
            if pl == line:
                per[i].append((0, msg + " (in the function's prototype)"))
                hit = True
                break
        if not hit:
            shared.append((line, msg))
    return shared, per


def fmt_errors(errs, limit=8):
    out = [f"line {l}: {m}" if l else m for l, m in errs[:limit]]
    if len(errs) > limit:
        out.append(f"... {len(errs) - limit} more")
    return "\n".join(out)


# ---------------------------------------------------------------- prompts

def context_block(u, shared, plan, others):
    lines = [gf.req_block(u), ""]
    if shared:
        lines += ["Shared declarations (already in the file, do not repeat them):", shared, ""]
    lines += ["Planned functions:"] + [f"- {p['signature']}  // {p['purpose']}" for p in plan]
    if others:
        lines += ["", "Other functions already in the file:", *others]
    return "\n".join(lines)


def fix_prompt(u, shared, plan, idx, others, code, errs):
    return "\n".join([
        context_block(u, shared, plan, others), "",
        f"This function does not compile: {plan[idx]['signature']}",
        "Compiler errors (line 1 is the first line of the function):", fmt_errors(errs), "",
        "Current code:", code, "",
        "Return JSON with 'reasoning': 3 to 6 short steps saying what is wrong and how you fix it, "
        "'code': the complete corrected function definition only (no #include lines, no main), and "
        "'added_declarations': any struct, enum, using alias or constant your fix needs that is "
        "missing from the shared declarations, declarations only, or an empty string.",
    ])


def shared_fix_prompt(u, shared, plan, errs):
    return "\n".join([
        gf.req_block(u), "",
        "These shared declarations do not compile:", shared, "",
        "Compiler errors (line numbers are within the full file):", fmt_errors(errs), "",
        "Planned functions that use them:", *[f"- {p['signature']}" for p in plan], "",
        "Return JSON with 'reasoning': 3 to 6 short steps, and 'shared_declarations': the corrected "
        "declarations only (no function definitions, no #include lines).",
    ])


def secure_prompt(u, shared, plan, idx, others, code, findings):
    lines = [context_block(u, shared, plan, others), "",
             f"Secure it. Function: {plan[idx]['signature']}", "Current code:", code, ""]
    if findings:
        lines += ["Static analysis reported:", findings, ""]
    lines += ["Keep the signature and the behaviour the requirement asks for. "
              "Return JSON with 'reasoning': 3 to 6 short steps saying what could go wrong and what you "
              "change, 'code': the complete function definition only (no #include lines, no main), and "
              "'added_declarations': any declarations the new code needs that are missing from the "
              "shared declarations, or an empty string."]
    return "\n".join(lines)


# ---------------------------------------------------------------- model calls

def seed_for(*parts):
    return int(hashlib.sha256("|".join(map(str, parts)).encode()).hexdigest()[:8], 16) % (2 ** 31)


class Caller:
    def __init__(self, llm, base_key):
        self.llm, self.base_key, self.calls = llm, base_key, 0

    def __call__(self, system, user, schema, label):
        self.llm.seed = seed_for(*self.base_key, label)
        self.calls += 1
        res, err = self.llm.chat_json_retry(system, user, schema)
        return res, err, self.llm.last_thinking


def clean_code(raw):
    code, _ = gf.fix_literal_newlines(gf.strip_fences(raw))
    code, _ = gf.repair_strings(code)
    return code


def add_declarations(shared, extra):
    extra = gf.strip_fences(extra or "").strip()
    if not extra or extra in (shared or ""):
        return shared
    return (shared + "\n" if shared else "") + extra


# ---------------------------------------------------------------- unit state

def load_jsonl(path):
    if not path.exists():
        return []
    return [json.loads(l) for l in path.read_text(encoding="utf-8").splitlines() if l.strip()]


def func_state(plan, recs):
    """Align records to plan entries by name, in order. Returns list of dicts or None."""
    pool = list(recs)
    out = []
    for p in plan:
        hit = next((r for r in pool if r["name"] == p["name"]), None)
        if hit:
            pool.remove(hit)
        out.append(hit)
    return out


def rec_code(rec):
    return rec["code"] if rec and code_has_body(rec.get("code")) else None


# ---------------------------------------------------------------- repair of one unit

def repair_compile(u, parent_unit, parent_recs, system, call, out_code_path, log):
    plan = parent_unit.get("plan") or []
    shared = parent_unit.get("shared_declarations") or ""
    steps = {}                       # idx -> dict(code, reasoning, thinking, repaired)
    errors_log = []

    if not plan:                     # plan_error: regenerate from the plan stage
        raw, err, _ = call(system, gf.plan_prompt(u, 5), gf.PLAN_SCHEMA, "plan")
        if raw is None:
            return None, [{"stage": "plan", "error": err}], "plan_error"
        items = [p for p in raw["functions"] if p.get("name") and p.get("signature")]
        types = [p["signature"] for p in items if gf.TYPE_DECL.match(p["signature"])]
        plan = [p for p in items if not gf.TYPE_DECL.match(p["signature"])][:5]
        shared = gf.strip_fences("\n".join([raw.get("shared_declarations") or "", *types])) if plan else ""
        if not plan:
            return None, [], "no_code"
        parent_recs = []
        log["regenerated"] = True

    state = func_state(plan, parent_recs)
    codes = [rec_code(r) for r in state]
    n = len(plan)

    src, info = assemble_unit(shared, plan, codes)
    out_code_path.write_text(src, encoding="utf-8")
    ok, errs = compile_errors(out_code_path)
    shared_errs, per = bucket_errors(errs, info, n)

    if shared and shared_errs:
        res, err, _ = call(system, shared_fix_prompt(u, shared, plan, shared_errs),
                           SHARED_SCHEMA, "shared")
        if res and res.get("shared_declarations", "").strip():
            shared = gf.strip_fences(res["shared_declarations"])
            log["shared_repaired"] = True
        elif err:
            errors_log.append({"stage": "shared", "error": err})

    for i in range(n):
        have = codes[i]
        needs_impl = have is None
        needs_fix = have is not None and bool(per[i])
        if not (needs_impl or needs_fix):
            continue
        others = [c for j, c in enumerate(codes) if c and j != i]
        if needs_impl:
            written = [{"code": c} for j, c in enumerate(codes) if c and j != i]
            res, err, th = call(system, gf.func_prompt(u, shared, plan, i, written),
                                gf.FUNC_SCHEMA, f"impl:{plan[i]['name']}")
            extra = ""
        else:
            res, err, th = call(system, fix_prompt(u, shared, plan, i, others, have, per[i]),
                                REPAIR_SCHEMA, f"fix:{plan[i]['name']}")
            extra = (res or {}).get("added_declarations", "")
        if res is None:
            errors_log.append({"stage": "func", "func": plan[i]["name"], "error": err})
            continue
        code = clean_code(res["code"])
        if not code_has_body(code):
            errors_log.append({"stage": "func", "func": plan[i]["name"], "error": "no body returned"})
            continue
        codes[i] = code
        shared = add_declarations(shared, extra)
        steps[i] = {"code": code, "thinking": th, "repaired": True,
                    "reasoning": [r.strip() for r in res["reasoning"] if r.strip()],
                    "action": "implement" if needs_impl else "fix"}

    return {"plan": plan, "shared": shared, "codes": codes, "state": state, "steps": steps}, errors_log, "ok"


def repair_secure(u, parent_unit, parent_recs, parent_verify_funcs, system, call, show_findings):
    plan = parent_unit["plan"]
    shared = parent_unit.get("shared_declarations") or ""
    state = func_state(plan, parent_recs)
    codes = [rec_code(r) for r in state]
    steps, rejected, errors_log = {}, [], []
    counts = {(r["func"]): r for r in parent_verify_funcs}
    for i, p in enumerate(plan):
        vf = counts.get(p["name"])
        if not vf or int(vf["cppcheck_findings"]) == 0 or not codes[i]:
            continue
        findings = ""
        if show_findings:
            findings = "\n".join(f"{k} x{v}" for k, v in json.loads(vf["cppcheck_classes"]).items())
        others = [c for j, c in enumerate(codes) if c and j != i]
        res, err, th = call(system, secure_prompt(u, shared, plan, i, others, codes[i], findings),
                            REPAIR_SCHEMA, f"sec:{p['name']}")
        if res is None:
            errors_log.append({"stage": "secure", "func": p["name"], "error": err})
            continue
        code = clean_code(res["code"])
        name_ok = re.search(r"\b" + re.escape(p["name"]) + r"\s*\(", code) is not None
        if not code_has_body(code) or not name_ok:
            rejected.append(p["name"])
            continue
        steps[i] = {"code": code, "thinking": th, "repaired": True, "action": "secure",
                    "reasoning": [r.strip() for r in res["reasoning"] if r.strip()],
                    "added": res.get("added_declarations", "")}
    return steps, rejected, errors_log


# ---------------------------------------------------------------- run driver

def model_config(model_dir):
    for m in json.loads(MODELS.read_text()):
        if re.sub(r"[^a-z0-9]+", "", m["tag"].lower()) == model_dir:
            return m
    raise SystemExit(f"{model_dir} not in models.json")


def write_unit(out, unit_id, plan, shared, codes, base, steps, state, round_name, parent_round):
    """Write code file and return (record rows, info)."""
    src, info = assemble_unit(shared, plan, codes)
    path = out / "code" / f"{unit_id}.cpp"
    path.write_text(src, encoding="utf-8")
    rows = []
    for k, i in enumerate(sorted(info["funcs"])):
        s, e = info["funcs"][i]
        step, old = steps.get(i), state[i] if i < len(state) else None
        rows.append({
            **base, "func_index": k, "name": plan[i]["name"], "signature": plan[i]["signature"],
            "purpose": plan[i]["purpose"],
            "reasoning": step["reasoning"] if step else (old or {}).get("reasoning", []),
            "thinking": step["thinking"] if step else (old or {}).get("thinking", ""),
            "code": codes[i], "start_line": s, "end_line": e,
            "code_file": f"code/{unit_id}.cpp", "repaired": bool(step),
            "action": step["action"] if step else "",
            "reasoning_round": round_name if step else (old or {}).get("reasoning_round", parent_round),
        })
    return path, rows


def run_config(args, units_by_id, parent_dir, arm, model_dir, sample):
    parent_manifest = json.loads((parent_dir / "manifest.json").read_text())
    cfg = model_config(model_dir)
    out = RUNS / args.round / f"{arm}__{model_dir}" / f"s{sample}"
    (out / "code").mkdir(parents=True, exist_ok=True)
    p_units = {u["unit_id"]: u for u in load_jsonl(parent_dir / "units.jsonl")}
    p_recs = {}
    for r in load_jsonl(parent_dir / "records.jsonl"):
        p_recs.setdefault(r["unit_id"], []).append(r)
    with open(parent_dir / "verify_units.csv", newline="", encoding="utf-8") as f:
        p_ver = {r["unit_id"]: r for r in csv.DictReader(f)}
    p_vfun = {}
    with open(parent_dir / "verify_functions.csv", newline="", encoding="utf-8") as f:
        for r in csv.DictReader(f):
            p_vfun.setdefault(r["unit_id"], []).append(r)

    done = {u["unit_id"] for u in load_jsonl(out / "units.jsonl")}
    system = gf.system_prompt(ARM_VARIANT[arm])
    # 0.2 unless the model needs more (DeepCoder loops at 0.0; models.json gives 0.6)
    temperature = args.temperature if args.temperature is not None else max(0.2, cfg["temperature"])
    llm = gf.Ollama(cfg["tag"], args.host, max(cfg["num_ctx"], 8192), cfg["max_tokens"],
                    seed=0, temperature=temperature)

    ids = sorted(p_units)
    if args.limit:
        ids = ids[: args.limit]
    todo = [i for i in ids if i not in done]
    print(f"[{args.round}] {arm}__{model_dir}/s{sample}: {len(todo)} units "
          f"({len(done)} done) <- {args.parent}", flush=True)

    t_start = time.time()
    n_attempted = 0
    for n, uid in enumerate(todo, 1):
        pu, ver = p_units[uid], p_ver.get(uid)
        usable = bool(ver and int(ver["usable"]))
        funcs_with_findings = any(int(f["cppcheck_findings"]) > 0 for f in p_vfun.get(uid, []))
        if args.kind == "compile":
            select = not usable and (bool(pu.get("plan")) or pu["status"] == "plan_error")
        else:
            select = usable and funcs_with_findings
        base = {"unit_id": uid, "variant": pu["variant"], "model": pu["model"],
                "seed": args.seed_base, "system_hash": pu["system_hash"]}
        row = {**base, "round": args.round, "parent": args.parent, "kind": args.kind,
               "attempted": bool(select), "reverted": False, "rejected": [], "errors": []}
        t0 = time.time()
        code_path = out / "code" / f"{uid}.cpp"
        u = units_by_id.get(uid)

        if select and u is not None:
            n_attempted += 1
            call = Caller(llm, (uid, arm, args.round, sample))
            plan, shared = pu.get("plan") or [], pu.get("shared_declarations") or ""
            recs = p_recs.get(uid, [])
            log = {}
            if args.kind == "compile":
                res, errs, status = repair_compile(u, pu, recs, system, call, code_path, log)
                row["errors"], row["status"] = errs, status
                if res:
                    plan, shared = res["plan"], res["shared"]
                    path, rows = write_unit(out, uid, plan, shared, res["codes"], base,
                                            res["steps"], res["state"], args.round, args.parent)
                    row.update(log)
                else:
                    rows = []
                    status = row["status"]
            else:
                steps, rejected, errs = repair_secure(u, pu, recs, p_vfun.get(uid, []),
                                                      system, call, args.show_findings)
                row["rejected"], row["errors"] = rejected, errs
                state = func_state(plan, recs)
                codes = [rec_code(r) for r in state]
                new_codes, new_shared = list(codes), shared
                for i, st in steps.items():
                    new_codes[i] = st["code"]
                    new_shared = add_declarations(new_shared, st.get("added"))
                path, rows = write_unit(out, uid, plan, new_shared, new_codes, base, steps,
                                        state, args.round, args.parent)
                ok, _ = compile_errors(path)
                row["status"] = pu["status"]
                if steps and not ok:       # revert to the parent version, keep the attempt logged
                    row["reverted"] = True
                    shutil.copyfile(parent_dir / "code" / f"{uid}.cpp", path)
                    rows = [dict(r, repaired=False, action="reverted",
                                 reasoning_round=r["reasoning_round"]) for r in p_recs.get(uid, [])]
                    new_shared = shared
                shared = new_shared
            row["plan"], row["shared_declarations"] = plan, shared
            row["n_functions"] = len(rows)
            row["model_calls"] = call.calls
        else:
            # carried forward unchanged
            if (parent_dir / "code" / f"{uid}.cpp").exists():
                shutil.copyfile(parent_dir / "code" / f"{uid}.cpp", code_path)
            rows = [dict(r, repaired=False, action="",
                         reasoning_round=r.get("reasoning_round", args.parent))
                    for r in p_recs.get(uid, [])]
            row.update({"status": pu["status"], "plan": pu.get("plan"),
                        "shared_declarations": pu.get("shared_declarations"),
                        "n_functions": len(rows), "carried": True})

        row["seconds"] = round(time.time() - t0, 1)
        with open(out / "records.jsonl", "a", encoding="utf-8") as f:
            for r in rows:
                f.write(json.dumps(r, ensure_ascii=False) + "\n")
        with open(out / "units.jsonl", "a", encoding="utf-8") as f:
            f.write(json.dumps(row, ensure_ascii=False) + "\n")
        if select:
            print(f"  [{n}/{len(todo)}] {uid}: {row.get('status')} calls={row.get('model_calls')}"
                  f"{' REVERTED' if row['reverted'] else ''} {row['seconds']:.0f}s", flush=True)

    all_rows = load_jsonl(out / "units.jsonl")
    code_hashes = {p.stem: hashlib.sha256(p.read_bytes()).hexdigest()
                   for p in sorted((out / "code").glob("*.cpp"))}
    manifest = {
        "round": args.round, "arm": arm, "model": model_dir, "model_tag": cfg["tag"],
        "sample": sample, "parent": args.parent, "kind": args.kind,
        "temperature": temperature, "seed_scheme": "sha256(unit|arm|round|sample|label)",
        "show_findings": args.show_findings, "system_hash": hashlib.sha1(system.encode()).hexdigest()[:8],
        "num_ctx": max(cfg["num_ctx"], 8192), "num_predict": cfg["max_tokens"],
        "n_units": len(all_rows),
        "n_attempted": sum(1 for r in all_rows if r.get("attempted")),
        "n_reverted": sum(1 for r in all_rows if r.get("reverted")),
        "code_sha256": code_hashes,
        "created": datetime.now(timezone.utc).isoformat(timespec="seconds"),
        "parent_manifest_source": parent_manifest.get("source"),
    }
    (out / "manifest.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")
    print(f"  done: {n_attempted} attempted in {time.time() - t_start:.0f}s", flush=True)
    return out


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--parent", required=True, help="round to read, e.g. R0")
    ap.add_argument("--round", required=True, help="round to write, e.g. C1")
    ap.add_argument("--kind", required=True, choices=["compile", "secure"])
    ap.add_argument("--arm", choices=["general", "secure"], help="default: both")
    ap.add_argument("--model", help="directory tag such as qwen25coder3b; default: all")
    ap.add_argument("--sample", type=int, default=0)
    ap.add_argument("--temperature", type=float, default=None,
                    help="default: max(0.2, models.json temperature)")
    ap.add_argument("--seed-base", type=int, default=0, help="logged only; seeds are derived")
    ap.add_argument("--show-findings", action="store_true", help="secure: include cppcheck classes")
    ap.add_argument("--limit", type=int, help="first N units per run, for smoke tests")
    ap.add_argument("--host", default="http://localhost:11434")
    ap.add_argument("--verify", action="store_true", help="run verify.py on the new round after")
    args = ap.parse_args()

    units_by_id = {}
    for l in UNITS.read_text(encoding="utf-8").splitlines():
        if l.strip():
            u = json.loads(l)
            units_by_id[u["unit_id"]] = u

    outs = []
    for cfg_dir in sorted((RUNS / args.parent).glob("*__*")):
        arm, model_dir = cfg_dir.name.split("__", 1)
        if args.arm and arm != args.arm:
            continue
        if args.model and model_dir != args.model:
            continue
        parent_dir = cfg_dir / f"s{args.sample}"
        if not (parent_dir / "verify_units.csv").exists():
            print(f"skip {cfg_dir.name}: no verify output in {args.parent}; run verify.py first")
            continue
        outs.append(run_config(args, units_by_id, parent_dir, arm, model_dir, args.sample))

    if args.verify and outs:
        subprocess.run([sys.executable, str(Path(__file__).with_name("verify.py")),
                        "--round", args.round, "--sample", str(args.sample)], check=True)


if __name__ == "__main__":
    main()
