#!/usr/bin/env bash
# Start the Ollama server, wait for it, then run scripts/pipeline.py with the
# container arguments (e.g. --models deepcoder:1.5b --samples 3).
set -euo pipefail

ollama serve > /tmp/ollama.log 2>&1 &
SERVER_PID=$!
trap 'kill "$SERVER_PID" 2>/dev/null || true' EXIT

for _ in $(seq 1 60); do
  if python3 -c "import requests; requests.get('${OLLAMA_HOST_URL}/api/version', timeout=2).raise_for_status()" 2>/dev/null; then
    break
  fi
  sleep 1
done

python3 /app/scripts/pipeline.py "$@"
