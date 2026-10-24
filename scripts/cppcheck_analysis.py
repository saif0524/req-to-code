"""
Run cppcheck on the generated C++ of each stored round and summarise the findings.

Reads   results/runs/<round>/<arm>__<model>/s0/{code/*.cpp,records.jsonl}
        results/runs/<round>/<arm>__<model>/s0/verify_units.csv   (usable flag, from verify.py)
Writes  results/cppcheck/findings.csv   one row per finding: round, arm, model, unit, usable, function, id, severity, line, message
        results/cppcheck/summary.csv    round x arm: files checked, files with findings, parse errors, usable units, usable with findings
        results/cppcheck/by_class.csv   round x arm x finding id x severity: findings in all files and in usable files
        results/cppcheck/meta.json      cppcheck version, flags, rounds

cppcheck runs on every file that has code, with the flags verify.py uses. Findings are mapped to
a function by line range; findings outside every function (includes, shared declarations) have an
empty function. Only the four analysed models are counted. Nothing under results/runs is modified.

    bash scripts/run_cppcheck.sh                         # R0 C1 C2
    python3 scripts/cppcheck_analysis.py --rounds R0 C2 --jobs 8
"""
import argparse
import csv
import json
import subprocess
import sys
import xml.etree.ElementTree as ET
from collections import Counter
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
import verify  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs"
OUT = ROOT / "results" / "cppcheck"
EXCLUDE = {"codegemma2b"}
FIELDS = ["round", "arm", "model", "unit_id", "usable", "func", "id", "severity", "line", "message"]


def check(path):
    """Return (findings as (id, severity, line, message), parse_error)."""
    try:
        r = subprocess.run(["cppcheck", *verify.CPPCHECK_FLAGS, str(path)],
                           capture_output=True, text=True, timeout=verify.CPPCHECK_TIMEOUT)
        root = ET.fromstring(r.stderr)
    except (subprocess.TimeoutExpired, ET.ParseError):
        return [], True
    found, parse_error = [], False
    for e in root.iter("error"):
        eid = e.get("id", "")
        if eid in verify.IGNORED_IDS:
            continue
        if eid in verify.PARSE_IDS:
            parse_error = True
            continue
        loc = e.find("location")
        line = int(loc.get("line", 0)) if loc is not None else 0
        found.append((eid, e.get("severity", ""), line, e.get("msg", "")))
    return found, parse_error


def jobs_for(rounds):
    for rnd in rounds:
        for d in sorted((RUNS / rnd).glob("*__*/s0")):
            arm, model = d.parent.name.split("__", 1)
            if model in EXCLUDE:
                continue
            usable = {r["unit_id"]: r["usable"] == "1"
                      for r in csv.DictReader(open(d / "verify_units.csv", encoding="utf-8"))}
            spans = {}
            for line in open(d / "records.jsonl", encoding="utf-8"):
                rec = json.loads(line)
                spans.setdefault(rec["unit_id"], []).append((rec["start_line"], rec["end_line"], rec["name"]))
            for cpp in sorted((d / "code").glob("*.cpp")):
                yield rnd, arm, model, cpp, usable.get(cpp.stem, False), spans.get(cpp.stem, [])


def run_job(job):
    rnd, arm, model, cpp, usable, spans = job
    finds, parse_err = check(cpp)
    rows = []
    for eid, sev, line, msg in finds:
        func = next((n for lo, hi, n in spans if lo <= line <= hi), "")
        rows.append({"round": rnd, "arm": arm, "model": model, "unit_id": cpp.stem, "usable": int(usable),
                     "func": func, "id": eid, "severity": sev, "line": line, "message": msg})
    return (rnd, arm, usable, bool(finds), parse_err), rows


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--rounds", nargs="+", default=["R0", "C1", "C2"])
    ap.add_argument("--jobs", type=int, default=8)
    args = ap.parse_args()

    OUT.mkdir(parents=True, exist_ok=True)
    jobs = list(jobs_for(args.rounds))
    print(f"cppcheck on {len(jobs)} files, rounds {args.rounds}")
    with ThreadPoolExecutor(args.jobs) as pool:
        results = list(pool.map(run_job, jobs))

    findings = [row for _, rows in results for row in rows]
    with open(OUT / "findings.csv", "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, FIELDS)
        w.writeheader()
        w.writerows(findings)

    files = Counter()
    for (rnd, arm, usable, has_find, parse_err), _ in results:
        k = (rnd, arm)
        files[k, "files"] += 1
        files[k, "with_findings"] += has_find
        files[k, "parse_errors"] += parse_err
        files[k, "usable"] += usable
        files[k, "usable_with_findings"] += usable and has_find
    n_find = Counter()
    for r in findings:
        n_find[r["round"], r["arm"], "findings"] += 1
        n_find[r["round"], r["arm"], "usable_findings"] += r["usable"]
    keys = sorted({k for k, _ in files})
    with open(OUT / "summary.csv", "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["round", "arm", "files", "files_with_findings", "parse_errors", "findings",
                    "usable_files", "usable_with_findings", "usable_findings"])
        for rnd, arm in keys:
            w.writerow([rnd, arm, files[(rnd, arm), "files"], files[(rnd, arm), "with_findings"],
                        files[(rnd, arm), "parse_errors"], n_find[rnd, arm, "findings"],
                        files[(rnd, arm), "usable"], files[(rnd, arm), "usable_with_findings"],
                        n_find[rnd, arm, "usable_findings"]])

    cls = Counter()
    for r in findings:
        cls[r["round"], r["arm"], r["id"], r["severity"], "all"] += 1
        cls[r["round"], r["arm"], r["id"], r["severity"], "usable"] += r["usable"]
    with open(OUT / "by_class.csv", "w", newline="", encoding="utf-8") as f:
        w = csv.writer(f)
        w.writerow(["round", "arm", "id", "severity", "findings", "usable_findings"])
        for rnd, arm, eid, sev in sorted({k[:4] for k in cls}):
            w.writerow([rnd, arm, eid, sev, cls[rnd, arm, eid, sev, "all"], cls[rnd, arm, eid, sev, "usable"]])

    (OUT / "meta.json").write_text(json.dumps({
        "cppcheck": verify.tool_version(["cppcheck", "--version"]),
        "flags": verify.CPPCHECK_FLAGS, "rounds": args.rounds, "files": len(jobs),
        "models_excluded": sorted(EXCLUDE)}, indent=2), encoding="utf-8")

    print(f"{'round':5s} {'arm':8s} {'files':>6s} {'w/find':>7s} {'parse':>6s} {'finds':>6s} {'usable':>7s} {'u+find':>7s}")
    for rnd, arm in keys:
        print(f"{rnd:5s} {arm:8s} {files[(rnd, arm), 'files']:6d} {files[(rnd, arm), 'with_findings']:7d} "
              f"{files[(rnd, arm), 'parse_errors']:6d} {n_find[rnd, arm, 'findings']:6d} "
              f"{files[(rnd, arm), 'usable']:7d} {files[(rnd, arm), 'usable_with_findings']:7d}")
    print(f"wrote {OUT}")


if __name__ == "__main__":
    main()
