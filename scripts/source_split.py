"""
Headline results split by PURE source tag (Ferrari et al., RE 2017): I = company or public body,
U = university case study or assignment. Tags are the authors' reading, confirmed by the user.

  core shift  secure-minus-general share of reasoning steps in a core category (echo removed)
  stub rate   share of R0 functions that are stubs, per prompt
Percentile bootstrap (2000) over requirement sections, within each group.

    python3 scripts/source_split.py
"""
import csv
import json
import sys
from collections import defaultdict
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sample_functions import classify  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
SOURCE = {"0000 - cctns": "I", "1999 - dii": "I", "1998 - themas": "I", "2005 - microcare": "I",
          "2008 - keepass": "I", "2010-blitdraft": "I",
          "2008 - peering": "U", "0000 - gamma j": "U", "2007 - get real 0.2": "U",
          "2009 - video search": "U", "2003 - qheadache": "U"}
STUB = {"empty", "output/trivial only", "placeholder-marked"}
EXCLUDE = {"codegemma2b"}


def main(boot=2000):
    doc = {}
    for l in (ROOT / "data" / "requirements_units.jsonl").read_text(encoding="utf-8").splitlines():
        if l.strip():
            u = json.loads(l)
            if u["doc"] in SOURCE:
                doc[u["unit_id"]] = u["doc"]
    steps = defaultdict(lambda: [0, 0])
    for r in csv.DictReader(open(ROOT / "results" / "reasoning" / "steps_tagged.csv", encoding="utf-8")):
        if r["model"] in EXCLUDE:
            continue
        a = steps[(r["model"], r["unit_id"], r["arm"])]
        a[0] += 1
        a[1] += int(r["sec_core_noecho"])
    pairs = [(m, u) for (m, u, arm) in steps if arm == "general" and (m, u, "secure") in steps]
    funcs = []
    for f in sorted((ROOT / "results" / "runs" / "R0").glob("*__*/s0/records.jsonl")):
        arm, model = f.parent.parent.name.split("__", 1)
        if model in EXCLUDE:
            continue
        for l in f.read_text(encoding="utf-8").splitlines():
            if l.strip():
                r = json.loads(l)
                funcs.append((arm, r["unit_id"], classify(r["code"]) in STUB))

    rng = np.random.default_rng(0)
    rows = []
    for g in ("I", "U", "all"):
        units = sorted({u for u in doc if g == "all" or SOURCE[doc[u]] == g})
        ix = {u: i for i, u in enumerate(units)}
        n = len(units)
        # per-unit sums
        c = {k: np.zeros((2, n)) for k in ("steps", "core")}
        for m, u in pairs:
            if u in ix:
                for j, arm in enumerate(("general", "secure")):
                    s = steps[(m, u, arm)]
                    c["steps"][j, ix[u]] += s[0]
                    c["core"][j, ix[u]] += s[1]
        st = np.zeros((2, 2, n))
        for arm, u, is_stub in funcs:
            if u in ix:
                j = 0 if arm == "general" else 1
                st[j, 0, ix[u]] += 1
                st[j, 1, ix[u]] += is_stub
        draws = rng.integers(0, n, (boot, n))
        w = np.array([np.bincount(d, minlength=n) for d in draws])

        def shift(wt):
            g_ = (wt @ c["core"][0]) / np.maximum(wt @ c["steps"][0], 1e-9)
            s_ = (wt @ c["core"][1]) / np.maximum(wt @ c["steps"][1], 1e-9)
            return s_ - g_
        base = shift(np.ones((1, n)))[0]
        lo, hi = np.percentile(shift(w), [2.5, 97.5])
        row = {"group": g, "sections": n, "pairs": sum(1 for m, u in pairs if u in ix),
               "core_shift": round(base, 4), "core_lo": round(lo, 4), "core_hi": round(hi, 4)}
        for j, arm in enumerate(("general", "secure")):
            est = st[j, 1].sum() / st[j, 0].sum()
            b = (w @ st[j, 1]) / np.maximum(w @ st[j, 0], 1e-9)
            l_, h_ = np.percentile(b, [2.5, 97.5])
            row.update({f"stub_{arm}": round(est, 4), f"stub_{arm}_lo": round(l_, 4), f"stub_{arm}_hi": round(h_, 4)})
        rows.append(row)
    out = ROOT / "results" / "robustness"
    out.mkdir(parents=True, exist_ok=True)
    with open(out / "source_split.csv", "w", newline="", encoding="utf-8") as fh:
        wr = csv.DictWriter(fh, fieldnames=list(rows[0]))
        wr.writeheader()
        wr.writerows(rows)
    for r in rows:
        print(f"{r['group']:4} sections {r['sections']:3} pairs {r['pairs']:3}  core shift {r['core_shift']*100:+.1f} "
              f"[{r['core_lo']*100:+.1f}, {r['core_hi']*100:+.1f}]  stubs general {r['stub_general']:.1%} "
              f"[{r['stub_general_lo']:.1%}, {r['stub_general_hi']:.1%}]  secure {r['stub_secure']:.1%} "
              f"[{r['stub_secure_lo']:.1%}, {r['stub_secure_hi']:.1%}]")


if __name__ == "__main__":
    main()
