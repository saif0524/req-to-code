"""
Leave-one-document-out check for the two headline results.

  core shift  secure-minus-general share of reasoning steps in a core security category,
              prompt wording removed (from results/reasoning/steps_tagged.csv, capped steps),
              pooled over (model, unit) pairs with steps under both prompts
  stub rate   share of R0 functions that are stubs (sample_functions.classify), per prompt

Writes results/robustness/leave_one_doc_out.csv.

    python3 scripts/robustness_docs.py
"""
import csv
import json
import sys
from collections import defaultdict
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))
from sample_functions import classify  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
STUB = {"empty", "output/trivial only", "placeholder-marked"}


def main():
    doc = {}
    for l in (ROOT / "data" / "requirements_units.jsonl").read_text(encoding="utf-8").splitlines():
        if l.strip():
            u = json.loads(l)
            doc[u["unit_id"]] = u["doc"]

    # (model, unit, arm) -> [steps, core]
    steps = defaultdict(lambda: [0, 0])
    for r in csv.DictReader(open(ROOT / "results" / "reasoning" / "steps_tagged.csv", encoding="utf-8")):
        a = steps[(r["model"], r["unit_id"], r["arm"])]
        a[0] += 1
        a[1] += int(r["sec_core_noecho"])
    pairs = [(m, u) for (m, u, arm) in steps if arm == "general" and (m, u, "secure") in steps]

    funcs = []
    for f in sorted((ROOT / "results" / "runs" / "R0").glob("*__*/s0/records.jsonl")):
        arm, model = f.parent.parent.name.split("__", 1)
        for l in f.read_text(encoding="utf-8").splitlines():
            if l.strip():
                r = json.loads(l)
                funcs.append((arm, r["unit_id"], classify(r["code"]) in STUB))

    def stats(drop):
        tot = {"general": [0, 0], "secure": [0, 0]}
        for m, u in pairs:
            if doc[u] == drop:
                continue
            for arm in tot:
                s = steps[(m, u, arm)]
                tot[arm][0] += s[0]
                tot[arm][1] += s[1]
        g, s = (tot[a][1] / tot[a][0] for a in ("general", "secure"))
        st = {"general": [0, 0], "secure": [0, 0]}
        for arm, u, is_stub in funcs:
            if doc[u] != drop:
                st[arm][0] += 1
                st[arm][1] += is_stub
        return {"dropped": drop or "(none)", "pairs": sum(1 for m, u in pairs if doc[u] != drop),
                "core_general": round(g, 3), "core_secure": round(s, 3), "core_shift": round(s - g, 3),
                "stub_general": round(st["general"][1] / st["general"][0], 3),
                "stub_secure": round(st["secure"][1] / st["secure"][0], 3)}

    rows = [stats(None)] + [stats(d) for d in sorted({doc[u] for m, u in pairs})]
    out = ROOT / "results" / "robustness"
    out.mkdir(parents=True, exist_ok=True)
    with open(out / "leave_one_doc_out.csv", "w", newline="", encoding="utf-8") as fh:
        w = csv.DictWriter(fh, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)
    for r in rows:
        print(f"{r['dropped']:26}{r['pairs']:5}  core {r['core_general']:.3f} -> {r['core_secure']:.3f} "
              f"({r['core_shift']:+.3f})  stubs {r['stub_general']:.3f} / {r['stub_secure']:.3f}")


if __name__ == "__main__":
    main()
