"""
ESBMC verdicts per function for the paper's table, plus why functions are unsupported.

Reads   results/runs/<round>/<arm>__<model>/s0/verify_functions.csv   (esbmc column, from verify.py)
Writes  results/esbmc/verdicts.csv           round x arm: functions, ok, fail, timeout, unsupported
        results/esbmc/violations.csv         round x arm x violated property
        results/esbmc/unsupported_causes.csv first frontend error of each unsupported function
        results/esbmc/failure_locations.csv  where each violation sits: generated code, or
                                             ESBMC's own C++ library models (--locate)

Only the four analysed models are counted. `skipped_not_usable` rows are not checked and are
left out. Causes are found by rerunning ESBMC on each unsupported function and keeping the
first line that contains "error".

    python3 scripts/esbmc_analysis.py                    # R0 and C2 (the paper's table)
    python3 scripts/esbmc_analysis.py --rounds R0 C1 C2 --causes --locate
"""
import argparse
import csv
import re
import subprocess
import sys
import tempfile
from collections import Counter, defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs"
OUT = ROOT / "results" / "esbmc"
EXCLUDE = {"codegemma2b"}
KINDS = ["ok", "fail", "timeout", "unsupported"]


def rows(rnd):
    for d in sorted((RUNS / rnd).glob("*__*/s0")):
        arm, model = d.parent.name.split("__", 1)
        if model in EXCLUDE:
            continue
        for r in csv.DictReader(open(d / "verify_functions.csv", encoding="utf-8")):
            yield arm, model, d, r


def cause(path, func):
    src = re.sub(r"^\s*#include\s*<optional>\s*$", "", Path(path).read_text(encoding="utf-8"), flags=re.M)
    with tempfile.TemporaryDirectory() as tmp:
        p = Path(tmp) / Path(path).name
        p.write_text(src, encoding="utf-8")
        try:
            r = subprocess.run(["esbmc", str(p), "--function", func, *verify.ESBMC_FLAGS],
                               capture_output=True, text=True, timeout=90)
        except subprocess.TimeoutExpired:
            return "timeout"
    out = r.stdout + r.stderr
    for line in out.splitlines():
        if "error" in line.lower() and "ERROR: PARSING" not in line:
            line = re.sub(r"^\S+?:\d+:\d+:\s*", "", line)
            line = re.sub(r"'[^']*'", "'_'", line)
            return line.strip()[:90]
    for line in out.splitlines():
        if line.startswith("ERROR"):
            return re.sub(r"`[^`]*`", "`_`", line)[:90]
    return "no message"


def location(path, func):
    """Where the violated property sits: the generated file or ESBMC's own library models."""
    src = re.sub(r"^\s*#include\s*<optional>\s*$", "", Path(path).read_text(encoding="utf-8"), flags=re.M)
    with tempfile.TemporaryDirectory() as tmp:
        p = Path(tmp) / Path(path).name
        p.write_text(src, encoding="utf-8")
        try:
            r = subprocess.run(["esbmc", str(p), "--function", func, *verify.ESBMC_FLAGS],
                               capture_output=True, text=True, timeout=90)
        except subprocess.TimeoutExpired:
            return "timeout"
    m = re.search(r"Violated property:\s*\n\s*file (\S+)", r.stdout + r.stderr)
    if not m:
        return "unknown"
    where = m.group(1)
    if "esbmc-cpp-headers" in where or "/esbmc/" in where:
        return "esbmc_library_model"
    if where.startswith(tmp) or where.endswith(Path(path).name):
        return "generated_code"
    return "system_header"


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rounds", nargs="+", default=["R0", "C2"])
    ap.add_argument("--causes", action="store_true", help="rerun ESBMC on unsupported functions")
    ap.add_argument("--locate", action="store_true", help="rerun ESBMC on failing functions")
    args = ap.parse_args()
    OUT.mkdir(parents=True, exist_ok=True)

    counts, props = defaultdict(Counter), defaultdict(Counter)
    unsupported, failing = [], []
    for rnd in args.rounds:
        for arm, model, d, r in rows(rnd):
            v = r["esbmc"]
            kind = v.split(":")[0]
            if kind not in KINDS:
                continue
            counts[(rnd, arm)][kind] += 1
            if kind == "fail":
                props[(rnd, arm)][v.split(":", 1)[1].split(":")[0]] += 1
            if kind == "fail":
                failing.append((rnd, arm, d / "code" / f"{r['unit_id']}.cpp", r["func"], v.split(":", 1)[1].split(":")[0]))
            if kind == "unsupported":
                unsupported.append((rnd, arm, d / "code" / f"{r['unit_id']}.cpp", r["func"]))

    with open(OUT / "verdicts.csv", "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["round", "arm", "functions", *KINDS])
        for (rnd, arm), c in sorted(counts.items()):
            w.writerow([rnd, arm, sum(c.values()), *[c[k] for k in KINDS]])
    with open(OUT / "violations.csv", "w", newline="") as f:
        w = csv.writer(f)
        w.writerow(["round", "arm", "property", "functions"])
        for (rnd, arm), c in sorted(props.items()):
            for p, n in c.most_common():
                w.writerow([rnd, arm, p, n])
    if args.causes:
        cc = Counter()
        for rnd, arm, path, func in unsupported:
            cc[(rnd, cause(path, func))] += 1
        with open(OUT / "unsupported_causes.csv", "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["round", "first_error", "functions"])
            for (rnd, msg), n in sorted(cc.items(), key=lambda x: (x[0][0], -x[1])):
                w.writerow([rnd, msg, n])
    if args.locate:
        lc = Counter()
        for rnd, arm, path, func, prop in failing:
            lc[(rnd, arm, prop, location(path, func))] += 1
        with open(OUT / "failure_locations.csv", "w", newline="") as f:
            w = csv.writer(f)
            w.writerow(["round", "arm", "property", "location", "functions"])
            for k, n in sorted(lc.items(), key=lambda x: (x[0][0], x[0][1], -x[1])):
                w.writerow([*k, n])
    for (rnd, arm), c in sorted(counts.items()):
        print(rnd, arm, sum(c.values()), dict(c))


if __name__ == "__main__":
    main()
