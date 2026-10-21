"""
Copy results/generation/<variant>__<model>/ into the round/sample layout:

  results/runs/R0/<arm>__<model>/s0/{records.jsonl,units.jsonl,code/,manifest.json}

arm: baseline -> general, secure_prompt -> secure. The source directories are left in
place. Existing records keep their original `variant` field; the arm is in the path and
the manifest. Re-running skips targets that already exist.

    python3 scripts/migrate_r0.py
"""
import hashlib
import json
import shutil
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SRC = ROOT / "results" / "generation"
DST = ROOT / "results" / "runs" / "R0"
ARM = {"baseline": "general", "secure_prompt": "secure"}

# gen_functions.py hardcodes temperature 0.0 in chat_json and seeds with 0 + offset.
R0_TEMPERATURE = 0.0


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    made = 0
    for d in sorted(SRC.iterdir()):
        if not (d / "records.jsonl").exists() or "__" not in d.name:
            continue
        variant, model = d.name.split("__", 1)
        arm = ARM.get(variant)
        if arm is None:
            print(f"skip {d.name}: unknown variant")
            continue
        out = DST / f"{arm}__{model}" / "s0"
        if out.exists():
            print(f"exists {out.relative_to(ROOT)}")
            continue
        shutil.copytree(d, out)

        units = [json.loads(l) for l in (out / "units.jsonl").read_text().splitlines() if l.strip()]
        code_hashes = {p.stem: sha(p) for p in sorted((out / "code").glob("*.cpp"))}
        manifest = {
            "round": "R0",
            "arm": arm,
            "variant": variant,
            "model": model,
            "model_tag": units[0]["model"] if units else None,
            "sample": 0,
            "parent": None,
            "seeds": sorted({u["seed"] for u in units}),
            "temperature": R0_TEMPERATURE,
            "system_hash": sorted({u["system_hash"] for u in units}),
            "n_units": len(units),
            "n_units_with_code": len(code_hashes),
            "status_counts": {s: sum(1 for u in units if u["status"] == s)
                              for s in sorted({u["status"] for u in units})},
            "code_sha256": code_hashes,
            "source": str(d.relative_to(ROOT)),
            "created": datetime.now(timezone.utc).isoformat(timespec="seconds"),
        }
        (out / "manifest.json").write_text(json.dumps(manifest, indent=2), encoding="utf-8")
        made += 1
        print(f"wrote {out.relative_to(ROOT)}  units={len(units)} code={len(code_hashes)}")
    print(f"{made} directories created")


if __name__ == "__main__":
    main()
