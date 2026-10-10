import json
import os
import re
from collections import defaultdict
from pathlib import Path

import matplotlib
matplotlib.use("Agg")
import matplotlib.pyplot as plt

ROOT = Path(__file__).resolve().parent.parent
RESULTS = Path(os.environ.get("REASONING_RESULTS_DIR", ROOT / "results"))

SECURITY_WORDS = [
    "secure", "security", "safe", "safety", "valid", "validation", "validate",
    "bounds", "overflow", "sanitiz", "robust", "defensive", "memory", "check",
    "guard", "exception", "error handling", "edge case", "malicious", "injection"
]

CODE_DEFENSIVE_PATTERNS = {
    "Bounds check": r"if\s*\([^)]*(<|<=|>|>=)[^)]*\)\s*\{?\s*(return|throw|continue|break)",
    "Input validation": r"(cin\.fail|cin\.bad|std::cin\.fail|isdigit|std::isdigit)",
    "Exception handling": r"\b(try|catch|throw)\b",
    "Assert": r"\bassert\s*\(",
    "Overflow guard": r"(long long|int64_t|uint64_t|INT_MAX|LLONG_MAX|overflow)",
    "Null check": r"(nullptr|!= *NULL|== *NULL)",
}

# Display names for result files; unknown files fall back to the model tag.
LABELS = {
    "smollm2": "SmolLM2-360M",
    "qwen2505b": "Qwen2.5-0.5B",
    "qwen25coder15b": "Qwen2.5-Coder-1.5B",
    "qwen25coder3b": "Qwen2.5-Coder-3B",
    "qwen25coder7b": "Qwen2.5-Coder-7B",
    "deepcoder15b": "DeepCoder-1.5B",
    "opencoder15b": "OpenCoder-1.5B",
    "codegemma2b": "CodeGemma-2B",
}

MODELS = {
    LABELS.get(p.name.removesuffix("_reasoning.json"), p.name.removesuffix("_reasoning.json")): p
    for p in sorted(RESULTS.glob("*_reasoning.json"))
}


def load(path):
    with open(path) as f:
        return json.load(f)


def word_count(text, words):
    text_l = text.lower()
    return sum(len(re.findall(re.escape(w), text_l)) for w in words)


def compute_stats(data):
    by_cond = defaultdict(list)
    for d in data:
        by_cond[d["condition"]].append(d)

    stats = {}
    for cond in ("secure", "general"):
        items = by_cond[cond]
        n = len(items)
        n_code = sum(1 for d in items if d["code"].strip())
        avg_sec_words = sum(
            word_count(d.get("thinking", "") + " " + d["reasoning"], SECURITY_WORDS)
            for d in items
        ) / n
        truncated = sum(1 for d in items if d.get("truncated"))

        pattern_rates = {}
        code_items = [d for d in items if d["code"].strip()]
        for pname, pattern in CODE_DEFENSIVE_PATTERNS.items():
            hits = sum(1 for d in code_items if re.search(pattern, d["code"]))
            pattern_rates[pname] = hits / len(code_items) if code_items else 0.0

        stats[cond] = {
            "n": n,
            "success_rate": n_code / n,
            "truncation_rate": truncated / n,
            "avg_security_words": avg_sec_words,
            "pattern_rates": pattern_rates,
        }
    return stats


all_stats = {name: compute_stats(load(path)) for name, path in MODELS.items()}

# ------------------------------------------------------------------
# LaTeX table: completion rate + security-vocab density
# ------------------------------------------------------------------
print("=" * 70)
print("LaTeX table: completion rate and security-vocabulary density")
print("=" * 70)
latex = []
latex.append(r"\begin{table}[t]")
latex.append(r"  \centering")
latex.append(r"  \caption{Code-completion success rate and mean security-related")
latex.append(r"           word count in verbalized reasoning, by model and prompt condition.}")
latex.append(r"  \label{tab:reasoning-vocab}")
latex.append(r"  \begin{tabular}{lccc}")
latex.append(r"    \toprule")
latex.append(r"    Model & Condition & Completion rate & Security words \\")
latex.append(r"    \midrule")
for model_name, stats in all_stats.items():
    for cond in ("secure", "general"):
        s = stats[cond]
        latex.append(
            f"    {model_name} & {cond.capitalize()} & "
            f"{s['success_rate']*100:.0f}\\% & {s['avg_security_words']:.2f} \\\\"
        )
latex.append(r"    \bottomrule")
latex.append(r"  \end{tabular}")
latex.append(r"\end{table}")
print("\n".join(latex))

out_tex = RESULTS / "reasoning_vocab_table.tex"
out_tex.write_text("\n".join(latex), encoding="utf-8")
print(f"\n[INFO] LaTeX table saved to {out_tex}")

# ------------------------------------------------------------------
# Figure 1: security-vocabulary density, secure vs general, both models
# ------------------------------------------------------------------
fig, ax = plt.subplots(figsize=(max(5, 1.6 * len(all_stats)), 3.4))
model_names = list(all_stats.keys())
x = range(len(model_names))
width = 0.35

secure_vals = [all_stats[m]["secure"]["avg_security_words"] for m in model_names]
general_vals = [all_stats[m]["general"]["avg_security_words"] for m in model_names]

ax.bar([i - width / 2 for i in x], secure_vals, width, label="Secure header")
ax.bar([i + width / 2 for i in x], general_vals, width, label="General header")
ax.set_xticks(list(x))
ax.set_xticklabels(model_names, rotation=20, ha="right")
ax.set_ylabel("Mean security words / reasoning")
ax.set_title("Security-vocabulary density in verbalized reasoning")
ax.legend()
fig.tight_layout()
fig.savefig(RESULTS / "reasoning_security_vocab.pdf")
print(f"[INFO] Saved {RESULTS / 'reasoning_security_vocab.pdf'}")

# ------------------------------------------------------------------
# Figure 2: defensive code-pattern hit rate, secure vs general, both models
# ------------------------------------------------------------------
fig, axes = plt.subplots(1, len(all_stats), figsize=(4.5 * len(all_stats), 3.2),
                         sharey=True, squeeze=False)
axes = axes[0]
pattern_names = list(CODE_DEFENSIVE_PATTERNS.keys())

for ax, model_name in zip(axes, model_names):
    stats = all_stats[model_name]
    y = range(len(pattern_names))
    secure_rates = [stats["secure"]["pattern_rates"][p] * 100 for p in pattern_names]
    general_rates = [stats["general"]["pattern_rates"][p] * 100 for p in pattern_names]

    ax.barh([i + 0.2 for i in y], secure_rates, height=0.4, label="Secure")
    ax.barh([i - 0.2 for i in y], general_rates, height=0.4, label="General")
    ax.set_yticks(list(y))
    ax.set_yticklabels(pattern_names)
    ax.set_xlabel("% of generated code samples")
    ax.set_title(model_name)
    ax.set_xlim(0, 100)

axes[0].legend(loc="lower right")
fig.suptitle("Defensive code patterns present in generated C++")
fig.tight_layout()
fig.savefig(RESULTS / "reasoning_defensive_patterns.pdf")
print(f"[INFO] Saved {RESULTS / 'reasoning_defensive_patterns.pdf'}")

# ------------------------------------------------------------------
# Failure-mode summary (computed from the records)
# ------------------------------------------------------------------
print()
print("=" * 70)
print("Failure-mode summary")
print("=" * 70)
print(f"{'model':22s} {'cond':8s} {'n':>4s} {'code%':>6s} {'trunc%':>7s}")
for model_name, stats in all_stats.items():
    for cond in ("secure", "general"):
        st = stats[cond]
        print(f"{model_name:22s} {cond:8s} {st['n']:4d} "
              f"{st['success_rate']*100:6.0f} {st['truncation_rate']*100:7.0f}")
