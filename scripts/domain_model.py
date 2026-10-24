"""
Missing domain model (RQ3): how often the plan declares shared types, and how often the first
compiler error of a failing section is an undeclared type or name.

Reads   results/runs/R0/<arm>__<model>/s0/{units.jsonl,verify_units.csv}
Writes  results/stubs/domain_model.csv

  shared types   share of the 166 sections whose plan has non-empty shared_declarations
  undeclared     among sections with code that do not compile, share whose first g++ error is
                 one of the UNDECLARED messages (a name or type that was never declared; a
                 parameter of unknown type also yields "variable or field ... declared void")

    python3 scripts/domain_model.py
"""
import csv
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs" / "R0"
OUT = ROOT / "results" / "stubs" / "domain_model.csv"
UNDECLARED = re.compile(r"was not declared|does not name a type|has not been declared|"
                        r"incomplete type|declared void")


def main():
    rows = []
    for d in sorted(RUNS.glob("*__*/s0")):
        arm, model = d.parent.name.split("__", 1)
        units = [json.loads(l) for l in open(d / "units.jsonl", encoding="utf-8") if l.strip()]
        shared = sum(1 for u in units if (u.get("shared_declarations") or "").strip())
        failing = [r for r in csv.DictReader(open(d / "verify_units.csv", encoding="utf-8"))
                   if r["has_code"] in ("1", "True", "true") and r["compiles"] not in ("1", "True", "true")]
        undeclared = sum(1 for r in failing if UNDECLARED.search(r.get("first_error", "")))
        rows.append({"model": model, "arm": arm, "sections": len(units), "shared_types": shared,
                     "shared_share": round(shared / len(units), 3), "failing": len(failing),
                     "undeclared_first_error": undeclared,
                     "undeclared_share": round(undeclared / max(len(failing), 1), 3)})
    with open(OUT, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    for r in rows:
        print(f"{r['model']:16} {r['arm']:8} shared types {r['shared_share']:.0%}  "
              f"undeclared first error {r['undeclared_first_error']}/{r['failing']} ({r['undeclared_share']:.0%})")


if __name__ == "__main__":
    main()
