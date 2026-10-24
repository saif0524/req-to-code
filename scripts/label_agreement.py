"""
Agreement for the two-annotator labelling of the blind sheets in results/labels/.

  inter-annotator   Cohen's kappa and percent agreement per column between two filled sheets;
                    writes the items they disagree on (ids and both labels, no model or prompt)
                    to results/labels/disagreements_<kind>.csv for adjudication.
  heuristic check   precision, recall and kappa of the automatic labels (the key files) against
                    the adjudicated sheet, per tag (steps) or for the stub flag (functions).

    python3 scripts/label_agreement.py steps H1_steps.csv H2_steps.csv --skip 10
    python3 scripts/label_agreement.py functions A_functions.csv B_functions.csv
    python3 scripts/label_agreement.py steps --truth adjudicated_steps.csv
    python3 scripts/label_agreement.py functions --truth adjudicated_functions.csv

Steps use the columns validation, memory_resource, threat, prevention, echo (0/1). Functions use is_stub (0/1) and implements_purpose (yes/partial/no).
Rows with an empty or invalid label in either sheet are listed and left out of that column.
"""
import argparse
import csv
import sys
from collections import Counter
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import label_functions  # noqa: E402

LABELS = Path(__file__).resolve().parent.parent / "results" / "labels"
COLS = {
    "steps": {"id": "step_id", "cols": ["validation", "memory_resource", "threat", "prevention", "echo"],
              "valid": {"0", "1"}},
    "functions": {"id": "id", "cols": ["is_stub", "implements_purpose"], "valid": None},
}
VALID_FUNC = {"is_stub": {"0", "1"}, "implements_purpose": {"yes", "partial", "no"}}


def read(path, kind):
    idc = COLS[kind]["id"]
    return {r[idc]: {k: (v or "").strip().lower() for k, v in r.items()}
            for r in csv.DictReader(open(path, encoding="utf-8"))}


def valid(kind, col, v):
    return v in (COLS[kind]["valid"] if kind == "steps" else VALID_FUNC[col])


def kappa(pairs):
    n = len(pairs)
    po = sum(a == b for a, b in pairs) / n
    ca, cb = Counter(a for a, _ in pairs), Counter(b for _, b in pairs)
    pe = sum(ca[k] * cb[k] for k in set(ca) | set(cb)) / n ** 2
    return po, (1.0 if pe == 1 else (po - pe) / (1 - pe))


def inter(kind, a_path, b_path, skip=0):
    A, B = read(a_path, kind), read(b_path, kind)
    ids = sorted((i for i in set(A) & set(B) if int(i) > skip), key=int)
    disagree, bad = {}, []
    print(f"{kind}: {len(ids)} items in both sheets" + (f" (ids 1-{skip} skipped: calibration)" if skip else ""))
    print(f"{'column':18} {'n':>4} {'agree':>7} {'kappa':>7}")
    for col in COLS[kind]["cols"]:
        pairs = []
        for i in ids:
            a, b = A[i][col], B[i][col]
            if not (valid(kind, col, a) and valid(kind, col, b)):
                bad.append((i, col, a, b))
                continue
            pairs.append((a, b))
            if a != b:
                disagree.setdefault(i, {})[col] = (a, b)
        if pairs:
            po, k = kappa(pairs)
            print(f"{col:18} {len(pairs):>4} {po:>7.3f} {k:>7.3f}")
    out = LABELS / f"disagreements_{kind}.csv"
    with open(out, "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["id", "column", "annotator_a", "annotator_b"])
        for i in sorted(disagree, key=int):
            for col, (a, b) in disagree[i].items():
                w.writerow([i, col, a, b])
    print(f"{sum(len(v) for v in disagree.values())} disagreements in {len(disagree)} items -> {out}")
    if bad:
        print(f"{len(bad)} cells empty or invalid (first 10): {bad[:10]}")


def truth_steps(path):
    key = {r["step_id"]: r for r in csv.DictReader(open(LABELS / "step_key.csv", encoding="utf-8"))}
    T = read(path, "steps")
    print(f"{'tag':18} {'n':>4} {'prec':>6} {'recall':>7} {'kappa':>7}")
    for col in COLS["steps"]["cols"]:
        tp = fp = fn = tn = 0
        for i, r in T.items():
            if r[col] not in ("0", "1") or i not in key:
                continue
            h, a = int(r[col]), int(key[i][col])
            tp += h and a; fp += (not h) and a; fn += h and (not a); tn += (not h) and (not a)
        n = tp + fp + fn + tn
        if not n:
            continue
        po = (tp + tn) / n
        pe = ((tp + fp) * (tp + fn) + (fn + tn) * (fp + tn)) / n ** 2
        k = 1.0 if pe == 1 else (po - pe) / (1 - pe)
        print(f"{col:18} {n:>4} {tp / max(tp + fp, 1):>6.3f} {tp / max(tp + fn, 1):>7.3f} {k:>7.3f}")


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("kind", choices=["steps", "functions"])
    ap.add_argument("sheets", nargs="*", type=Path, help="two filled sheets (inter-annotator)")
    ap.add_argument("--skip", type=int, default=0, help="leave out ids 1..N (calibration items)")
    ap.add_argument("--truth", type=Path, help="adjudicated sheet, compared with the automatic labels")
    a = ap.parse_args()
    if a.truth:
        truth_steps(a.truth) if a.kind == "steps" else label_functions.agreement(a.truth)
    elif len(a.sheets) == 2:
        inter(a.kind, *a.sheets, skip=a.skip)
    else:
        ap.error("give two filled sheets, or --truth with one adjudicated sheet")


if __name__ == "__main__":
    main()
