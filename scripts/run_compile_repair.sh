#!/usr/bin/env bash
# Compile repair on the 166-section R0: C1 then C2 for the fast models, DeepCoder C1 last.
# repair.py skips units already written, so this resumes after an interruption.
#   setsid nohup bash scripts/run_compile_repair.sh >> results/logs/repair_166.log 2>&1 &
set -euo pipefail
cd "$(dirname "$0")/.."
FAST="qwen25coder15b qwen25coder3b opencoder15b"
for m in $FAST; do
  echo "=== C1 $m $(date +%H:%M:%S)"
  python3 scripts/repair.py --parent R0 --round C1 --kind compile --model "$m"
done
python3 scripts/verify.py --round C1 --no-esbmc
for m in $FAST; do
  echo "=== C2 $m $(date +%H:%M:%S)"
  python3 scripts/repair.py --parent C1 --round C2 --kind compile --model "$m"
done
python3 scripts/verify.py --round C2 --no-esbmc
python3 scripts/metrics.py --k 1 > /dev/null
echo "=== fast models C1+C2 done $(date +%H:%M:%S)"
echo "=== C1 deepcoder15b $(date +%H:%M:%S)"
python3 scripts/repair.py --parent R0 --round C1 --kind compile --model deepcoder15b
python3 scripts/verify.py --round C1 --no-esbmc
echo "=== all done $(date +%H:%M:%S)"
