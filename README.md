# req-to-code-reasoning

Code and scripts for a study of small language models generating C++ from software requirements. The models plan the functions for a requirements section, then write each function with a short rationale. Each section is run under a general and a secure prompt. The scripts compare the rationales, the code, and what a compiler-feedback repair loop recovers.

Run everything from the repository root. The scripts resolve paths from their own location.

## Requirements

- Python 3 with `requests`, `numpy`, `matplotlib`
- [Ollama](https://ollama.com) serving the models in `scripts/models.json`
- `g++` with C++17 (compile check) and `cppcheck` (static analysis in `verify.py`)
- ESBMC 8.0.0 is optional. `verify.py` writes `not_installed` in that column when it is missing, and `ESBMC_DIR=/path/to/esbmc/bin bash scripts/run_esbmc.sh` fills it in for the chosen rounds.

## Data

`data/requirements-xml/` holds the XML versions of the PURE requirements corpus (Ferrari et al., RE 2017). The study uses 11 of its 18 documents, chosen to balance company or public-body sources (I) and university sources (U) while keeping runs feasible on one laptop GPU. `data/requirements_units.jsonl` holds the 166 requirement sections derived from them, with one JSON object per section (`req_extract.py` builds it).

## Models

Four instruction-capable code models are analysed: Qwen2.5-Coder 1.5B and 3B, OpenCoder 1.5B and DeepCoder 1.5B. `scripts/models.json` also lists CodeGemma 2B. It fails the JSON plan/implement format (about 60% invalid plans, no usable sections), so `reasoning_analysis.py` excludes it by default (`--include-all` keeps it) and the repair scripts do not run it. Each model has its own token budget, context size and temperature in `models.json`. First-generation runs are greedy (temperature 0, seed 0); DeepCoder uses 0.6 because greedy decoding loops on it.

## Workflow

### 1. Generate (round R0)

For each section, one plan call returns up to five functions (name, signature, purpose) and shared declarations. One function call per planned function then returns JSON with 3 to 6 reasoning steps and the code. `--variant baseline` is the general prompt and `--variant secure_prompt` is the secure one.

```bash
python scripts/gen_functions.py --model qwen2.5-coder:3b --variant baseline --doc keepass
python scripts/gen_functions.py --model qwen2.5-coder:3b --variant secure_prompt --doc keepass
python scripts/migrate_r0.py        # results/generation/... -> results/runs/R0/<arm>__<model>/s0/
python scripts/verify.py --round R0 # compile check, cppcheck, ESBMC if installed
```

Runs are resumable. Each unit is skipped once it appears in `units.jsonl`. A run directory holds `records.jsonl` (one line per function, with reasoning and code), `units.jsonl` (plan, status, errors), `code/<unit>.cpp` and `manifest.json`.

### 2. Repair rounds

`repair.py` reads a stored round and writes a full snapshot of the next one under `results/runs/<round>/`.

```bash
bash scripts/run_compile_repair.sh   # R0 -> C1 -> C2, compile repair for the paper's models
bash scripts/run_rounds.sh           # R0 -> C1 -> C2 -> S1 -> S2, verify after each, then metrics
python scripts/repair.py --parent R0 --round C1 --kind compile --model qwen25coder3b --limit 5
```

- Compile repair (`C1`, `C2`) covers sections that are not usable. A function with compiler errors gets the errors (line numbers relative to the function) and its code. A missing or empty function gets the original implement prompt. A section with no plan is planned again.
- Security repair (`S1`, `S2`) covers usable sections with cppcheck findings. Each flagged function gets "Secure it." with its code. A repair that stops a section compiling, or removes a function body, is reverted.
- Repair calls use temperature 0.2 with seeds derived from section, prompt, round and function.

### 3. Analyse

| Script | Output |
|---|---|
| `reasoning_analysis.py` | Content tags, echo of the secure prompt, form measures and requirement relevance of the reasoning steps (RQ1, RQ2) and follow-through of promised checks in code (RQ4). Reasoning is capped at the first six steps per function. |
| `stub_analysis.py` | Classes of function bodies: empty, output or trivial only, placeholder, minimal, logic (RQ3). |
| `repair_analysis.py` | Compiles, usable and stub shares per round and prompt, with bootstrap intervals over sections (RQ5). |
| `metrics.py` | compile@k, usable@k, secure@k, arm differences and round transitions from `verify.py` output. |
| `robustness_docs.py` | Leave-one-document-out check of the two headline results. |
| `source_split.py` | Headline results split by PURE source tag (I or U). |
| `run_esbmc.sh`, `esbmc_analysis.py` | ESBMC (bounded model checking) of usable sections, one function at a time, per round. `esbmc_analysis.py` writes verdict counts, violated properties, the location of each violation (generated code or ESBMC's library models) and the first frontend error of unsupported functions to `results/esbmc/`. Tested with ESBMC 8.0.0. |
| `recompile.py` | Compile results with and without the extra standard headers added by `gen_functions.py`. |

Rates are reported as pooled secure-minus-general differences with 95% percentile bootstrap intervals that resample requirement sections.

### 4. Human labels

The tags and classes above are lexical heuristics. `label_functions.py` draws blind samples for hand labelling: 150 reasoning steps and 100 functions (20 per heuristic class). The sheets are written to `results/labels/`. Model, prompt and automatic label are in separate key files that annotators must not open. The full protocol for two annotators is in `docs/labeling_guideline.md`. `label_agreement.py` computes agreement between the annotators and checks the automatic labels against the adjudicated ones. The older single-sheet check is:

```bash
python scripts/label_functions.py --per-class 20
python scripts/label_functions.py --agreement results/labels/function_sheet_filled.csv
```

## Docker

```bash
docker build -f docker/Dockerfile -t reasoning-pipeline .
docker run --rm --gpus all \
  -v ollama_models:/root/.ollama -v "$PWD/results:/app/results" -v "$PWD/generated_code:/app/generated_code" \
  reasoning-pipeline --doc keepass
```

The image bundles the Ollama server, `g++` and the Python dependencies, and container arguments go to `scripts/pipeline.py`. That script is the earlier single-stage pipeline (one reasoning-plus-code call per problem, `--stages pull generate analyze`). The plan, repair and verification workflow above is not in the image, and `cppcheck` is not installed there. `--gpus all` needs the NVIDIA Container Toolkit on the host. `docker/docker-compose.yml` does the same with `docker compose up`.

## Layout

| Path | Contents |
|---|---|
| `scripts/` | Generation, repair, verification, analysis and labelling scripts, `models.json`, and the shell drivers |
| `docker/` | Dockerfile, entrypoint, compose file |
| `data/` | `requirements-xml/` (PURE XML), `requirements_units.jsonl` (derived sections) |
| `results/` | Runs, metrics, figures and label sheets. Gitignored, regenerated by the scripts. |
| `generated_code/ollama/` | C++ from the earlier single-stage pipeline |
