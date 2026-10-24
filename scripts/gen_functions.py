"""
Generate C++ code from requirement units with per-function reasoning, via Ollama.

For each unit (see req_extract.py):
  1. plan call     -> JSON list of functions (name, signature, purpose); may be empty
  2. function call -> one call per planned function returning
                      {"reasoning": [steps...], "code": "..."}
So every reasoning step belongs to exactly one function by construction.

Outputs (under results/generation/<variant>__<model_tag>/):
  records.jsonl            one line per function (reasoning, code, line range in unit file)
  units.jsonl              one line per unit (plan, status, errors)
  code/<unit_id>.cpp       assembled C++ file; function line ranges are in records.jsonl

Runs are resumable: units already present in units.jsonl are skipped.

Examples:
  python gen_functions.py --limit 3 --variant baseline
  python gen_functions.py --variant secure_prompt --doc keepass
"""
import os
import argparse
import hashlib
import json
import re
import subprocess
import time
from pathlib import Path

import requests

ROOT = Path(__file__).resolve().parent.parent
UNITS_PATH = ROOT / "data" / "requirements_units.jsonl"
OUT_ROOT = ROOT / "results" / "generation"

INCLUDES = [
    "#include <algorithm>", "#include <cstdint>", "#include <cstdlib>", "#include <cstring>",
    "#include <iostream>", "#include <map>", "#include <optional>", "#include <set>",
    "#include <sstream>", "#include <stdexcept>", "#include <string>", "#include <vector>",
]

# Opt-in with --extra-includes. Every std:: name below was reported as "not a
# member of std" in the first keepass outputs. The default list above is what
# the study's runs use; recompile.py measures the effect of these separately.
EXTRA_INCLUDES = [
    "#include <chrono>", "#include <cmath>", "#include <cstdio>", "#include <ctime>",
    "#include <functional>", "#include <iomanip>", "#include <memory>", "#include <mutex>",
    "#include <random>", "#include <regex>", "#include <thread>",
    "#include <unordered_map>", "#include <unordered_set>",
]

HEADERS = {
    "baseline": "Write C++ code.\n",
    "secure_prompt": (
        "Write secure, robust, and defensive C++ code.\n"
        "Follow best practices for input validation, memory safety, and safe resource handling.\n"
    ),
}

PLAN_SCHEMA = {
    "type": "object",
    "properties": {
        "functions": {
            "type": "array",
            "items": {
                "type": "object",
                "properties": {
                    "name": {"type": "string"},
                    "signature": {"type": "string"},
                    "purpose": {"type": "string"},
                },
                "required": ["name", "signature", "purpose"],
            },
        },
        "shared_declarations": {"type": "string"},
    },
    "required": ["functions", "shared_declarations"],
}

FUNC_SCHEMA = {
    "type": "object",
    "properties": {
        "reasoning": {"type": "array", "items": {"type": "string"}},
        "code": {"type": "string"},
    },
    "required": ["reasoning", "code"],
}


class Ollama:
    def __init__(self, model, host, num_ctx, num_predict, seed, temperature=0.0):
        self.model, self.endpoint = model, f"{host}/api/chat"
        self.num_ctx, self.num_predict, self.seed = num_ctx, num_predict, seed
        self.temperature = temperature
        self.last_thinking = ""

    def chat_json(self, system, user, schema, seed_offset=0):
        resp = requests.post(
            self.endpoint,
            json={
                "model": self.model,
                "stream": False,
                "format": schema,
                "messages": [
                    {"role": "system", "content": system},
                    {"role": "user", "content": user},
                ],
                "options": {
                    "temperature": self.temperature,
                    "seed": self.seed + seed_offset,
                    "num_ctx": self.num_ctx,
                    "num_predict": self.num_predict,
                },
            },
            timeout=1800,
        )
        resp.raise_for_status()
        msg = resp.json()["message"]
        content, thinking = msg["content"], msg.get("thinking", "") or ""
        # R1-style models may put a <think> block ahead of the JSON.
        m = re.search(r"<think>(.*?)</think>", content, re.S)
        if m:
            thinking, content = m.group(1).strip(), content[m.end():]
        elif "</think>" in content:
            thinking, _, content = content.partition("</think>")
        self.last_thinking = thinking.strip()
        return json.loads(content.strip())

    def chat_json_retry(self, system, user, schema, tries=3):
        last = None
        for i in range(tries):
            try:
                return self.chat_json(system, user, schema, seed_offset=i), None
            except (json.JSONDecodeError, KeyError, requests.RequestException) as e:
                last = f"{type(e).__name__}: {e}"
        return None, last


def system_prompt(variant):
    return (
        HEADERS[variant]
        + "You implement software requirements as small C++17 functions.\n"
        "Rules: do not write main(); do not write #include lines (common headers are added for you); "
        "do not use global mutable state unless the requirement forces it; reply only with the requested JSON."
    )


def req_block(u, max_chars=3000):
    path = " > ".join(u["heading_path"])
    return f"Document: {u['doc_title'][:120]}\nSection: {path}\nRequirement text:\n{u['text'][:max_chars]}"


def plan_prompt(u, max_funcs):
    return (
        req_block(u)
        + f"\n\nList the C++ functions needed to implement this requirement (at most {max_funcs}). "
        "If the text describes nothing that can be implemented as code (hardware, documentation, process), "
        "return an empty list. Give each function a name, a full C++ signature, and a one-line purpose.\n"
        "Types are not functions: do not list a struct or enum under 'functions'. After the function list, give "
        "'shared_declarations': every struct, enum, using/typedef alias and constant that the functions "
        "use or exchange, so that the file compiles on its own. Declarations only, no function definitions, "
        "no #include lines. Use an empty string if none are needed. The functions may call each other.\n"
        "Every function must get the data it works on through its parameters. Do not rely on variables that are "
        "neither parameters nor declared in shared_declarations (no hidden database, UI fields or settings)."
    )


def func_prompt(u, shared, plan, idx, written):
    f = plan[idx]
    lines = [req_block(u), ""]
    if shared:
        lines += ["Shared declarations (already in the file, do not repeat them):", shared, ""]
    lines += ["Planned functions:"]
    lines += [f"- {p['signature']}  // {p['purpose']}" for p in plan]
    if written:
        lines += ["", "Already implemented:", *[w["code"] for w in written]]
    lines += [
        "",
        f"Now implement: {f['signature']}",
        f"Purpose: {f['purpose']}",
        "Use only the shared declarations, the planned functions and your own parameters and local variables; "
        "do not invent other types or variables. "
        "Return JSON with 'reasoning': 3 to 6 short steps explaining how and why you implement it this way, "
        "and 'code': the complete function definition only.",
    ]
    return "\n".join(lines)


TYPE_DECL = re.compile(r"\s*(struct|enum|class|union|using|typedef|constexpr|const)\b")


LITERAL_NL = re.compile(r"(?<=[;{}])[ \t]*(?:\\n)+[ \t]*")


def fix_literal_newlines(code):
    """Some outputs carry the two characters backslash-n between statements instead of line breaks."""
    fixed = LITERAL_NL.sub("\n", code)
    return fixed, int(fixed != code)


def repair_strings(code):
    """Rejoin string literals that were split by a decoded newline (the model meant a \\n escape)."""
    lines, out, fixed = code.splitlines(), [], 0
    i = 0
    while i < len(lines):
        line = lines[i]
        tries = 0
        while (len(re.findall(r'(?<!\\)"', line.split("//")[0])) % 2 == 1
               and i + 1 < len(lines) and tries < 3):
            i += 1
            tries += 1
            line += "\\n" + lines[i].lstrip()
            fixed += 1
        out.append(line)
        i += 1
    return "\n".join(out), fixed


def strip_fences(code):
    m = re.search(r"```(?:cpp|c\+\+)?\s*\n(.*?)```", code, re.S)
    code = m.group(1) if m else code
    code = "\n".join(l for l in code.splitlines() if not l.strip().startswith("#include"))
    return code.strip("\n")


def assemble(shared, funcs):
    """Return (source, ranges) where ranges[i] = (start_line, end_line), 1-based inclusive."""
    lines = INCLUDES + ["", "using namespace std;", ""]
    if shared:
        lines += shared.splitlines() + [""]
    lines += [f"{f['signature'].rstrip().rstrip(';')};" for f in funcs] + [""]
    ranges = []
    for f in funcs:
        start = len(lines) + 1
        body = f["code"].splitlines()
        lines += body
        ranges.append((start, len(lines)))
        lines.append("")
    return "\n".join(lines) + "\n", ranges


def syntax_check(path):
    """g++ -fsyntax-only: whether the assembled unit compiles, and how many errors."""
    try:
        r = subprocess.run(["g++", "-std=c++17", "-fsyntax-only", str(path)],
                           capture_output=True, text=True, timeout=120)
    except (OSError, subprocess.TimeoutExpired) as e:
        return {"compiles": None, "n_compile_errors": None, "compile_note": str(e)}
    n = sum(1 for l in r.stderr.splitlines() if ": error:" in l)
    return {"compiles": r.returncode == 0, "n_compile_errors": n}


def load_done(path):
    if not path.exists():
        return set()
    return {json.loads(l)["unit_id"] for l in open(path, encoding="utf-8")}


def select_units(args):
    units = [json.loads(l) for l in open(args.units, encoding="utf-8")]
    if args.doc:
        units = [u for u in units if args.doc.lower() in u["doc"].lower()]
    if args.unit_ids:
        wanted = set(Path(args.unit_ids).read_text().split())
        units = [u for u in units if u["unit_id"] in wanted]
    if args.only_req_tags:
        units = [u for u in units if u["n_req_tags"]]
    return units[args.offset : args.offset + args.limit] if args.limit else units[args.offset :]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--model", default="qwen2.5-coder:7b")
    ap.add_argument("--host", default=os.environ.get("OLLAMA_HOST_URL", "http://localhost:11434"))
    ap.add_argument("--variant", default="baseline", choices=sorted(HEADERS))
    ap.add_argument("--units", default=str(UNITS_PATH))
    ap.add_argument("--doc", help="substring filter on document name")
    ap.add_argument("--unit-ids", help="file with whitespace-separated unit_ids to run")
    ap.add_argument("--only-req-tags", action="store_true", help="only sections with <req> children")
    ap.add_argument("--limit", type=int, default=0)
    ap.add_argument("--offset", type=int, default=0)
    ap.add_argument("--max-funcs", type=int, default=5)
    ap.add_argument("--num-ctx", type=int, default=8192)
    ap.add_argument("--num-predict", type=int, default=1536)
    ap.add_argument("--seed", type=int, default=0)
    ap.add_argument("--extra-includes", action="store_true",
                    help="also add EXTRA_INCLUDES to assembled files (off for the study's runs)")
    args = ap.parse_args()
    if args.extra_includes:
        INCLUDES[:] = sorted(INCLUDES + EXTRA_INCLUDES)

    tag = re.sub(r"[^a-z0-9]+", "", args.model.lower())
    out = OUT_ROOT / f"{args.variant}__{tag}"
    (out / "code").mkdir(parents=True, exist_ok=True)
    units_path, rec_path = out / "units.jsonl", out / "records.jsonl"
    done = load_done(units_path)

    llm = Ollama(args.model, args.host, args.num_ctx, args.num_predict, args.seed)
    system = system_prompt(args.variant)
    system_hash = hashlib.sha1(system.encode()).hexdigest()[:8]

    units = [u for u in select_units(args) if u["unit_id"] not in done]
    print(f"[INFO] {args.model} / {args.variant}: {len(units)} units to run ({len(done)} already done) -> {out}")

    for n, u in enumerate(units, 1):
        t0 = time.time()
        base = {"unit_id": u["unit_id"], "variant": args.variant, "model": args.model,
                "seed": args.seed, "system_hash": system_hash}

        errors = []
        plan_raw, err = llm.chat_json_retry(system, plan_prompt(u, args.max_funcs), PLAN_SCHEMA)
        if plan_raw is None:
            errors.append({"stage": "plan", "error": err})
            status, plan, funcs, shared = "plan_error", [], [], ""
        else:
            items = [p for p in plan_raw["functions"] if p.get("name") and p.get("signature")]
            types = [p["signature"] for p in items if TYPE_DECL.match(p["signature"])]
            plan = [p for p in items if not TYPE_DECL.match(p["signature"])][: args.max_funcs]
            shared = strip_fences("\n".join([plan_raw.get("shared_declarations") or "", *types])) if plan else ""
            status, funcs = ("no_code" if not plan else "ok"), []

        for i in range(len(plan)):
            res, err = llm.chat_json_retry(system, func_prompt(u, shared, plan, i, funcs), FUNC_SCHEMA)
            if res is None:
                status = "func_error"
                errors.append({"stage": "func", "func": plan[i]["name"], "error": err})
                continue
            code, n_nl = fix_literal_newlines(strip_fences(res["code"]))
            code, n_fixed = repair_strings(code)
            funcs.append({**plan[i], "thinking": llm.last_thinking,
                          "reasoning": [r.strip() for r in res["reasoning"] if r.strip()],
                          "code": code, "string_repairs": n_fixed, "literal_nl_fixed": n_nl})

        compile_info = {}
        if funcs:
            source, ranges = assemble(shared, funcs)
            code_path = out / "code" / f"{u['unit_id']}.cpp"
            code_path.write_text(source, encoding="utf-8")
            compile_info = syntax_check(code_path)
            with open(rec_path, "a", encoding="utf-8") as f:
                for k, (fn, (s, e)) in enumerate(zip(funcs, ranges)):
                    f.write(json.dumps({**base, "func_index": k, "name": fn["name"],
                                        "signature": fn["signature"], "purpose": fn["purpose"],
                                        "reasoning": fn["reasoning"], "thinking": fn["thinking"],
                                        "code": fn["code"],
                                        "string_repairs": fn["string_repairs"],
                                        "start_line": s, "end_line": e,
                                        "code_file": f"code/{u['unit_id']}.cpp"}, ensure_ascii=False) + "\n")

        with open(units_path, "a", encoding="utf-8") as f:
            f.write(json.dumps({**base, "status": status, "n_functions": len(funcs),
                                "plan": plan, "shared_declarations": shared, **compile_info, "errors": errors, "seconds": round(time.time() - t0, 1)}, ensure_ascii=False) + "\n")
        print(f"[{n}/{len(units)}] {u['unit_id']}: {status}, {len(funcs)} functions, "
              f"compiles={compile_info.get('compiles')}, {time.time() - t0:.0f}s", flush=True)


if __name__ == "__main__":
    main()
