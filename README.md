# mechanistic-analysis-llm

Reasoning-level analysis of LLM code generation: what small models say when prompted to reason before writing C++ under secure vs. general prompts.

Run the pipeline from the repository root; the scripts resolve paths from their own location.

## Pipeline

Requirements specifications (`data/requirements-xml`) to C++ code, per model and prompt variant. Models are listed in `scripts/models.json` (Qwen2.5-Coder 1.5B and 3B, DeepCoder 1.5B, OpenCoder 1.5B, CodeGemma 2B), each with its own token budget, context size and temperature.

```bash
python scripts/pipeline.py                                  # pull, run, analyze
python scripts/pipeline.py --models deepcoder:1.5b --samples 3
python scripts/pipeline.py --limit 1 --stages run           # smoke test
python scripts/pipeline.py --stages analyze                 # figures and table only
```

Runs resume from `results/<tag>_reasoning.json`. Each record stores the verbalized reasoning, the native `<think>` trace (`thinking`), the code, `done_reason`, `truncated`, token count and wall time.

## Docker

```bash
docker build -f docker/Dockerfile -t reasoning-pipeline .
docker run --rm --gpus all \
  -v ollama_models:/root/.ollama -v "$PWD/results:/app/results" -v "$PWD/generated_code:/app/generated_code" \
  reasoning-pipeline --doc keepass
```

The image bundles the Ollama server and the Python pipeline; container arguments go to `pipeline.py`. `--gpus all` needs the NVIDIA Container Toolkit on the host. `docker/docker-compose.yml` does the same with `docker compose up`.

| Directory | Contents |
|---|---|
| `scripts/` | `pipeline.py` (pull, run, analyze), `models.json`, `ollama_reasoning.py` (collect reasoning + code via Ollama), `analyze_reasoning_patterns.py` (vocabulary/pattern analysis, figures), `req_extract.py` and `gen_functions.py` (requirements to per-function generation) |
| `docker/` | Dockerfile, entrypoint, compose file |
| `data/` | Problem sets (`*.json`), requirements (`requirements/`, `requirements-xml/`), derived `requirements_units.jsonl`; original archives in `data/raw/` |
| `results/` | `*_reasoning.json`, reasoning figures and vocabulary table, `generation/` runs (gitignored) |
| `generated_code/ollama/` | C++ produced by `ollama_reasoning.py` |
| `slides/` | Presentation of reasoning findings |
| `docs/papers/` | Reference papers and the VulBench-CPP draft |
| `docs/notes/` | Project status and working notes |
| `archive/residual_stream/` | Earlier residual-stream / teacher-forcing work (TransformerLens scripts, notebooks, report, results, generated code). Not part of the current project; kept for reference. Its `../data` paths were rewritten to `../../../data` |
