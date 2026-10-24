"""
Blind sample of R0 functions for hand-labelling the RQ3 stub classes.

Stratified by heuristic class (sample_functions.classify): N per class, drawn across the four
analysed models and both prompts. The sheet shows only the requirement, the planned purpose and
the code; model, prompt and the automatic class go to a separate key file.

    python3 scripts/label_functions.py --per-class 20
    python3 scripts/label_functions.py --agreement results/labels/function_sheet_filled.csv
"""
import argparse
import csv
import json
import random
import sys
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sample_functions import classify  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
OUT = ROOT / "results" / "labels"
ORDER = ["empty", "output/trivial only", "placeholder-marked", "minimal", "logic"]
STUB = {"empty", "output/trivial only", "placeholder-marked"}


def sheet(per_class, seed):
    units = {}
    for l in (ROOT / "data" / "requirements_units.jsonl").read_text(encoding="utf-8").splitlines():
        if l.strip():
            u = json.loads(l)
            units[u["unit_id"]] = u
    pool = defaultdict(list)
    for f in sorted((ROOT / "results" / "runs" / "R0").glob("*__*/s0/records.jsonl")):
        arm, model = f.parent.parent.name.split("__", 1)
        for l in f.read_text(encoding="utf-8").splitlines():
            if l.strip():
                r = json.loads(l)
                pool[classify(r["code"])].append((arm, model, r))
    rng = random.Random(seed)
    chosen = []
    for cls in ORDER:
        for arm, model, r in rng.sample(pool[cls], min(per_class, len(pool[cls]))):
            chosen.append((cls, arm, model, r))
    rng.shuffle(chosen)
    rows, key = [], []
    for i, (cls, arm, model, r) in enumerate(chosen, 1):
        u = units.get(r["unit_id"], {})
        rows.append({"id": i, "requirement": u.get("text", "")[:1500], "signature": r["signature"],
                     "purpose": r["purpose"], "code": r["code"],
                     "is_stub": "", "implements_purpose": "", "notes": ""})
        key.append({"id": i, "arm": arm, "model": model, "unit_id": r["unit_id"], "func": r["name"],
                    "auto_class": cls, "auto_stub": int(cls in STUB)})
    OUT.mkdir(parents=True, exist_ok=True)
    for name, data in (("function_sheet.csv", rows), ("function_key.csv", key)):
        with open(OUT / name, "w", newline="", encoding="utf-8") as fh:
            w = csv.DictWriter(fh, fieldnames=list(data[0]))
            w.writeheader()
            w.writerows(data)
    print(f"wrote {OUT / 'function_sheet.csv'} ({len(rows)} functions, {per_class} per class, blind)")
    print("Fill is_stub (1 = no real implementation of the purpose: empty, output-only, placeholder or")
    print("constant return; 0 = otherwise) and implements_purpose (yes / partial / no).")


def agreement(path):
    key = {r["id"]: r for r in csv.DictReader(open(OUT / "function_key.csv", encoding="utf-8"))}
    lab = [r for r in csv.DictReader(open(path, encoding="utf-8")) if r["is_stub"].strip() in ("0", "1")]
    tp = fp = fn = tn = 0
    by_cls = defaultdict(Counter)
    for r in lab:
        h, k = int(r["is_stub"]), key[r["id"]]
        a = int(k["auto_stub"])
        tp += h and a; fp += (not h) and a; fn += h and (not a); tn += (not h) and (not a)
        by_cls[k["auto_class"]][r["implements_purpose"].strip().lower() or "?"] += 1
        by_cls[k["auto_class"]]["human_stub"] += h
    n = tp + fp + fn + tn
    po = (tp + tn) / n
    pe = ((tp + fp) * (tp + fn) + (fn + tn) * (fp + tn)) / n ** 2
    print(f"n={n} precision={tp / max(tp + fp, 1):.3f} recall={tp / max(tp + fn, 1):.3f} "
          f"kappa={(po - pe) / (1 - pe):.3f}")
    for cls in ORDER:
        print(f"  {cls:20} {dict(by_cls[cls])}")


if __name__ == "__main__":
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--per-class", type=int, default=20)
    ap.add_argument("--seed", type=int, default=7)
    ap.add_argument("--agreement", type=Path)
    a = ap.parse_args()
    agreement(a.agreement) if a.agreement else sheet(a.per_class, a.seed)
