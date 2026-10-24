# SLM Reasoning for code generation

## Setup

### Docker (recommended)

The image holds Python 3, g++ 13, cppcheck 2.19.0 and ESBMC 8.0. Ollama runs as a second service.

```bash
docker compose -f docker/docker-compose.yml up -d ollama
for m in qwen2.5-coder:1.5b qwen2.5-coder:3b opencoder:1.5b deepcoder:1.5b; do
  docker compose -f docker/docker-compose.yml exec ollama ollama pull $m
done
docker compose -f docker/docker-compose.yml run --rm tools bash
```

Run the commands below inside the `tools` shell. Results are written to `./results` on the host. Remove `gpus: all` from the compose file if the host has no GPU.

### Local

Python 3 with `requests`, `numpy`, `matplotlib`, `lxml`; `g++` with C++17; `cppcheck` 2.19.0; ESBMC 8.0.0; Ollama on `localhost:11434` with the four models above pulled. Run every command from the repository root.

## Data

`data/requirements_units.jsonl` holds the 166 requirement sections from the 11 PURE documents in `data/requirements-xml/`. Use it as provided.

## 1. First generation (R0)

```bash
for v in baseline secure_prompt; do      # baseline is the general prompt
  for m in qwen2.5-coder:1.5b qwen2.5-coder:3b opencoder:1.5b; do
    python3 scripts/gen_functions.py --model $m --variant $v --num-ctx 4096 --num-predict 1536
  done
  python3 scripts/gen_functions.py --model deepcoder:1.5b --variant $v --num-ctx 12288 --num-predict 8192
done
python3 scripts/migrate_r0.py            # results/generation/ -> results/runs/R0/<prompt>__<model>/s0/
python3 scripts/verify.py --round R0 --no-esbmc
```

Greedy decoding (temperature 0, seed 0). Runs resume where they stopped.

## 2. Compile repair (C1, C2)

```bash
bash scripts/run_compile_repair.sh       # C1 and C2 for Qwen 1.5B, Qwen 3B and OpenCoder; C1 for DeepCoder
python3 scripts/repair.py --parent C1 --round C2 --kind compile --model deepcoder15b
python3 scripts/verify.py --round C2 --no-esbmc
```

Each round reads its parent and writes a full snapshot to `results/runs/<round>/<prompt>__<model>/s0/`.

## 3. cppcheck

```bash
bash scripts/run_cppcheck.sh R0 C1 C2
```

Output: `results/cppcheck/`.

## 4. ESBMC

```bash
bash scripts/run_esbmc.sh R0 C1 C2       # ESBMC_DIR=/path/to/esbmc/bin if esbmc is not on PATH
python3 scripts/esbmc_analysis.py --rounds R0 C1 C2 --causes --locate
```

Output: `results/esbmc/`.

## 5. Analysis

```bash
python3 scripts/reasoning_analysis.py
python3 scripts/stub_analysis.py
python3 scripts/repair_analysis.py
python3 scripts/robustness_docs.py
python3 scripts/source_split.py
python3 scripts/metrics.py --k 1
```

Output: `results/`.

## 6. Human labels

```bash
python3 scripts/label_functions.py --per-class 20
python3 scripts/label_agreement.py steps A_steps.csv B_steps.csv --skip 10
python3 scripts/label_agreement.py functions A_functions.csv B_functions.csv --skip 10
python3 scripts/label_agreement.py steps --truth adjudicated_steps.csv
python3 scripts/label_agreement.py functions --truth adjudicated_functions.csv
```

Blind sheets are written to `results/labels/`. The protocol is in `docs/labeling_guideline.md`.
