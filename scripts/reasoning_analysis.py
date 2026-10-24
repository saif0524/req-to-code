"""
How does secure phrasing change the reasoning a model writes before its code?

Data: results/runs/R0/<arm>__<model>/s0/records.jsonl (per-function reasoning steps), the
requirement text in data/requirements_units.jsonl. Unit of analysis: a (model, requirement
unit) pair that has reasoning in both arms. Each arm planned its own functions, so arms are
compared on rates per step or per function inside the pair, never on raw counts.

  RQ1  amount and content   share of steps in each security category, with and without
                            the phrases copied from the secure header (echo)
  RQ2  form                 words per step, steps per function, hedging, obligation,
                            conditionals, concrete code references, first person
  RQ3  task dependence      the RQ1 shift for requirements with and without security-relevant text
  RQ4  model dependence     the RQ1 shift per model
  RQ5  follow-through       when the reasoning mentions a check, does the function's code contain one

Categories are phrase patterns (CATEGORIES). They are a measuring instrument and need checking:
--label-sheet writes a blind sample of steps to hand-label, --agreement scores the labels.

Intervals are percentile bootstraps over requirement units (all models of a unit move together).

    python3 scripts/reasoning_analysis.py
    python3 scripts/reasoning_analysis.py --label-sheet 200
    python3 scripts/reasoning_analysis.py --agreement results/reasoning/label_sheet_filled.csv
"""
import argparse
import csv
import json
import re
import sys
from collections import defaultdict
from pathlib import Path

import numpy as np

sys.path.insert(0, str(Path(__file__).resolve().parent))
from verify import code_has_body  # noqa: E402

ROOT = Path(__file__).resolve().parent.parent
RUNS = ROOT / "results" / "runs"
UNITS = ROOT / "data" / "requirements_units.jsonl"
OUT = ROOT / "results" / "reasoning"

# Wording the secure header gives the model; a step repeating it is echo, not independent reasoning.
ECHO = re.compile(r"input validation|memory safety|safe resource handling|resource handling|"
                  r"best practices|defensive|secure,? robust|robust,? and", re.I)

CATEGORIES = {
    "validation": r"\bvalidat\w*|\bsanitiz\w*|\binvalid\b|\bmalformed\b|\bwell-formed\b|"
                  r"\bverif(?:y|ies|ied|ication)\b|\bnon-empty\b|\bmust not be empty\b",
    "memory_resource": r"\bmemory\b|\bleak\w*|\bbuffer\w*|\boverflow\w*|\bunderflow\w*|\bnull(?:ptr)?\b|"
                       r"\bdangling\b|\bpointers?\b|\braii\b|\bbounds?\b|out[- ]of[- ]range|"
                       r"\bdealloc\w*|\bfree[sd]?\b|\bresources?\b",
    "error_handling": r"\berrors?\b|\bexceptions?\b|\bthrow\w*|\bcatch\w*|\bfail(?:s|ed|ure|ures|ing)?\b|"
                      r"\bgracefully\b|\bfallback\b|\bedge cases?\b|\brecover\w*",
    "threat": r"\binjection\b|\bxss\b|cross-site|\bmalicious\b|\battacks?\b|\bvulnerab\w*|\bexploit\w*|"
              r"\buntrusted\b|\bthreats?\b|\bsecurity\b|\bsecure[sd]?\b|\bsecurely\b|\bunauthori[sz]ed\b|"
              r"\bsafe(?:ly|ty)?\b|\bsafeguard\w*",
    "secrets_access": r"\bpasswords?\b|\bhash\w*|\bencrypt\w*|\bdecrypt\w*|\bcrypto\w*|\bauthenticat\w*|"
                      r"\bauthori[sz]\w*|\bpermissions?\b|\bcredentials?\b|\btokens?\b|\bsalt\w*|\bsecrets?\b|"
                      r"\bprivileg\w*|\baccess control\b",
    "prevention": r"\bavoid\w*|\bprevent\w*|\bensur\w*|\bguard\w*|\bprotect\w*|\bmake sure\b|"
                  r"\bguarantee\w*|\brobust\w*",
}
CAT_RE = {k: re.compile(v, re.I) for k, v in CATEGORIES.items()}
CORE = ("validation", "memory_resource", "threat", "prevention")  # error handling and secrets are often task-driven

FORM = {
    "hedge": r"\b(might|could|may|possibly|perhaps|probably|likely|potentially)\b",
    "obligation": r"\b(should|must|need to|needs to|have to|has to|required)\b",
    "conditional": r"\b(if|otherwise|unless|when|in case)\b",
    "first_person": r"\b(i|i'll|i'd|we|we'll|let's|our)\b",
    "concrete_ref": r"`[^`]+`|\b\w+\(\)|\b[a-z]+_[a-z_]+\b|\b[a-z]+[A-Z]\w+\b",
}
FORM_RE = {k: re.compile(v) if k == "concrete_ref" else re.compile(v, re.I) for k, v in FORM.items()}

SEC_REQ = re.compile(r"password|authenticat|authori[sz]|encrypt|permission|access control|privilege|"
                     r"credential|user input|validat|personal data|privacy|secur|audit|log ?in|session|"
                     r"network|database|\bkey\b|token|\bfile\b", re.I)

VALID_CODE = re.compile(r"\b(empty\(\)|size\(\)\s*[<>=!]|length\(\)\s*[<>=!]|nullptr|NULL|throw|catch|"
                        r"\.at\(|find\()|if\s*\([^)]*(<|<=|>|>=|==|!=)[^)]*\)\s*\{?\s*(return|throw)")
CHECK_STEP = re.compile(r"\bvalidat\w*|\bcheck(?:s|ing|ed)?\s+(?:that|if|whether|for)\b|\bverif\w*|\bensur\w*|"
                        r"\bnull\b|\bempty\b|\bbounds?\b|\binvalid\b|\bthrow\w*|\bexception\b", re.I)


def body(code):
    b = code[code.index("{") + 1: code.rindex("}")] if "}" in code else code[code.index("{") + 1:]
    return re.sub(r"//.*?$|/\*.*?\*/", "", b, flags=re.S | re.M)


def tag_step(text):
    ne = ECHO.sub(" ", text)
    tags = {k: bool(r.search(text)) for k, r in CAT_RE.items()}
    tags["echo"] = bool(ECHO.search(text))
    tags["sec_core"] = any(tags[k] for k in CORE)
    tags["sec_core_noecho"] = any(CAT_RE[k].search(ne) for k in CORE)
    # prevention over-flags in the hand check (ensure/avoid without a stated threat), so the core
    # shift is also reported without it
    tags["sec_core_noecho_noprev"] = any(CAT_RE[k].search(ne) for k in CORE if k != "prevention")
    for k, r in FORM_RE.items():
        tags[k] = bool(r.search(text))
    return tags


# CodeGemma 2B is a completion model and fails the JSON workflow (few plans, empty bodies); it is
# reported separately, not in this analysis. Pass --include-all to keep it.
EXCLUDE = {"codegemma2b"}
# The prompt asks for 3 to 6 steps. Under greedy decoding DeepCoder sometimes loops and writes
# hundreds; only the first MAX_STEPS steps of a function are analysed (0 = no cap, --max-steps).
MAX_STEPS = 6


def load_records():
    recs = []
    for d in sorted(RUNS.glob("R0/*__*/s0")):
        arm, model = d.parent.name.split("__", 1)
        if model in EXCLUDE:
            continue
        for l in (d / "records.jsonl").read_text(encoding="utf-8").splitlines():
            if l.strip():
                r = json.loads(l)
                r["arm"], r["model_dir"] = arm, model
                recs.append(r)
    return recs


def build_pairs(recs, units):
    """Aggregate to (model, unit, arm) counts; keep pairs with reasoning in both arms."""
    agg = defaultdict(lambda: defaultdict(float))
    steps_rows = []
    for r in recs:
        key = (r["model_dir"], r["unit_id"], r["arm"])
        a = agg[key]
        a["functions"] += 1
        has_body = code_has_body(r["code"])
        a["real_functions"] += has_body
        # follow-through is judged per function
        steps = (r.get("reasoning") or [])[:MAX_STEPS] if MAX_STEPS else (r.get("reasoning") or [])
        mentions = any(CHECK_STEP.search(s) for s in steps)
        if has_body and steps:
            has_check = bool(VALID_CODE.search(body(r["code"])))
            a["ft_mention"] += mentions
            a["ft_mention_check"] += mentions and has_check
            a["ft_nomention"] += not mentions
            a["ft_nomention_check"] += (not mentions) and has_check
        for i, s in enumerate(steps):
            t = tag_step(s)
            a["steps"] += 1
            a["words"] += len(s.split())
            for k, v in t.items():
                a[k] += v
            steps_rows.append({"model": r["model_dir"], "arm": r["arm"], "unit_id": r["unit_id"],
                               "func": r["name"], "step_idx": i, "text": s, **{k: int(v) for k, v in t.items()}})
    pairs = []
    for (m, u), _ in {(m, u): 1 for (m, u, _a) in agg}.items():
        g, s = agg.get((m, u, "general")), agg.get((m, u, "secure"))
        if g and s and g["steps"] and s["steps"]:
            hits = len(set(x.lower() for x in SEC_REQ.findall(units.get(u, {}).get("text", ""))))
            pairs.append({"model": m, "unit": u, "g": g, "s": s, "req_hits": hits})
    return pairs, steps_rows


METRICS = {  # name: (numerator key, denominator key)
    **{f"cat_{k}": (k, "steps") for k in CATEGORIES},
    "sec_core": ("sec_core", "steps"), "sec_core_noecho": ("sec_core_noecho", "steps"),
    "sec_core_noecho_noprev": ("sec_core_noecho_noprev", "steps"),
    "echo": ("echo", "steps"),
    "words_per_step": ("words", "steps"), "steps_per_function": ("steps", "functions"),
    **{k: (k, "steps") for k in FORM},
}


def estimate(pairs, metric, boot, rng, unit_index, idx_boot):
    nk, dk = METRICS[metric]
    ng = np.array([p["g"][nk] for p in pairs]); dg = np.array([p["g"][dk] for p in pairs])
    ns = np.array([p["s"][nk] for p in pairs]); ds = np.array([p["s"][dk] for p in pairs])
    ui = np.array([unit_index[p["unit"]] for p in pairs])
    base = ns.sum() / ds.sum() - ng.sum() / dg.sum()
    diffs = np.empty(len(idx_boot))
    for b, w in enumerate(idx_boot):
        wp = w[ui]
        diffs[b] = (wp * ns).sum() / max((wp * ds).sum(), 1e-9) - (wp * ng).sum() / max((wp * dg).sum(), 1e-9)
    lo, hi = np.percentile(diffs, [2.5, 97.5])
    return ng.sum() / dg.sum(), ns.sum() / ds.sum(), base, lo, hi, diffs, ng / dg, ns / ds


def write_csv(path, rows):
    OUT.mkdir(parents=True, exist_ok=True)
    with open(path, "w", newline="", encoding="utf-8") as f:
        w = csv.DictWriter(f, fieldnames=list(rows[0]))
        w.writeheader()
        w.writerows(rows)


def row(metric, label, gv, sv, d, lo, hi, n_pairs, p=""):
    return {"metric": metric, "group": label, "general": round(gv, 4), "secure": round(sv, 4),
            "diff": round(d, 4), "ci_lo": round(lo, 4), "ci_hi": round(hi, 4), "pairs": n_pairs, "wilcoxon_p": p}


def analysis(args):
    units = {}
    for l in UNITS.read_text(encoding="utf-8").splitlines():
        if l.strip():
            u = json.loads(l)
            units[u["unit_id"]] = u
    recs = load_records()
    pairs, steps_rows = build_pairs(recs, units)
    write_csv(OUT / "steps_tagged.csv", steps_rows)
    unit_ids = sorted({p["unit"] for p in pairs})
    unit_index = {u: i for i, u in enumerate(unit_ids)}
    rng = np.random.default_rng(0)
    idx = rng.integers(0, len(unit_ids), (args.boot, len(unit_ids)))
    idx_boot = np.array([np.bincount(r, minlength=len(unit_ids)) for r in idx])
    try:
        from scipy.stats import wilcoxon
    except ImportError:
        wilcoxon = None

    print(f"{len(recs)} functions, {len(steps_rows)} steps, {len(pairs)} (model, unit) pairs over {len(unit_ids)} units")
    main_rows, model_rows = [], []
    for metric in METRICS:
        gv, sv, d, lo, hi, _, rg, rs = estimate(pairs, metric, args.boot, rng, unit_index, idx_boot)
        p = ""
        if wilcoxon is not None and np.any(rs != rg):
            p = float(f"{wilcoxon(rs - rg).pvalue:.3g}")
        main_rows.append(row(metric, "all", gv, sv, d, lo, hi, len(pairs), p))
        for m in sorted({p_["model"] for p_ in pairs}):
            sub = [p_ for p_ in pairs if p_["model"] == m]
            if len(sub) < 5:
                continue
            gv, sv, d, lo, hi, *_ = estimate(sub, metric, args.boot, rng, unit_index, idx_boot)
            model_rows.append(row(metric, m, gv, sv, d, lo, hi, len(sub)))
    write_csv(OUT / "rq1_rq2_main.csv", main_rows)
    write_csv(OUT / "rq4_by_model.csv", model_rows)

    # RQ3: requirement relevance split; interaction = diff(relevant) - diff(other)
    hi_pairs = [p for p in pairs if p["req_hits"] >= 2]
    lo_pairs = [p for p in pairs if p["req_hits"] < 2]
    task_rows = []
    for metric in ("sec_core", "sec_core_noecho", "cat_validation", "cat_memory_resource", "cat_threat",
                   "cat_prevention", "cat_secrets_access", "echo"):
        res = {}
        for name, sub in (("security-relevant requirement", hi_pairs), ("other requirement", lo_pairs)):
            if len(sub) >= 5:
                gv, sv, d, lo, hi, diffs, *_ = estimate(sub, metric, args.boot, rng, unit_index, idx_boot)
                res[name] = diffs
                task_rows.append(row(metric, name, gv, sv, d, lo, hi, len(sub)))
        if len(res) == 2:
            inter = res["security-relevant requirement"] - res["other requirement"]
            task_rows.append({"metric": metric, "group": "interaction (relevant minus other)", "general": "",
                              "secure": "", "diff": round(float(np.mean(inter)), 4),
                              "ci_lo": round(float(np.percentile(inter, 2.5)), 4),
                              "ci_hi": round(float(np.percentile(inter, 97.5)), 4),
                              "pairs": len(pairs), "wilcoxon_p": ""})
    write_csv(OUT / "rq3_task_dependence.csv", task_rows)

    # RQ5: follow-through, pooled and by arm/model; intervals resample requirement units
    def ft_counts(sub, k):
        arr = np.array([[p[k]["ft_mention_check"], p[k]["ft_mention"],
                         p[k]["ft_nomention_check"], p[k]["ft_nomention"]] for p in sub])
        return arr, np.array([unit_index[p["unit"]] for p in sub])

    def ft_stats(arr, w):
        a, b, c, d_ = (w[:, None] * arr).sum(0)
        return a / max(b, 1e-9), c / max(d_, 1e-9)

    ft_rows = []
    for scope, sub_fn in (("all", lambda p: True),) + tuple(
            (m, (lambda p, m=m: p["model"] == m)) for m in sorted({p["model"] for p in pairs})):
        sub = [p for p in pairs if sub_fn(p)]
        if len(sub) < 5:
            continue
        data = {k: ft_counts(sub, k) for k in ("g", "s")}
        boot = {k: [] for k in ("g", "s")}
        for w in idx_boot:
            for k in ("g", "s"):
                arr, ui = data[k]
                boot[k].append(ft_stats(arr, w[ui].astype(float)))
        boot = {k: np.array(v) for k, v in boot.items()}
        for arm, k in (("general", "g"), ("secure", "s")):
            arr, ui = data[k]
            a, b, c, d_ = arr.sum(0)
            if b and d_:
                gap_b = boot[k][:, 0] - boot[k][:, 1]
                lo_m, hi_m = np.percentile(boot[k][:, 0], [2.5, 97.5])
                lo_g, hi_g = np.percentile(gap_b, [2.5, 97.5])
                ft_rows.append({"scope": scope, "arm": arm, "functions_mentioning_check": int(b),
                                "code_has_check_when_mentioned": round(a / b, 3),
                                "mentioned_ci_lo": round(lo_m, 3), "mentioned_ci_hi": round(hi_m, 3),
                                "functions_not_mentioning": int(d_),
                                "code_has_check_when_not_mentioned": round(c / d_, 3),
                                "gap": round(a / b - c / d_, 3),
                                "gap_ci_lo": round(lo_g, 3), "gap_ci_hi": round(hi_g, 3)})
        # secure minus general, same resamples
        dm = boot["s"][:, 0] - boot["g"][:, 0]
        dg = (boot["s"][:, 0] - boot["s"][:, 1]) - (boot["g"][:, 0] - boot["g"][:, 1])
        if scope == "all":
            print("\nRQ5 secure minus general (all): mention-rate diff CI",
                  np.percentile(dm, [2.5, 97.5]).round(3), " gap diff CI", np.percentile(dg, [2.5, 97.5]).round(3))
    write_csv(OUT / "rq5_follow_through.csv", ft_rows)

    # Console summary
    def show(title, rows, cols):
        print(f"\n{title}")
        for r in rows:
            print("  " + "  ".join(f"{str(r[c])[:34]:<{w}}" for c, w in cols))
    cols = [("metric", 22), ("general", 8), ("secure", 8), ("diff", 8), ("ci_lo", 8), ("ci_hi", 8), ("wilcoxon_p", 9)]
    show("RQ1/RQ2 (all pairs)", main_rows, cols)
    show(f"RQ3 ({len(hi_pairs)} security-relevant pairs, {len(lo_pairs)} other)", task_rows,
         [("metric", 22), ("group", 34), ("general", 8), ("secure", 8), ("diff", 8), ("ci_lo", 8), ("ci_hi", 8)])
    show("RQ5 follow-through", ft_rows, [("scope", 16), ("arm", 8), ("functions_mentioning_check", 8),
                                         ("code_has_check_when_mentioned", 8),
                                         ("code_has_check_when_not_mentioned", 8), ("gap", 8)])
    make_figures(main_rows, model_rows)


def make_figures(main_rows, model_rows):
    import matplotlib
    matplotlib.use("Agg")
    import matplotlib.pyplot as plt
    ink, muted, grid, blue, orange = "#0b0b0b", "#52514e", "#e6e5e1", "#2a78d6", "#eb6834"
    plt.rcParams.update({"font.size": 10, "axes.edgecolor": grid, "axes.labelcolor": muted,
                         "xtick.color": muted, "ytick.color": muted, "text.color": ink})

    # Figure 1: change in the share of steps per category (secure minus general), paired
    cats = [("cat_validation", "validation"), ("cat_memory_resource", "memory / resources"),
            ("cat_threat", "threat and safety words"), ("cat_prevention", "prevention (avoid, ensure)"),
            ("cat_error_handling", "error handling"), ("cat_secrets_access", "secrets and access"),
            ("echo", "repeats the prompt's wording"), ("sec_core_noecho", "any core category, wording removed")]
    by = {r["metric"]: r for r in main_rows}
    fig, ax = plt.subplots(figsize=(7.2, 3.9), dpi=160)
    for i, (k, lab) in enumerate(cats[::-1]):
        r = by[k]
        ax.plot([r["ci_lo"] * 100, r["ci_hi"] * 100], [i, i], color=blue, lw=1.6, solid_capstyle="round")
        ax.plot(r["diff"] * 100, i, "o", color=blue, ms=6, mec="white", mew=1.2)
        ax.text(r["ci_hi"] * 100 + 0.4, i, f"{r['diff'] * 100:+.1f}", va="center", fontsize=9, color=muted)
    ax.axvline(0, color=muted, lw=0.8)
    ax.set_yticks(range(len(cats)))
    ax.set_yticklabels([lab for _, lab in cats[::-1]])
    ax.set_xlabel("points more steps with this content (secure minus general)")
    ax.set_title("Change in share of reasoning steps, paired by requirement", loc="left", fontsize=10.5)
    ax.grid(axis="x", color=grid, lw=0.6); ax.set_axisbelow(True)
    for s in ("top", "right", "left"):
        ax.spines[s].set_visible(False)
    ax.tick_params(length=0)
    fig.tight_layout()
    OUT.mkdir(parents=True, exist_ok=True)
    fig.savefig(OUT / "fig_rq1_category_shift.png")
    fig.savefig(OUT / "fig_rq1_category_shift.pdf")
    plt.close(fig)

    # Figure 2: per-model share of steps in a core security category, general vs secure
    rows = [r for r in model_rows if r["metric"] == "sec_core_noecho" and r["pairs"] >= 20]
    rows.sort(key=lambda r: r["secure"])
    fig, ax = plt.subplots(figsize=(7.2, 3.2), dpi=160)
    for i, r in enumerate(rows):
        ax.plot([r["general"] * 100, r["secure"] * 100], [i, i], color=grid, lw=3, solid_capstyle="round", zorder=1)
        ax.plot(r["general"] * 100, i, "o", color=blue, ms=7, mec="white", mew=1.2, zorder=2)
        ax.plot(r["secure"] * 100, i, "o", color=orange, ms=7, mec="white", mew=1.2, zorder=2)
    ax.set_yticks(range(len(rows)))
    ax.set_yticklabels([r["group"] for r in rows])
    ax.set_xlabel("% of steps in a core security category (prompt wording removed)")
    ax.plot([], [], "o", color=blue, label="general prompt")
    ax.plot([], [], "o", color=orange, label="secure prompt")
    ax.legend(frameon=False, loc="lower right", fontsize=9)
    ax.set_title("By model (CodeGemma omitted: 5 usable pairs)", loc="left", fontsize=10.5)
    ax.grid(axis="x", color=grid, lw=0.6); ax.set_axisbelow(True)
    for s in ("top", "right", "left"):
        ax.spines[s].set_visible(False)
    ax.tick_params(length=0)
    fig.tight_layout()
    fig.savefig(OUT / "fig_rq4_by_model.png")
    fig.savefig(OUT / "fig_rq4_by_model.pdf")
    plt.close(fig)


def label_sheet(n):
    rng = np.random.default_rng(1)
    recs = load_records()
    pool = defaultdict(list)
    for r in recs:
        steps = r.get("reasoning") or []
        for i, s in enumerate(steps[:MAX_STEPS] if MAX_STEPS else steps):
            pool[r["arm"]].append((r["model_dir"], r["unit_id"], r["name"], i, s))
    per = n // 2
    sheet, key = [], []
    chosen = []
    for arm in ("general", "secure"):
        pick = rng.choice(len(pool[arm]), size=per, replace=False)
        chosen += [(arm, *pool[arm][j]) for j in pick]
    order = rng.permutation(len(chosen))
    for sid, j in enumerate(order, 1):
        arm, model, unit, func, i, text = chosen[j]
        t = tag_step(text)
        sheet.append({"step_id": sid, "text": text, **{k: "" for k in list(CATEGORIES) + ["echo"]}})
        key.append({"step_id": sid, "arm": arm, "model": model, "unit_id": unit, "func": func,
                    **{k: int(t[k]) for k in list(CATEGORIES) + ["echo"]}})
    write_csv(OUT / "label_sheet.csv", sheet)
    write_csv(OUT / "label_key.csv", key)
    print(f"wrote {OUT / 'label_sheet.csv'} ({len(sheet)} steps, blind) and label_key.csv (arm + automatic tags)")
    print("Fill each category column with 1 (step has that content) or 0, save as label_sheet_filled.csv.")
    print("Category definitions are in CATEGORIES in this file; echo = repeats the secure header's wording.")


def agreement(path):
    key_path = path.parent / "step_key.csv"
    if not key_path.exists():
        key_path = OUT / "label_key.csv"
    key = {int(r["step_id"]): r for r in csv.DictReader(open(key_path, encoding="utf-8"))}
    lab = {int(r["step_id"]): r for r in csv.DictReader(open(path, encoding="utf-8"))}
    rows = []
    for cat in list(CATEGORIES) + ["echo"]:
        tp = fp = fn = tn = 0
        for sid, r in lab.items():
            if r.get(cat, "").strip() == "":
                continue
            h, a = int(r[cat]), int(key[sid][cat])
            tp += h and a; fp += (not h) and a; fn += h and (not a); tn += (not h) and (not a)
        n = tp + fp + fn + tn
        if not n:
            continue
        po = (tp + tn) / n
        pe = ((tp + fp) * (tp + fn) + (fn + tn) * (fp + tn)) / n ** 2
        rows.append({"category": cat, "n": n, "human_positive": tp + fn, "auto_positive": tp + fp,
                     "precision": round(tp / (tp + fp), 3) if tp + fp else "",
                     "recall": round(tp / (tp + fn), 3) if tp + fn else "",
                     "kappa": round((po - pe) / (1 - pe), 3) if pe < 1 else ""})
    write_csv(OUT / "label_agreement.csv", rows)
    for r in rows:
        print(r)


def main():
    ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
    ap.add_argument("--boot", type=int, default=2000)
    ap.add_argument("--label-sheet", type=int, metavar="N")
    ap.add_argument("--agreement", type=Path, metavar="FILLED_CSV")
    ap.add_argument("--include-all", action="store_true", help="also analyse models in EXCLUDE")
    ap.add_argument("--max-steps", type=int, default=6, help="analyse only the first N steps per function (0 = all)")
    args = ap.parse_args()
    global MAX_STEPS
    MAX_STEPS = args.max_steps
    if args.include_all:
        EXCLUDE.clear()
    if args.label_sheet:
        label_sheet(args.label_sheet)
    elif args.agreement:
        agreement(args.agreement)
    else:
        analysis(args)


if __name__ == "__main__":
    main()
