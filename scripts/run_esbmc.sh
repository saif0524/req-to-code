#!/usr/bin/env bash
# Bounded model checking (ESBMC) of every usable section in the stored rounds.
# verify.py recomputes compile, cppcheck and ESBMC results for each round; ESBMC checks one
# function at a time with --function, on files whose sections compile and whose planned
# functions all have bodies. Verdicts per function: ok, fail:<property>, timeout, unsupported.
#
#   ESBMC_DIR=/path/to/esbmc/bin bash scripts/run_esbmc.sh            # R0 C1 C2
#   ESBMC_DIR=/path/to/esbmc/bin bash scripts/run_esbmc.sh R0 C2      # chosen rounds
#   JOBS=16 bash scripts/run_esbmc.sh
#
# Tested with ESBMC 8.0.0 (64-bit x86_64 Linux). ESBMC_DIR is only needed when esbmc is not on PATH.
set -euo pipefail
cd "$(dirname "$0")/.."
[ -n "${ESBMC_DIR:-}" ] && export PATH="$ESBMC_DIR:$PATH"
command -v esbmc >/dev/null || { echo "esbmc not found: set ESBMC_DIR or add it to PATH" >&2; exit 1; }
esbmc --version | head -1
rounds=("$@")
[ ${#rounds[@]} -eq 0 ] && rounds=(R0 C1 C2)
for r in "${rounds[@]}"; do
  echo "=== $r $(date +%H:%M:%S)"
  python3 scripts/verify.py --round "$r" --force --jobs "${JOBS:-16}"
done
python3 scripts/metrics.py --k 1 > /dev/null
echo "=== done $(date +%H:%M:%S)"
