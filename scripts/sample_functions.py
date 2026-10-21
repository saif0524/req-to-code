"""
Draw a stratified sample of generated functions that the heuristic classifies
as "logic" (control flow or 3+ non-I/O statements, no placeholder marker), for
manual labeling.

Strata are model x variant; CodeGemma is skipped because it produced no logic.
Output: results/sample_logic_<n>.csv with blank label columns.

    python scripts/sample_functions.py --n 100 --seed 7
"""
import argparse
import csv
import json
import random
import re
from collections import defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
GEN = ROOT / "results" / "generation"
MODELS = ("qwen25coder15b", "qwen25coder3b", "deepcoder15b", "opencoder15b")

IO = re.compile(r"\b(std::)?(cout|cerr|clog|printf|fprintf|puts|perror|putchar|endl)\b|\bLOG\w*\(|\blog\w*\(|\bprint\w*\(", re.I)
CTRL = re.compile(r"\b(if|for|while|switch|do|try|catch|throw)\b")
PLACEHOLDER = re.compile(
    r"placeholder|todo|fixme|logic here|code here|real[- ]world|actual (implementation|database|operation|logic)"
    r"|implementation (goes|would|will)|to be implemented|not implemented|simulat|dummy|stub|omitted|would (go|be)"
    r"|in a real|for demonstration|for simplicity|should be implemented|add .{0,30}here", re.I)


def body(code):
    i, j = code.find("{"), code.rfind("}")
    return code[i + 1 : j] if 0 <= i < j else ""


def strip(b):
    b = re.sub(r"//.*", "", b)
    b = re.sub(r"/\*.*?\*/", "", b, flags=re.S)
    return re.sub(r'"(\\.|[^"\\])*"', '""', b)


def is_work(s):
    if IO.search(s):
        return False
    if re.fullmatch(r'return(\s+(true|false|nullptr|NULL|\d+(\.\d+)?|""|\{\s*\}|[-+]?\d+))?', s):
        return False
    if re.fullmatch(r'(const\s+)?[\w:<>,\s\*&]+\s+\w+(\s*=\s*(""|\d+|true|false|nullptr|\{\s*\}))?', s) and "(" not in s:
        return False
    return True


def classify(code):
    b = body(code)
    if not b.strip():
        return "empty"
    stmts = [p.strip() for p in re.split(r";|\{|\}", strip(b)) if p.strip()]
    work = [s for s in stmts if is_work(s)]
    if not stmts:
        return "empty"
    if not work:
        return "output/trivial only"
    if PLACEHOLDER.search(code):
        return "placeholder-marked"
    if any(CTRL.search(s) for s in work) or len(work) >= 3:
        return "logic"
    return "minimal"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("--n", type=int, default=100)
    ap.add_argument("--seed", type=int, default=7)
    ap.add_argument("--out", default=None)
    args = ap.parse_args()

    doc_of = {}
    for l in open(ROOT / "data" / "requirements_units.jsonl", encoding="utf-8"):
        u = json.loads(l)
        doc_of[u["unit_id"]] = u["doc"]

    pools = defaultdict(list)
    for f in sorted(GEN.glob("*__*/records.jsonl")):
        variant, _, model = f.parent.name.partition("__")
        if model not in MODELS:
            continue
        for l in open(f, encoding="utf-8"):
            r = json.loads(l)
            if classify(r["code"]) == "logic":
                pools[(model, variant)].append(r)

    rng = random.Random(args.seed)
    strata = sorted(pools)
    base, extra = divmod(args.n, len(strata))
    quota = {s: base for s in strata}
    for s in rng.sample(strata, extra):
        quota[s] += 1

    rows = []
    for s in strata:
        model, variant = s
        for r in rng.sample(pools[s], min(quota[s], len(pools[s]))):
            rows.append({
                "model": model, "variant": variant, "doc": doc_of.get(r["unit_id"], "?"),
                "unit_id": r["unit_id"], "func_index": r["func_index"], "name": r["name"],
                "signature": r["signature"], "purpose": r["purpose"],
                "reasoning": " | ".join(r["reasoning"]), "code": r["code"],
                # to be filled by hand
                "label_implements_purpose": "",  # yes / partial / no
                "label_calls_undefined_helper": "",  # yes / no
                "label_defensive_checks": "",  # none / some / extensive
                "notes": "",
            })
    rng.shuffle(rows)
    for i, row in enumerate(rows, 1):
        row["id"] = i
    rows = [{"id": r["id"], **{k: v for k, v in r.items() if k != "id"}} for r in rows]

    out = Path(args.out) if args.out else ROOT / "results" / f"sample_logic_{args.n}.csv"
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)

    print(f"[INFO] {len(rows)} functions -> {out}")
    print(f"[INFO] pool sizes: " + ", ".join(f"{m}/{v}={len(p)}" for (m, v), p in sorted(pools.items())))
    print("[INFO] per stratum: " + ", ".join(f"{m}/{v}={sum(1 for r in rows if r['model']==m and r['variant']==v)}" for m, v in strata))


if __name__ == "__main__":
    main()
