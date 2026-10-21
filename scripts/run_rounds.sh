#!/usr/bin/env bash
# R0 -> C1 -> C2 (compile repair) -> S1 -> S2 (security repair), verify after each, then metrics.
# Needs the Ollama server and results/runs/R0 already verified (python3 scripts/verify.py).
#   bash scripts/run_rounds.sh [extra repair.py args, e.g. --model qwen25coder3b]
set -euo pipefail
cd "$(dirname "$0")/.."
extra=("$@")
step() { echo "=== $1 <- $2 ($3) $(date +%H:%M:%S)"; python3 scripts/repair.py --parent "$2" --round "$1" --kind "$3" --verify "${extra[@]}"; }
step C1 R0 compile
step C2 C1 compile
step S1 C2 secure
step S2 S1 secure
python3 scripts/metrics.py --k 1
echo "=== all rounds done $(date +%H:%M:%S)"
