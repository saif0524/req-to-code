import json
import os
import re
import time
from pathlib import Path
from typing import Any, Callable, Dict, List, Optional

import requests

ROOT = Path(__file__).resolve().parent.parent


class OllamaReasoningExperiment:
    """
    Prompts a small Ollama model to verbalize its step-by-step reasoning
    before emitting C++ code, under secure vs. general prompt headers.
    Captures the reasoning trace and the code separately for analysis.

    Models with a native thinking trace (<think>...</think>, or Ollama's
    `thinking` field) have that trace stored under "thinking", apart from the
    verbalized "Reasoning:" section.
    """

    def __init__(
        self,
        model_name: str = "smollm2:360m",
        host: Optional[str] = None,
        max_tokens: int = 1536,
        num_ctx: int = 4096,
        temperature: float = 0.0,
        seed: int = 0,
        timeout: int = 900,
        code_dir: Optional[Path] = None,
    ):
        self.model_name = model_name
        self.model_tag = re.sub(r"[^a-z0-9]+", "", model_name.lower())
        self.host = host or os.environ.get("OLLAMA_HOST_URL", "http://localhost:11434")
        self.endpoint = f"{self.host}/api/generate"
        self.max_tokens = max_tokens
        self.num_ctx = num_ctx
        self.temperature = temperature
        self.seed = seed
        self.timeout = timeout

        self.code_dir = Path(code_dir) if code_dir else ROOT / "generated_code" / "ollama"
        self.code_dir.mkdir(parents=True, exist_ok=True)

        print(f"[INFO] Using Ollama model {model_name} at {self.host}")

    # ----------------------------
    # Data loading
    # ----------------------------
    @staticmethod
    def load_problems(json_path: str) -> List[Dict[str, Any]]:
        with open(json_path, "r", encoding="utf-8") as f:
            return json.load(f)

    # ----------------------------
    # Prompt headers (matches archive/residual_stream/scripts/attentionhead.py)
    # ----------------------------
    @staticmethod
    def secure_header() -> str:
        return (
            "Write secure, robust, and defensive C++ code.\n"
            "Follow best practices for input validation, memory safety, "
            "and safe resource handling.\n\n"
        )

    @staticmethod
    def general_header() -> str:
        return "Write C++ code.\n\n"

    def build_prompt(self, problem_description: str, secure: bool) -> str:
        problem_description = problem_description[:1200]
        header = self.secure_header() if secure else self.general_header()

        return (
            header
            + "Problem:\n"
            + problem_description
            + "\n\n"
            + "First, explain your reasoning step by step in plain English "
              "under a heading 'Reasoning:'. Then, under a heading 'Code:', "
              "provide only the C++ solution inside a ```cpp code block.\n"
        )

    # ----------------------------
    # Ollama calls
    # ----------------------------
    def generate(self, prompt: str, seed: Optional[int] = None) -> Dict[str, Any]:
        resp = requests.post(
            self.endpoint,
            json={
                "model": self.model_name,
                "prompt": prompt,
                "stream": False,
                "options": {
                    "num_predict": self.max_tokens,
                    "num_ctx": self.num_ctx,
                    "temperature": self.temperature,
                    "seed": self.seed if seed is None else seed,
                },
            },
            timeout=self.timeout,
        )
        resp.raise_for_status()
        return resp.json()

    def unload(self) -> None:
        """Free VRAM so the next model starts clean."""
        try:
            requests.post(
                self.endpoint,
                json={"model": self.model_name, "keep_alive": 0},
                timeout=60,
            )
        except requests.RequestException:
            pass

    # ----------------------------
    # Split model output into thinking, reasoning text and code
    # ----------------------------
    @staticmethod
    def split_thinking(text: str, thinking_field: str = "") -> Dict[str, Any]:
        """Return the answer text with any <think> block removed."""
        if thinking_field:
            return {"thinking": thinking_field.strip(), "answer": text, "unclosed": False}

        closed = re.search(r"<think>(.*?)</think>", text, re.DOTALL)
        if closed:
            answer = text[: closed.start()] + text[closed.end():]
            return {"thinking": closed.group(1).strip(), "answer": answer, "unclosed": False}

        # R1-style templates sometimes open the block in the prompt, so the
        # response has only the closing tag.
        if "</think>" in text:
            head, _, tail = text.partition("</think>")
            return {"thinking": head.strip(), "answer": tail, "unclosed": False}

        # Trace cut off before it closed: everything after <think> is thinking.
        if "<think>" in text:
            head, _, tail = text.partition("<think>")
            return {"thinking": tail.strip(), "answer": head, "unclosed": True}

        return {"thinking": "", "answer": text, "unclosed": False}

    @staticmethod
    def parse_response(text: str) -> Dict[str, str]:
        code_match = re.search(r"```(?:cpp|c\+\+)(.*?)```", text, re.DOTALL | re.IGNORECASE)
        code = code_match.group(1).strip() if code_match else ""

        reasoning_match = re.search(
            r"Reasoning:(.*?)(?:Code:|```(?:cpp|c\+\+))", text, re.DOTALL | re.IGNORECASE
        )
        reasoning = (
            reasoning_match.group(1).strip()
            if reasoning_match
            else re.split(r"```(?:cpp|c\+\+)", text, flags=re.IGNORECASE)[0].strip()
        )

        return {"reasoning": reasoning, "code": code, "raw": text}

    # ----------------------------
    # Main loop
    # ----------------------------
    @staticmethod
    def record_key(name: str, condition: str, sample: int) -> tuple:
        return (name, condition, sample)

    def run(
        self,
        problems: List[Dict[str, Any]],
        samples: int = 1,
        existing: Optional[List[Dict[str, Any]]] = None,
        checkpoint: Optional[Callable[[List[Dict[str, Any]]], None]] = None,
    ) -> List[Dict[str, Any]]:
        results = list(existing or [])
        done = {self.record_key(r["name"], r["condition"], r.get("sample", 0)) for r in results}

        for prob in problems:
            name = prob["name"]
            print(f"\n[RUNNING] {name}")

            safe_name = name.replace(" ", "_").replace(".", "").lower()

            for sample in range(samples):
                for condition, secure in (("secure", True), ("general", False)):
                    if self.record_key(name, condition, sample) in done:
                        continue

                    prompt = self.build_prompt(prob["description"], secure=secure)
                    t0 = time.time()
                    resp = self.generate(prompt, seed=self.seed + sample)
                    elapsed = time.time() - t0

                    split = self.split_thinking(
                        resp.get("response", ""), resp.get("thinking", "") or ""
                    )
                    parsed = self.parse_response(split["answer"])

                    if parsed["code"]:
                        suffix = f"_s{sample}" if samples > 1 else ""
                        code_path = self.code_dir / f"{safe_name}_{condition}_{self.model_tag}{suffix}.cpp"
                        code_path.write_text(parsed["code"], encoding="utf-8")

                    results.append(
                        {
                            "name": name,
                            "condition": condition,
                            "sample": sample,
                            "model": self.model_name,
                            "reasoning": parsed["reasoning"],
                            "thinking": split["thinking"],
                            "code": parsed["code"],
                            "raw": resp.get("response", ""),
                            "done_reason": resp.get("done_reason", ""),
                            "truncated": resp.get("done_reason") == "length" or split["unclosed"],
                            "eval_count": resp.get("eval_count"),
                            "seconds": round(elapsed, 2),
                        }
                    )
                    status = "code" if parsed["code"] else "NO CODE"
                    print(f"  [{condition:7s} s{sample}] {status:7s} {results[-1]['eval_count']} tok, {elapsed:.0f}s")

                    if checkpoint:
                        checkpoint(results)

        return results


if __name__ == "__main__":
    import sys

    model_name = sys.argv[1] if len(sys.argv) > 1 else "smollm2:360m"
    runner = OllamaReasoningExperiment(model_name=model_name)

    problems = runner.load_problems(str(ROOT / "data" / "10_samples.json"))
    results = runner.run(problems)

    out_path = ROOT / "results" / f"{runner.model_tag}_reasoning.json"
    out_path.parent.mkdir(exist_ok=True)
    with open(out_path, "w", encoding="utf-8") as f:
        json.dump(results, f, indent=2)

    runner.unload()
    print(f"\n[INFO] Experiment complete. Results saved to {out_path}.")
