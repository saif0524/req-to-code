#!/usr/bin/env bash
# cppcheck on the generated code of the stored rounds, then a summary under results/cppcheck/.
# Does not modify results/runs (verify.py recomputes the per-run columns).
#
#   bash scripts/run_cppcheck.sh                # R0 C1 C2
#   bash scripts/run_cppcheck.sh R0 C2          # chosen rounds
#   JOBS=16 bash scripts/run_cppcheck.sh
set -euo pipefail
cd "$(dirname "$0")/.."
command -v cppcheck >/dev/null || { echo "cppcheck not found on PATH" >&2; exit 1; }
cppcheck --version
rounds=("$@")
[ ${#rounds[@]} -eq 0 ] && rounds=(R0 C1 C2)
python3 scripts/cppcheck_analysis.py --rounds "${rounds[@]}" --jobs "${JOBS:-8}"
