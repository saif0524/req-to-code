"""
How much of the generated C++ is real implementation?

Each R0 function is classified by sample_functions.classify (heuristic, not yet validated by hand):
  empty               no body, or no statements
  output/trivial only only printing, constant returns, bare declarations
  placeholder-marked  placeholder / "simulate" / "in a real" wording in the code
  minimal             a few statements, no control flow
  logic               control flow or at least 3 non-trivial statements
"Stub" = empty + output/trivial only + placeholder-marked. Intervals are percentile bootstraps over
requirement units.

    python3 scripts/stub_analysis.py
"""
import csv
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sample_functions import classify  # noqa: E402
from reasoning_analysis import CHECK_STEP  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "results" / "stubs"
ORDER = ["empty", "output/trivial only", "placeholder-marked", "minimal", "logic"]
STUB = {"empty", "output/trivial only", "placeholder-marked"}


def load():
    rows = []
    for f in sorted((ROOT / "results" / "runs" / "R0").glob("*__*/s0/records.jsonl")):
        arm, model = f.parent.parent.name.split("__", 1)
        for l in f.read_text(encoding="utf-8").splitlines():
            if l.strip():
                r = json.loads(l)
                steps = r.get("reasoning") or []
                rows.append({"model": model, "arm": arm, "unit": r["unit_id"], "cls": classify(r["code"]),
                             "mentions": any(CHECK_STEP.search(s) for s in steps)})
    return rows


def boot_rate(rows, pred, rng, n=2000):
    units = sorted({r["unit"] for r in rows})
    ix = {u: i for i, u in enumerate(units)}
    num, den = np.zeros(len(units)), np.zeros(len(units))
    for r in rows:
        den[ix[r["unit"]]] += 1
        num[ix[r["unit"]]] += pred(r)
    est = num.sum() / den.sum()
    draws = rng.integers(0, len(units), (n, len(units)))
    b = np.array([num[d].sum() / max(den[d].sum(), 1) for d in draws])
    return est, *np.percentile(b, [2.5, 97.5])


def main():
    rows = [r for r in load() if r["model"] != "codegemma2b"]
    rng = np.random.default_rng(0)
    out = []
    for scope in ["all"] + sorted({r["model"] for r in rows}):
        for arm in ("general", "secure"):
            sub = [r for r in rows if r["arm"] == arm and (scope == "all" or r["model"] == scope)]
            c = Counter(r["cls"] for r in sub)
            row = {"scope": scope, "arm": arm, "functions": len(sub),
                   **{k: round(c[k] / len(sub), 3) for k in ORDER}}
            for name, pred in (("stub", lambda r: r["cls"] in STUB),
                               ("not_logic", lambda r: r["cls"] != "logic")):
                e, lo, hi = boot_rate(sub, pred, rng)
                row.update({name: round(e, 3), f"{name}_lo": round(lo, 3), f"{name}_hi": round(hi, 3)})
            out.append(row)
    OUT.mkdir(parents=True, exist_ok=True)
    with open(OUT / "stub_rates.csv", "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=list(out[0]))
        w.writeheader(); w.writerows(out)

    # functions whose rationale promises a check: what do they contain?
    ct = defaultdict(Counter)
    for r in rows:
        if r["mentions"]:
            ct[r["arm"]][r["cls"]] += 1
    with open(OUT / "promised_check_by_class.csv", "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f); w.writerow(["arm", "n"] + ORDER)
        for arm in ("general", "secure"):
            n = sum(ct[arm].values())
            w.writerow([arm, n] + [round(ct[arm][k] / n, 3) for k in ORDER])
    for r in out:
        print(f"{r['scope']:15}{r['arm']:9}{r['functions']:>5} stub {r['stub']:.3f} [{r['stub_lo']:.3f},{r['stub_hi']:.3f}]"
              f"  not-logic {r['not_logic']:.3f} [{r['not_logic_lo']:.3f},{r['not_logic_hi']:.3f}]")
    print(open(OUT / "promised_check_by_class.csv").read())


if __name__ == "__main__":
    main()
