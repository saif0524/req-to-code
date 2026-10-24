"""
Recompile generated units with and without the extra standard headers added to
gen_functions.INCLUDES, and record both results.

Every unit file is compiled twice with `g++ -std=c++17 -fsyntax-only`:
  before  the file with the EXTRA_INCLUDES lines removed
  after   the file with EXTRA_INCLUDES present
so the comparison does not depend on when a file was generated.

Writes (default results/):
  compile_by_unit.csv   one row per unit and mode-pair: errors before/after, first error
  compile_summary.csv   one row per (doc, variant, model) plus ALL rows per (variant, model)

    python scripts/recompile.py
    python scripts/recompile.py --write     # also add the headers to the stored .cpp files
"""
import argparse
import csv
import json
import re
import subprocess
import time
from collections import defaultdict
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
GEN = ROOT / "results" / "generation"
UNITS = ROOT / "data" / "requirements_units.jsonl"

import sys

sys.path.insert(0, str(Path(__file__).resolve().parent))
from gen_functions import EXTRA_INCLUDES  # noqa: E402

EXTRA_SET = set(EXTRA_INCLUDES)


def without_extra(src):
    return "\n".join(l for l in src.splitlines() if l.strip() not in EXTRA_SET) + "\n"


def with_extra(src):
    lines = without_extra(src).splitlines()
    last = max((i for i, l in enumerate(lines) if l.startswith("#include")), default=-1)
    return "\n".join(lines[: last + 1] + EXTRA_INCLUDES + lines[last + 1 :]) + "\n"


def compile_source(src):
    try:
        r = subprocess.run(["g++", "-std=c++17", "-fsyntax-only", "-x", "c++", "-"],
                           input=src, capture_output=True, text=True, timeout=120)
    except subprocess.TimeoutExpired:
        return None, 0, "timeout"
    errs = [l for l in r.stderr.splitlines() if ": error:" in l]
    first = re.sub(r"^.*?: error: ", "", errs[0]) if errs else ""
    return r.returncode == 0, len(errs), first[:160]


def run_unit(job):
    path, doc, variant, model = job
    src = path.read_text(encoding="utf-8")
    ok_b, n_b, first_b = compile_source(without_extra(src))
    ok_a, n_a, first_a = compile_source(with_extra(src))
    return {"doc": doc, "variant": variant, "model": model, "unit_id": path.stem,
            "ok_before": ok_b, "errors_before": n_b, "ok_after": ok_a, "errors_after": n_a,
            "first_error_before": first_b, "first_error_after": first_a}


def rate(n, d):
    return round(n / d, 4) if d else ""


def summarize(rows, total_units):
    groups = defaultdict(list)
    for r in rows:
        groups[(r["doc"], r["variant"], r["model"])].append(r)
        groups[("ALL", r["variant"], r["model"])].append(r)
    out = []
    for (doc, variant, model), rs in sorted(groups.items()):
        n = len(rs)
        okb = sum(1 for r in rs if r["ok_before"])
        oka = sum(1 for r in rs if r["ok_after"])
        eb = sum(r["errors_before"] for r in rs)
        ea = sum(r["errors_after"] for r in rs)
        out.append({
            "doc": doc, "variant": variant, "model": model,
            "units_total": total_units.get((doc, variant, model), ""),
            "units_with_code": n,
            "compiles_before": okb, "compiles_after": oka,
            "error_rate_before": rate(n - okb, n), "error_rate_after": rate(n - oka, n),
            "errors_total_before": eb, "errors_total_after": ea,
            "errors_per_unit_before": rate(eb, n), "errors_per_unit_after": rate(ea, n),
        })
    return out


def write_csv(path, rows):
    if not rows:
        return
    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("--out-dir", default=str(ROOT / "results"))
    ap.add_argument("--workers", type=int, default=4)
    ap.add_argument("--write", action="store_true", help="add EXTRA_INCLUDES to stored .cpp files")
    ap.add_argument("--restore", action="store_true",
                    help="remove EXTRA_INCLUDES from stored .cpp files (original generated form)")
    ap.add_argument("--normalize-units", action="store_true",
                    help="set compiles/n_compile_errors in units.jsonl to the 'before' result")
    args = ap.parse_args()

    doc_of = {}
    for l in open(UNITS, encoding="utf-8"):
        u = json.loads(l)
        doc_of[u["unit_id"]] = u["doc"]

    jobs, total_units = [], defaultdict(int)
    for run in sorted(GEN.glob("*__*")):
        variant, _, model = run.name.partition("__")
        if (run / "units.jsonl").exists():
            for l in open(run / "units.jsonl", encoding="utf-8"):
                uid = json.loads(l)["unit_id"]
                doc = doc_of.get(uid, "?")
                total_units[(doc, variant, model)] += 1
                total_units[("ALL", variant, model)] += 1
        # Only the five models in models.json; skip earlier qwen25coder7b trial dirs.
        if model not in {"qwen25coder15b", "qwen25coder3b", "deepcoder15b", "opencoder15b"}:
            continue
        for p in sorted((run / "code").glob("*.cpp")):
            if time.time() - p.stat().st_mtime < 60:  # may still be written by a running job
                continue
            jobs.append((p, doc_of.get(p.stem, "?"), variant, model))

    print(f"[INFO] compiling {len(jobs)} files twice")
    with ThreadPoolExecutor(args.workers) as ex:
        rows = list(ex.map(run_unit, jobs))

    out = Path(args.out_dir)
    out.mkdir(parents=True, exist_ok=True)
    write_csv(out / "compile_by_unit.csv", rows)
    summary = summarize(rows, total_units)
    write_csv(out / "compile_summary.csv", summary)

    print(f"{'variant':14s} {'model':16s} {'n':>5s} {'err_rate before':>16s} {'after':>7s}")
    for s in summary:
        if s["doc"] == "ALL":
            print(f"{s['variant']:14s} {s['model']:16s} {s['units_with_code']:5d} "
                  f"{s['error_rate_before']:16} {s['error_rate_after']:7}")

    if args.write:
        n = 0
        for p, *_ in jobs:
            p.write_text(with_extra(p.read_text(encoding="utf-8")), encoding="utf-8")
            n += 1
        print(f"[INFO] added headers to {n} stored files")
    if args.restore:
        n = 0
        for p, *_ in jobs:
            p.write_text(without_extra(p.read_text(encoding="utf-8")), encoding="utf-8")
            n += 1
        print(f"[INFO] restored {n} stored files to the original include list")

    if args.normalize_units:
        before = {(r["variant"], r["model"], r["unit_id"]): r for r in rows}
        changed = 0
        for run in sorted(GEN.glob("*__*")):
            variant, _, model = run.name.partition("__")
            up = run / "units.jsonl"
            if not up.exists():
                continue
            out_lines = []
            for l in open(up, encoding="utf-8"):
                u = json.loads(l)
                r = before.get((variant, model, u["unit_id"]))
                if r and (u.get("compiles") != r["ok_before"] or u.get("n_compile_errors") != r["errors_before"]):
                    u["compiles"], u["n_compile_errors"] = r["ok_before"], r["errors_before"]
                    changed += 1
                out_lines.append(json.dumps(u))
            up.write_text("\n".join(out_lines) + "\n", encoding="utf-8")
        print(f"[INFO] normalized compile fields of {changed} units in units.jsonl")
    print(f"[INFO] wrote {out / 'compile_summary.csv'} and {out / 'compile_by_unit.csv'}")


if __name__ == "__main__":
    main()
