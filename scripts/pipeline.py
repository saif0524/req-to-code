"""
End-to-end reasoning pipeline: pull models, collect reasoning + code under
secure/general prompts, then run the analysis.

    python scripts/pipeline.py                      # pull + requirements -> code, keepass, both variants
    python scripts/pipeline.py --models deepcoder:1.5b --variants baseline
    python scripts/pipeline.py --doc tcs --limit 3  # another document, first 3 units
    python scripts/pipeline.py --stages run analyze # Codeforces demo (needs data/10_samples.json)

Runs are resumable: finished (problem, condition, sample) records are kept in
results/<model_tag>_reasoning.json and skipped on the next run.
"""
import argparse
import json
import os
import subprocess
import sys
from pathlib import Path

import requests

sys.path.insert(0, str(Path(__file__).resolve().parent))
from ollama_reasoning import OllamaReasoningExperiment, ROOT  # noqa: E402

HOST = os.environ.get("OLLAMA_HOST_URL", "http://localhost:11434")


def wait_for_server(timeout: int = 120) -> None:
    import time

    deadline = time.time() + timeout
    while time.time() < deadline:
        try:
            requests.get(f"{HOST}/api/version", timeout=2).raise_for_status()
            return
        except requests.RequestException:
            time.sleep(1)
    sys.exit(f"[ERROR] Ollama server not reachable at {HOST}")


def installed_models() -> set:
    resp = requests.get(f"{HOST}/api/tags", timeout=10)
    resp.raise_for_status()
    return {m["name"] for m in resp.json().get("models", [])}


def pull(tag: str) -> None:
    have = installed_models()
    if tag in have or f"{tag}:latest" in have:
        print(f"[PULL] {tag} already present")
        return
    print(f"[PULL] {tag}")
    with requests.post(
        f"{HOST}/api/pull", json={"model": tag, "stream": True}, stream=True, timeout=None
    ) as r:
        r.raise_for_status()
        last = ""
        for line in r.iter_lines():
            if not line:
                continue
            msg = json.loads(line)
            if "error" in msg:
                sys.exit(f"[ERROR] pulling {tag}: {msg['error']}")
            status = msg.get("status", "")
            if status != last:
                print(f"  {status}")
                last = status


def run_model(cfg: dict, problems: list, samples: int, results_dir: Path,
              code_dir: Path, force: bool) -> None:
    runner = OllamaReasoningExperiment(
        model_name=cfg["tag"],
        max_tokens=cfg.get("max_tokens", 1536),
        num_ctx=cfg.get("num_ctx", 4096),
        temperature=cfg.get("temperature", 0.0),
        code_dir=code_dir,
    )
    out_path = results_dir / f"{runner.model_tag}_reasoning.json"

    existing = []
    if out_path.exists() and not force:
        existing = json.loads(out_path.read_text(encoding="utf-8"))
        print(f"[RESUME] {len(existing)} records already in {out_path.name}")

    def checkpoint(records):
        out_path.write_text(json.dumps(records, indent=2), encoding="utf-8")

    records = runner.run(problems, samples=samples, existing=existing, checkpoint=checkpoint)
    checkpoint(records)
    runner.unload()
    print(f"[DONE] {cfg['tag']}: {len(records)} records -> {out_path}")


def generate(cfg: dict, doc: str, variants: list, limit: int) -> None:
    """Requirement-to-function generation (gen_functions.py) for one model."""
    for variant in variants:
        cmd = [
            sys.executable, str(ROOT / "scripts" / "gen_functions.py"),
            "--model", cfg["tag"], "--variant", variant, "--doc", doc,
            "--num-ctx", str(cfg.get("num_ctx", 4096)),
            "--num-predict", str(cfg.get("max_tokens", 1536)),
            "--host", HOST,
        ]
        if limit:
            cmd += ["--limit", str(limit)]
        print(f"[GENERATE] {cfg['tag']} / {variant} / {doc}")
        subprocess.run(cmd, check=True)
    OllamaReasoningExperiment(model_name=cfg["tag"]).unload()


def main() -> None:
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawTextHelpFormatter)
    ap.add_argument("--config", default=str(ROOT / "scripts" / "models.json"))
    ap.add_argument("--models", nargs="*", help="subset of tags from the config")
    ap.add_argument("--problems", default=str(ROOT / "data" / "10_samples.json"))
    ap.add_argument("--limit", type=int, help="only the first N problems (smoke test)")
    ap.add_argument("--samples", type=int, default=1, help="samples per problem and condition")
    ap.add_argument("--results-dir", default=str(ROOT / "results"))
    ap.add_argument("--code-dir", default=str(ROOT / "generated_code" / "ollama"))
    ap.add_argument("--stages", nargs="+", default=["pull", "generate"],
                    choices=["pull", "run", "analyze", "generate"])
    ap.add_argument("--doc", default="keepass", help="requirements document (generate stage)")
    ap.add_argument("--variants", nargs="+", default=["baseline", "secure_prompt"],
                    choices=["baseline", "secure_prompt"])
    ap.add_argument("--force", action="store_true", help="ignore existing results")
    args = ap.parse_args()

    models = json.loads(Path(args.config).read_text(encoding="utf-8"))
    if args.models:
        unknown = set(args.models) - {m["tag"] for m in models}
        if unknown:
            sys.exit(f"[ERROR] not in config: {', '.join(sorted(unknown))}")
        models = [m for m in models if m["tag"] in args.models]

    results_dir = Path(args.results_dir)
    results_dir.mkdir(parents=True, exist_ok=True)

    if {"pull", "run", "generate"} & set(args.stages):
        wait_for_server()

    problems = []
    if "run" in args.stages:  # the Codeforces demo set; not used for requirements generation
        problems = OllamaReasoningExperiment.load_problems(args.problems)
        if args.limit:
            problems = problems[: args.limit]

    for cfg in models:
        if "pull" in args.stages:
            pull(cfg["tag"])
        if "run" in args.stages:
            run_model(cfg, problems, args.samples, results_dir, Path(args.code_dir), args.force)
        if "generate" in args.stages:
            generate(cfg, args.doc, args.variants, args.limit)

    if "analyze" in args.stages:
        env = dict(os.environ, REASONING_RESULTS_DIR=str(results_dir))
        subprocess.run(
            [sys.executable, str(ROOT / "scripts" / "analyze_reasoning_patterns.py")],
            check=True, env=env,
        )


if __name__ == "__main__":
    main()
