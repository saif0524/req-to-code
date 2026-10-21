"""
Aggregate verify.py output into sampling metrics, arm comparisons and round transitions.

Reads   results/runs/<round>/<arm>__<model>/s<i>/verify_{units,functions}.csv
Writes  results/metrics.csv        per (round, arm, model, metric, k): value and 95% CI
        results/metrics_arms.csv   secure minus general, paired by unit, with CI
        results/transitions.csv    per run vs its parent round: usable/findings movement

Definitions (denominator is every planned unit, including units with no code):
  compile@k, usable@k, secure@k   unbiased pass@k estimator (Chen et al. 2021) over the
                                  n samples of a unit; at k=1 it equals the sample mean
  vuln_rate                       usable samples with cppcheck findings / usable samples
  findings_per_kloc               findings / KLOC over usable samples
  sec_terms_per_100w              security-lexicon hits per 100 words of reasoning

Transitions compare sample i of a round with sample i of its manifest `parent`. Finding
movement (fixed / persisted / introduced, by cppcheck class counts, since line numbers
shift) is counted only for units usable in both rounds; newly usable units are counted
under became_usable.

Confidence intervals are percentile bootstraps over units (units are the sampling
unit; samples within a unit are not treated as independent). Arm differences use the
same resampled unit indices for both arms.

    python3 scripts/metrics.py
    python3 scripts/metrics.py --k 1 3 5 --boot 5000
"""
import argparse
import csv
import json
from collections import defaultdict
from math import comb
from pathlib import Path

import numpy as np

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs"
INT_COLS = ["sample", "has_code", "n_planned", "compiles", "usable", "loc", "cppcheck_findings",
            "cppcheck_parse_error", "secure"]


def read_csv(path):
    with open(path, newline="", encoding="utf-8") as f:
        return list(csv.DictReader(f))


def pass_at_k(n, c, k):
    """Unbiased estimator 1 - C(n-c, k) / C(n, k); needs n >= k."""
    if n - c < k:
        return 1.0
    return 1.0 - comb(n - c, k) / comb(n, k)


def load(runs_root):
    units = defaultdict(lambda: defaultdict(dict))   # cfg -> unit_id -> sample -> row
    funcs = defaultdict(lambda: defaultdict(list))   # cfg -> unit_id -> rows
    manifests = {}
    for p in sorted(runs_root.glob("*/*__*/s*/verify_units.csv")):
        sd = p.parent
        rnd, (arm, model) = sd.parent.parent.name, sd.parent.name.split("__", 1)
        sample = int(sd.name[1:])
        cfg = (rnd, arm, model)
        for r in read_csv(p):
            for c in INT_COLS:
                r[c] = int(r[c])
            units[cfg][r["unit_id"]][sample] = r
        fp = sd / "verify_functions.csv"
        if fp.exists():
            for r in read_csv(fp):
                funcs[cfg][r["unit_id"]].append(r)
        mp = sd / "manifest.json"
        manifests[(rnd, arm, model, sample)] = json.loads(mp.read_text()) if mp.exists() else {}
    return units, funcs, manifests


def unit_vectors(cfg_units, cfg_funcs, unit_ids, ks):
    """Per-unit numerator/denominator arrays for every metric."""
    spec = defaultdict(lambda: ([], []))

    def add(name, num, den):
        spec[name][0].append(num)
        spec[name][1].append(den)

    for u in unit_ids:
        rows = list(cfg_units.get(u, {}).values())
        n = len(rows)
        for flag in ("compiles", "usable", "secure"):
            c = sum(r[flag] for r in rows)
            for k in ks:
                add((f"{flag}@k", k), pass_at_k(n, c, k) if n >= k else np.nan, 1.0)
        use = [r for r in rows if r["usable"]]
        add(("vuln_rate", 0), sum(1 for r in use if r["cppcheck_findings"] > 0), len(use))
        add(("findings_per_kloc", 0), sum(r["cppcheck_findings"] for r in use),
            sum(r["loc"] for r in use) / 1000)
        fr = cfg_funcs.get(u, [])
        add(("sec_terms_per_100w", 0), sum(int(f["sec_terms"]) for f in fr),
            sum(int(f["reasoning_words"]) for f in fr) / 100)
    return {k: (np.array(v[0], float), np.array(v[1], float)) for k, v in spec.items()}


def ratio(num, den, idx=None):
    if idx is not None:
        num, den = num[idx], den[idx]
    valid = ~np.isnan(num)
    if idx is not None:
        s_num = np.where(valid, num, 0).sum(axis=-1)
        s_den = np.where(valid, den, 0).sum(axis=-1)
    else:
        s_num, s_den = num[valid].sum(), den[valid].sum()
    with np.errstate(divide="ignore", invalid="ignore"):
        return s_num / s_den


def ci(samples):
    s = samples[~np.isnan(samples)]
    return (np.percentile(s, 2.5), np.percentile(s, 97.5)) if len(s) else (np.nan, np.nan)


def transitions(units, manifests):
    rows = []
    for (rnd, arm, model, sample), m in sorted(manifests.items()):
        parent = m.get("parent")
        if not parent:
            continue
        pcfg, cfg = (parent, arm, model), (rnd, arm, model)
        agg = defaultdict(int)
        for u, samples in units[cfg].items():
            a = samples.get(sample)
            b = units.get(pcfg, {}).get(u, {}).get(sample)
            if a is None or b is None:
                continue
            agg["units"] += 1
            if not b["usable"] and a["usable"]:
                agg["became_usable"] += 1
            elif b["usable"] and not a["usable"]:
                agg["regressed"] += 1
            elif b["usable"]:
                agg["stay_usable"] += 1
            else:
                agg["stay_unusable"] += 1
            if a["usable"] and b["usable"]:
                ca, cb = json.loads(a["cppcheck_classes"]), json.loads(b["cppcheck_classes"])
                for cls in set(ca) | set(cb):
                    x, y = cb.get(cls, 0), ca.get(cls, 0)
                    agg["findings_fixed"] += max(0, x - y)
                    agg["findings_persisted"] += min(x, y)
                    agg["findings_introduced"] += max(0, y - x)
        rows.append({"round": rnd, "parent": parent, "arm": arm, "model": model,
                     "sample": sample, **{k: agg[k] for k in (
                         "units", "became_usable", "regressed", "stay_usable", "stay_unusable",
                         "findings_fixed", "findings_persisted", "findings_introduced")}})
    return rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--k", type=int, nargs="+", default=[1, 5])
    ap.add_argument("--boot", type=int, default=2000)
    ap.add_argument("--runs-root", type=Path, default=RUNS)
    ap.add_argument("--out", type=Path, default=ROOT / "results")
    args = ap.parse_args()

    units, funcs, manifests = load(args.runs_root)
    if not units:
        raise SystemExit(f"no verify_units.csv under {args.runs_root}; run verify.py first")
    rng = np.random.default_rng(0)

    metric_rows, vecs = [], {}
    for cfg in sorted(units):
        ids = sorted(units[cfg])
        n_samples = max(len(s) for s in units[cfg].values())
        vec = unit_vectors(units[cfg], funcs[cfg], ids, args.k)
        vecs[cfg] = (ids, vec)
        idx = rng.integers(0, len(ids), (args.boot, len(ids)))
        for (name, k), (num, den) in sorted(vec.items()):
            if np.all(np.isnan(num)):
                continue
            lo, hi = ci(ratio(num, den, idx))
            metric_rows.append({"round": cfg[0], "arm": cfg[1], "model": cfg[2],
                                "metric": name.replace("@k", f"@{k}") if k else name,
                                "value": round(float(ratio(num, den)), 4),
                                "ci_lo": round(float(lo), 4), "ci_hi": round(float(hi), 4),
                                "n_units": len(ids), "n_samples": n_samples})

    arm_rows = []
    try:
        from scipy.stats import wilcoxon
    except ImportError:
        wilcoxon = None
    for rnd, model in sorted({(c[0], c[2]) for c in vecs}):
        g, s = (rnd, "general", model), (rnd, "secure", model)
        if g not in vecs or s not in vecs:
            continue
        common = sorted(set(vecs[g][0]) & set(vecs[s][0]))
        gi = [vecs[g][0].index(u) for u in common]
        si = [vecs[s][0].index(u) for u in common]
        idx = rng.integers(0, len(common), (args.boot, len(common)))
        for key in sorted(set(vecs[g][1]) & set(vecs[s][1])):
            gn, gd = (a[gi] for a in vecs[g][1][key])
            sn, sd = (a[si] for a in vecs[s][1][key])
            if np.all(np.isnan(gn)) or np.all(np.isnan(sn)):
                continue
            diff = ratio(sn, sd) - ratio(gn, gd)
            lo, hi = ci(ratio(sn, sd, idx) - ratio(gn, gd, idx))
            p = ""
            if wilcoxon and key[0].split("@")[0] in ("compiles", "usable", "secure"):
                d = sn - gn
                d = d[~np.isnan(d)]
                if np.any(d != 0):
                    p = round(float(wilcoxon(d).pvalue), 4)
            name, k = key
            arm_rows.append({"round": rnd, "model": model,
                             "metric": name.replace("@k", f"@{k}") if k else name,
                             "general": round(float(ratio(gn, gd)), 4),
                             "secure": round(float(ratio(sn, sd)), 4),
                             "diff_secure_minus_general": round(float(diff), 4),
                             "ci_lo": round(float(lo), 4), "ci_hi": round(float(hi), 4),
                             "wilcoxon_p": p, "n_units": len(common)})

    trans_rows = transitions(units, manifests)

    args.out.mkdir(parents=True, exist_ok=True)
    for name, rows in (("metrics", metric_rows), ("metrics_arms", arm_rows),
                       ("transitions", trans_rows)):
        if rows:
            with open(args.out / f"{name}.csv", "w", newline="", encoding="utf-8") as f:
                w = csv.DictWriter(f, fieldnames=list(rows[0]))
                w.writeheader()
                w.writerows(rows)

    shown = ("compiles@1", "usable@1", "secure@1", "vuln_rate", "findings_per_kloc")
    print(f"{'round':5} {'arm':8} {'model':16}" + "".join(f"{m:>26}" for m in shown))
    by = defaultdict(dict)
    for r in metric_rows:
        by[(r["round"], r["arm"], r["model"])][r["metric"]] = r
    for (rnd, arm, model), ms in sorted(by.items()):
        cells = []
        for m in shown:
            r = ms.get(m)
            cells.append(f"{r['value']:.3f} [{r['ci_lo']:.3f},{r['ci_hi']:.3f}]" if r else "-")
        print(f"{rnd:5} {arm:8} {model:16}" + "".join(f"{c:>26}" for c in cells))


if __name__ == "__main__":
    main()
