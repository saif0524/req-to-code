"""
Extract generation units from the XML requirements documents.

A unit is one <p> section: its own <text_body>/<req>/<itemize> content (not the
text of nested sub-sections), plus the document title and the heading path.
Output is data/requirements_units.jsonl, one unit per line.

By default only sections that look like requirements are kept (contain
shall/must/should/will, or have <req> children) and that have enough text.
Boilerplate sections (introduction, glossary, references, ...) are dropped.
"""
import argparse
import json
import re
from pathlib import Path

from lxml import etree

ROOT = Path(__file__).resolve().parent.parent
XML_DIR = ROOT / "data" / "requirements-xml" / "XMLZIPFile"
OUT = ROOT / "data" / "requirements_units.jsonl"

MODAL = re.compile(r"\b(shall|must|should|will|needs? to|is required to)\b", re.I)
BOILERPLATE_TITLE = re.compile(
    r"introduction|purpose|scope|overview|definition|glossary|acronym|abbreviation|"
    r"reference|document (convention|overview)|intended audience|table of contents|"
    r"revision|change log|appendix|references|contact|copyright|disclaimer",
    re.I,
)


def local(e):
    return etree.QName(e).localname


def clean(s):
    return re.sub(r"\s+", " ", s).strip()


def own_text(p):
    """Text of a section excluding nested <p> sections and the title."""
    parts = []
    for child in p:
        if not isinstance(child.tag, str):
            continue
        name = local(child)
        if name in ("p", "title"):
            continue
        parts.append(clean("".join(child.itertext())))
    return clean(" ".join(x for x in parts if x))


def title_of(p):
    t = p.find("{*}title")
    return clean("".join(t.itertext())) if t is not None else ""


def heading_path(p):
    path = []
    node = p
    while node is not None and isinstance(node.tag, str) and local(node) == "p":
        path.append(title_of(node))
        node = node.getparent()
    return [x for x in reversed(path) if x]


def slug(s):
    return re.sub(r"[^a-z0-9]+", "_", s.lower()).strip("_")


def extract_file(path):
    root = etree.parse(str(path)).getroot()
    doc_title = clean("".join(root.find("{*}title").itertext())) if root.find("{*}title") is not None else path.stem
    doc_slug = slug(path.stem)
    for p in root.iter("{*}p"):
        text = own_text(p)
        if not text:
            continue
        n_req = len(p.findall("{*}req"))
        sec = p.get("id", "").strip()
        title = title_of(p)
        yield {
            "unit_id": f"{doc_slug}__{slug(sec) or 'x'}",
            "doc": path.stem,
            "doc_title": doc_title,
            "section_id": sec,
            "section_title": title,
            "heading_path": heading_path(p),
            "n_req_tags": n_req,
            "has_modal": bool(MODAL.search(text)),
            "boilerplate": bool(BOILERPLATE_TITLE.search(title)),
            "n_words": len(text.split()),
            "text": text,
        }


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--min-words", type=int, default=25)
    ap.add_argument("--max-words", type=int, default=400)
    ap.add_argument("--keep-all", action="store_true", help="skip the requirement/boilerplate filters")
    ap.add_argument("--out", default=str(OUT))
    args = ap.parse_args()

    units, seen = [], set()
    for f in sorted(XML_DIR.glob("*.xml")):
        for u in extract_file(f):
            if u["unit_id"] in seen:  # duplicate section ids inside one doc
                u["unit_id"] += f"_{len(seen)}"
            seen.add(u["unit_id"])
            units.append(u)

    total = len(units)
    if not args.keep_all:
        units = [
            u for u in units
            if not u["boilerplate"]
            and (u["has_modal"] or u["n_req_tags"])
            and args.min_words <= u["n_words"] <= args.max_words
        ]

    with open(args.out, "w", encoding="utf-8") as f:
        for u in units:
            f.write(json.dumps(u, ensure_ascii=False) + "\n")

    per_doc = {}
    for u in units:
        per_doc[u["doc"]] = per_doc.get(u["doc"], 0) + 1
    print(f"{len(units)} units kept out of {total} sections -> {args.out}")
    for d, n in sorted(per_doc.items()):
        print(f"  {n:4d}  {d}")


if __name__ == "__main__":
    main()
