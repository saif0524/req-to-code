"""
Analyze every stored run (compile check, cppcheck, ESBMC when installed) and write the
results next to the run's code.

Layout read:   results/runs/<round>/<arm>__<model>/s<i>/{units.jsonl,records.jsonl,code/,manifest.json}
Files written into each s<i>/ directory:
  verify_units.csv       one row per planned unit (units without code are included, so
                         denominators for compile@k and secure@k stay complete)
  verify_functions.csv   one row per function
  verify_meta.json       tool versions, flags, code hashes checked against the manifest

Per unit:
  compiles   g++ -std=c++17 -fsyntax-only succeeds
  usable     compiles, and every planned function has a body
  findings   cppcheck findings for the whole file (parse failures are flagged separately)
  secure     usable and findings == 0

cppcheck runs on every unit with code. ESBMC runs per function on usable units only; with
no binary on PATH the column holds `not_installed`, so rerunning with --force after
installing it fills the column for every stored round.

    python3 scripts/verify.py                       # all runs not yet analyzed
    python3 scripts/verify.py --round R0 --model qwen25coder3b --arm secure
    python3 scripts/verify.py --force --limit 20    # recompute, first 20 units per run
"""
import argparse
import csv
import hashlib
import json
import re
import shutil
import subprocess
import tempfile
import xml.etree.ElementTree as ET
from collections import Counter, defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs"

IGNORED_IDS = {"missingInclude", "missingIncludeSystem", "checkersReport",
               "normalCheckLevelMaxBranches", "toomanyconfigs", "unmatchedSuppression"}
PARSE_IDS = {"syntaxError", "internalAstError", "cppcheckError"}

CPPCHECK_FLAGS = ["--enable=warning,portability", "--inconclusive", "--xml",
                  "--library=std", "--suppress=missingIncludeSystem",
                  "--suppress=missingInclude", "--inline-suppr"]
# ESBMC 8 checks array bounds and pointers by default (only --no-bounds-check and
# --no-pointer-check exist), so the flags below add the two checks that are off by default.
ESBMC_FLAGS = ["--memory-leak-check", "--overflow-check", "--unwind", "8",
               "--no-unwinding-assertions", "--timeout", "30s"]

# Crude lexicon for security-oriented reasoning steps. A proxy, not a classifier.
SEC_TERMS = re.compile(
    r"\b(validat\w*|sanitiz\w*|bounds?|overflow\w*|underflow\w*|null\w*|nullptr|"
    r"buffer\w*|out[- ]of[- ]range|injection|untrusted|malicious|secure\w*|"
    r"safe\w*|check(?:s|ing|ed)? (?:for|that|if|whether)|error handling|"
    r"exception\w*|memory leak\w*|leak\w*|invalid input|edge case\w*|"
    r"permission\w*|authenticat\w*|authoriz\w*|encrypt\w*|escap\w*)\b", re.I)


def compile_check(path):
    """Return (ok, n_errors, first_error)."""
    try:
        r = subprocess.run(["g++", "-std=c++17", "-fsyntax-only", "-x", "c++", str(path)],
                           capture_output=True, text=True, timeout=120)
    except subprocess.TimeoutExpired:
        return False, 0, "timeout"
    errs = [l for l in r.stderr.splitlines() if ": error:" in l]
    first = re.sub(r"^.*?: error: ", "", errs[0])[:160] if errs else ""
    return r.returncode == 0, len(errs), first


def run_cppcheck(path):
    """Return (list of (id, severity, line), parse_error)."""
    try:
        r = subprocess.run(["cppcheck", *CPPCHECK_FLAGS, str(path)],
                           capture_output=True, text=True, timeout=300)
    except subprocess.TimeoutExpired:
        return [], True
    try:
        root = ET.fromstring(r.stderr)
    except ET.ParseError:
        return [], True
    found, parse_error = [], False
    for e in root.iter("error"):
        eid = e.get("id", "")
        if eid in IGNORED_IDS:
            continue
        if eid in PARSE_IDS:
            parse_error = True
            continue
        loc = e.find("location")
        line = int(loc.get("line", 0)) if loc is not None else 0
        found.append((eid, e.get("severity", ""), line))
    return found, parse_error


def run_esbmc(path, func):
    # ESBMC's C++ frontend cannot parse <optional> next to its own header models, so the
    # check runs on a copy without that include. Code that really uses std::optional then
    # fails to parse and is recorded as unsupported.
    src = re.sub(r"^\s*#include\s*<optional>\s*$", "", Path(path).read_text(encoding="utf-8"), flags=re.M)
    try:
        with tempfile.TemporaryDirectory() as tmp:
            tmp_path = Path(tmp) / Path(path).name
            tmp_path.write_text(src, encoding="utf-8")
            r = subprocess.run(["esbmc", str(tmp_path), "--function", func, *ESBMC_FLAGS],
                               capture_output=True, text=True, timeout=90)
    except subprocess.TimeoutExpired:
        return "timeout"
    out = r.stdout + r.stderr
    if "VERIFICATION SUCCESSFUL" in out:
        return "ok"
    if "VERIFICATION FAILED" in out:
        m = re.search(r"Violated property:\s*\n\s*file[^\n]*\n\s*([^\n]+)", out)
        prop = re.sub(r"\s+", "_", m.group(1).strip())[:60] if m else "unknown"
        return f"fail:{prop}"
    if "Timed out" in out or "timeout" in out.lower():
        return "timeout"
    return "unsupported"


STUB_PHRASES = re.compile(r"your implementation|todo|not implemented|implement(?:ation)? here|"
                         r"placeholder|fill in", re.I)


def is_stub(code):
    """A definition with no statements, or only a placeholder comment."""
    if "{" not in (code or ""):
        return False
    body = code[code.index("{") + 1: code.rindex("}")] if "}" in code else code[code.index("{") + 1:]
    stripped = re.sub(r"//.*?$|/\*.*?\*/", "", body, flags=re.S | re.M)
    return ";" not in stripped or bool(STUB_PHRASES.search(body) and stripped.count(";") <= 1)


def code_has_body(code):
    return "{" in (code or "") and not is_stub(code)


def has_body(rec):
    return code_has_body(rec.get("code"))


def analyze_unit(job):
    run, unit, recs, use_esbmc = job
    unit_id = unit["unit_id"]
    cpp = run["dir"] / "code" / f"{unit_id}.cpp"
    key = {"round": run["round"], "arm": run["arm"], "model": run["model"],
           "sample": run["sample"], "unit_id": unit_id}
    # n_functions counts functions that were written; the plan is what was intended.
    n_planned = len(unit.get("plan") or []) or unit.get("n_functions") or 0
    bodies = sum(1 for r in recs if has_body(r))
    has_code = cpp.exists()

    ok, n_err, first_err, finds, parse_err, loc = False, 0, "", [], False, 0
    if has_code:
        ok, n_err, first_err = compile_check(cpp)
        finds, parse_err = run_cppcheck(cpp)
        loc = len(cpp.read_text(encoding="utf-8").splitlines())
    usable = ok and n_planned > 0 and bodies == n_planned and len(recs) == n_planned

    func_rows, mapped = [], 0
    for rec in recs:
        lo, hi = rec["start_line"], rec["end_line"]
        mine = [f for f in finds if lo <= f[2] <= hi]
        mapped += len(mine)
        steps = rec.get("reasoning") or []
        text = " ".join(steps)
        if not use_esbmc:
            verdict = "not_installed"
        elif not usable:
            verdict = "skipped_not_usable"
        else:
            verdict = run_esbmc(cpp, rec["name"])
        func_rows.append({
            **key, "func": rec["name"], "compiles": int(ok), "has_body": int(has_body(rec)),
            "loc": hi - lo + 1, "reasoning_steps": len(steps),
            "reasoning_words": len(text.split()), "sec_terms": len(SEC_TERMS.findall(text)),
            "cppcheck_findings": len(mine),
            "cppcheck_classes": json.dumps(dict(Counter(f[0] for f in mine)), sort_keys=True),
            "esbmc": verdict,
        })
    unit_row = {
        **key, "status": unit.get("status", ""), "has_code": int(has_code),
        "n_planned": n_planned, "n_records": len(recs), "n_bodies": bodies,
        "compiles": int(ok), "n_compile_errors": n_err, "first_error": first_err,
        "usable": int(usable), "loc": loc,
        "cppcheck_findings": len(finds), "cppcheck_unmapped": len(finds) - mapped,
        "cppcheck_parse_error": int(parse_err),
        "cppcheck_classes": json.dumps(dict(Counter(f[0] for f in finds)), sort_keys=True),
        "secure": int(usable and not finds and not parse_err),
    }
    return unit_row, func_rows


def find_runs(args):
    runs = []
    for rd in sorted(args.runs_root.iterdir()) if args.runs_root.exists() else []:
        if args.round and rd.name != args.round:
            continue
        for cfg in sorted(p for p in rd.iterdir() if p.is_dir() and "__" in p.name):
            arm, model = cfg.name.split("__", 1)
            if args.arm and arm != args.arm:
                continue
            if args.model and model != args.model:
                continue
            for sd in sorted(p for p in cfg.iterdir() if re.fullmatch(r"s\d+", p.name)):
                if args.sample is not None and sd.name != f"s{args.sample}":
                    continue
                if (sd / "units.jsonl").exists():
                    runs.append({"dir": sd, "round": rd.name, "arm": arm,
                                 "model": model, "sample": int(sd.name[1:])})
    return runs


def read_jsonl(path):
    if not path.exists():
        return []
    return [json.loads(l) for l in path.read_text(encoding="utf-8").splitlines() if l.strip()]


def write_csv(path, rows):
    with open(path, "w", newline="", encoding="utf-8") as f:
        if rows:
            w = csv.DictWriter(f, fieldnames=list(rows[0]))
            w.writeheader()
            w.writerows(rows)


def tool_version(cmd):
    try:
        out = subprocess.run(cmd, capture_output=True, text=True, timeout=20).stdout
        return out.strip().splitlines()[0]
    except Exception:
        return None


def process_run(run, args, use_esbmc, pool):
    d = run["dir"]
    if (d / "verify_units.csv").exists() and not args.force:
        return None
    units = read_jsonl(d / "units.jsonl")
    if args.limit:
        units = units[: args.limit]
    by_unit = defaultdict(list)
    for rec in read_jsonl(d / "records.jsonl"):
        by_unit[rec["unit_id"]].append(rec)

    # The manifest records a hash per code file; a mismatch means the run was edited.
    manifest = json.loads((d / "manifest.json").read_text()) if (d / "manifest.json").exists() else {}
    expected = manifest.get("code_sha256", {})
    changed = [u for u, h in expected.items()
               if (d / "code" / f"{u}.cpp").exists()
               and hashlib.sha256((d / "code" / f"{u}.cpp").read_bytes()).hexdigest() != h]

    jobs = [(run, u, by_unit.get(u["unit_id"], []), use_esbmc) for u in units]
    results = list(pool.map(analyze_unit, jobs))
    unit_rows = [r[0] for r in results]
    func_rows = [f for r in results for f in r[1]]
    write_csv(d / "verify_units.csv", unit_rows)
    write_csv(d / "verify_functions.csv", func_rows)
    (d / "verify_meta.json").write_text(json.dumps({
        "cppcheck": tool_version(["cppcheck", "--version"]),
        "gxx": tool_version(["g++", "--version"]),
        "esbmc": tool_version(["esbmc", "--version"]) if use_esbmc else "not_installed",
        "cppcheck_flags": CPPCHECK_FLAGS, "esbmc_flags": ESBMC_FLAGS,
        "units_analyzed": len(unit_rows), "limit": args.limit,
        "code_changed_since_manifest": changed,
    }, indent=2), encoding="utf-8")
    n = len(unit_rows)
    print(f"{run['round']}/{run['arm']}__{run['model']}/s{run['sample']}: {n} units, "
          f"compiles={sum(r['compiles'] for r in unit_rows)} usable={sum(r['usable'] for r in unit_rows)} "
          f"secure={sum(r['secure'] for r in unit_rows)}"
          + (f"  WARNING {len(changed)} files differ from manifest" if changed else ""))
    return unit_rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--round")
    ap.add_argument("--arm", choices=["general", "secure"])
    ap.add_argument("--model")
    ap.add_argument("--sample", type=int)
    ap.add_argument("--limit", type=int, help="first N units of each run, for smoke tests")
    ap.add_argument("--force", action="store_true", help="recompute runs that already have results")
    ap.add_argument("--no-esbmc", action="store_true")
    ap.add_argument("--jobs", type=int, default=8)
    ap.add_argument("--runs-root", type=Path, default=RUNS)
    args = ap.parse_args()

    use_esbmc = not args.no_esbmc and shutil.which("esbmc") is not None
    if not use_esbmc:
        print("esbmc not used: recording esbmc=not_installed")
    runs = find_runs(args)
    print(f"{len(runs)} runs")
    with ThreadPoolExecutor(max_workers=args.jobs) as pool:
        for run in runs:
            process_run(run, args, use_esbmc, pool)


if __name__ == "__main__":
    main()
