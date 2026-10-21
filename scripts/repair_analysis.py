"""
Compile-repair rounds R0 -> C1 -> C2 for the paper's models.

Per round and prompt, pooled over models, with 95% percentile bootstrap intervals over
requirement sections (all models of a section move together):
  compiles   share of (model, section) cases whose assembled file compiles
  usable     compiles and every planned function has a non-stub body (verify.py)
  stub       share of planned functions that are stubs or missing (a repair that returns no
             body drops the function from the output, so missing counts as stub)
  logic      share of planned functions with recognisable logic
Also the secure-minus-general difference in usable per round.

    python3 scripts/repair_analysis.py
"""
import csv
import json
import sys
from collections import Counter, defaultdict
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sample_functions import classify  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs"
OUT = ROOT / "results" / "repair"
MODELS = ["qwen25coder15b", "qwen25coder3b", "opencoder15b"]
ROUNDS = ["R0", "C1", "C2"]
STUB = {"empty", "output/trivial only", "placeholder-marked"}


def load(rnd, arm, model):
    d = RUNS / rnd / f"{arm}__{model}" / "s0"
    ver = {r["unit_id"]: r for r in csv.DictReader(open(d / "verify_units.csv", encoding="utf-8"))}
    plan = {}
    for l in (d / "units.jsonl").read_text(encoding="utf-8").splitlines():
        if l.strip():
            u = json.loads(l)
            plan[u["unit_id"]] = len(u.get("plan") or [])
    cls = defaultdict(Counter)
    for l in (d / "records.jsonl").read_text(encoding="utf-8").splitlines():
        if l.strip():
            r = json.loads(l)
            cls[r["unit_id"]][classify(r["code"])] += 1
    rows = {}
    for u, v in ver.items():
        c = cls[u]
        written = sum(c.values())
        rows[u] = {"compiles": int(v["compiles"] or 0), "usable": int(v["usable"] or 0),
                   "planned": plan.get(u, 0),
                   "stub": sum(c[k] for k in STUB) + max(plan.get(u, 0) - written, 0),
                   "logic": c["logic"]}
    return rows


def main(boot=2000):
    data = {(r, a, m): load(r, a, m) for r in ROUNDS for a in ("general", "secure") for m in MODELS}
    units = sorted(data[("R0", "general", MODELS[0])])
    ix = {u: i for i, u in enumerate(units)}
    rng = np.random.default_rng(0)
    draws = rng.integers(0, len(units), (boot, len(units)))
    w = np.array([np.bincount(d, minlength=len(units)) for d in draws])

    def per_unit(rnd, arm, key):
        v = np.zeros(len(units))
        for m in MODELS:
            for u, row in data[(rnd, arm, m)].items():
                v[ix[u]] += row[key]
        return v

    rows = []
    for rnd in ROUNDS:
        usable = {}
        for arm in ("general", "secure"):
            n_cases = np.full(len(units), len(MODELS))
            for key, den in (("compiles", n_cases), ("usable", n_cases),
                             ("stub", per_unit(rnd, arm, "planned")), ("logic", per_unit(rnd, arm, "planned"))):
                num = per_unit(rnd, arm, key)
                est = num.sum() / den.sum()
                b = (w @ num) / np.maximum(w @ den, 1e-9)
                lo, hi = np.percentile(b, [2.5, 97.5])
                rows.append({"round": rnd, "arm": arm, "metric": key, "value": round(est, 4),
                             "ci_lo": round(lo, 4), "ci_hi": round(hi, 4)})
                if key == "usable":
                    usable[arm] = (num, est, b)
        d = usable["secure"][2] - usable["general"][2]
        lo, hi = np.percentile(d, [2.5, 97.5])
        rows.append({"round": rnd, "arm": "secure-general", "metric": "usable",
                     "value": round(usable["secure"][1] - usable["general"][1], 4),
                     "ci_lo": round(lo, 4), "ci_hi": round(hi, 4)})
    OUT.mkdir(parents=True, exist_ok=True)
    with open(OUT / "repair_rounds.csv", "w", newline="", encoding="utf-8") as fh:
        wr = csv.DictWriter(fh, fieldnames=list(rows[0]))
        wr.writeheader()
        wr.writerows(rows)
    for r in rows:
        print(f"{r['round']:3} {r['arm']:15} {r['metric']:9} {r['value']:.3f} [{r['ci_lo']:.3f}, {r['ci_hi']:.3f}]")


if __name__ == "__main__":
    main()
