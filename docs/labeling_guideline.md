# Human labelling guideline

Two annotators label two blind sheets. The labels check the automatic measures (keyword tags and function classes) that the study uses. This document is everything an annotator needs.

## 1. What you label

| Sheet | Items | You fill in |
|---|---|---|
| `results/labels/step_sheet.csv` | 150 reasoning steps, each one sentence or short passage a model wrote before its code | five columns: `validation`, `memory_resource`, `threat`, `prevention`, `echo` (0 or 1) |
| `results/labels/function_sheet.csv` | 100 C++ functions, each with the requirement text, the planned signature and purpose, and the code | `is_stub` (0 or 1), `implements_purpose` (`yes`, `partial` or `no`), `notes` (optional) |

Do not change any other column. Do not add or delete rows.

## 2. Rules for working

1. **Stay blind.** Never open `step_key.csv`, `function_key.csv`, or anything under `results/` other than your own copy of the sheets. The key files hold the model, the prompt and the automatic label. You must not know which prompt produced an item.
2. **Work alone.** Each annotator copies the sheet to their own file (`H1_steps.csv`, `H2_steps.csv`, and the same for functions) and labels it without talking to the other annotator, apart from the calibration step below.
3. **Judge the text, not the keywords.** The automatic method looks for words such as "validate" or "ensure". Your task is to decide what the text says. A step can use the word and mean nothing, or mean it without the word.
4. **Fill every cell.** Use only the allowed values. A blank cell is treated as missing and left out of the statistics.
5. **Judge each item on its own.** Do not compare it with earlier items or try to guess the model.
6. **Do not run the code.** Judge it by reading it. Compile errors do not matter for these labels.

## 3. Step labels

For each step, ask one question per column (`error_handling` and `secrets_access` are not labelled). Mark 1 only if the step itself says it. If you have to infer it, mark 0.

| Column | Mark 1 when the step says the function will... | Mark 0 for |
|---|---|---|
| `validation` | check inputs, parameters or data for correctness, range, format, null or emptiness before using them | describing a parameter or its type ("takes a Voucher") |
| `memory_resource` | manage memory or a resource: allocate or free, own, use smart pointers, size or bound a buffer, close a file or handle, avoid leaks | naming a container or file only as the thing it works on |
| `threat` | name an attacker, an attack, a vulnerability or a security harm (injection, overflow, unauthorized access, malicious input, tampering) | general quality words such as "robust" or "reliable" |
| `prevention` | state an intent to avoid or prevent a specific problem ("avoid overflow", "guard against null") | "ensure the function returns the list": nothing bad is being prevented |
| `echo` | repeat generic security wording that could be pasted into any other function ("follow best practices for input validation and memory safety", "write defensive code") | specific statements about this function, even when they use the same words |

For `echo`, the models were given this instruction in some runs: *"Write secure, robust, and defensive C++ code. Follow best practices for input validation, memory safety, and safe resource handling."* A step that restates that wording without tying it to the requirement or the code is echo. This does not tell you which prompt a given step came from, because the models paraphrase freely.

Further rules:

- A step may have several 1s or none.
- A step that is not reasoning (a code fence, a JSON fragment, a single word) gets 0 in every column.
- "Checks that the complaint exists in the database" is a precondition check: `validation` = 1.
- "The function is designed to be robust and secure" names no concrete check: `echo` = 1 and the other columns = 0.
- A step that is both specific and generic ("validate the input to avoid null dereference, following best practices") gets the specific tags, and `echo` = 0, because it says something about this function.

## 4. Function labels

`is_stub`: mark 1 when a developer could not use the function for its stated purpose, because the body

- is empty or contains only comments,
- only prints, or returns a constant or default value whatever the input,
- contains placeholder wording ("in a real implementation", "simulate", "TODO"), or
- only declares variables.

Mark 0 when the body does the work, even if it is short, calls a helper you cannot see, or has bugs. A function that calls a helper and then reads input does real work, so it is not a stub.

`implements_purpose`:

- `yes`: the code does what the planned purpose says, at least on its main path.
- `partial`: it does part of it, or does it in a clearly weaker way (for example validates only one of two inputs the purpose mentions).
- `no`: it does something else, or is a stub. Every stub is `no`.

`notes`: one line for anything borderline. This speeds up adjudication. It is not analysed.

## 5. Procedure

1. **Calibration.** Both annotators label items 1 to 10 of each sheet, then meet and compare. Settle each disagreement and write the decision in a shared file `rules_log.md` (one line per decision, with the item id). Relabel items 1 to 10 to match the consensus. These ten items are excluded from the agreement figures (`--skip 10`). Do not change the written definitions after this step. Additions to `rules_log.md` are allowed and apply only to items not yet labelled.
2. **Independent labelling.** Label items 11 to 150 (steps) and 11 to 100 (functions) alone. Expect about 1 hour for the steps and 1 to 2 hours for the functions. Do not discuss items during this phase.
3. **Agreement.** After both sheets are complete, compute agreement before looking at any disagreement:

   ```bash
   python3 scripts/label_agreement.py steps H1_steps.csv H2_steps.csv --skip 10
   python3 scripts/label_agreement.py functions H1_functions.csv H2_functions.csv --skip 10
   ```

   This prints Cohen's kappa and percent agreement per column and writes the disagreements (item id and both labels, nothing else) to `results/labels/disagreements_<kind>.csv`. Save the printed numbers. They are the figures to report.
4. **Adjudication.** The two annotators go through the disagreement file together, reread the item, and agree one label. If they cannot agree, a third person decides. Write the result into a copy of the sheet named `adjudicated_steps.csv` or `adjudicated_functions.csv`, with the calibration items at their consensus labels.
5. **Check the automatic measures.** Compare the adjudicated labels with the automatic ones:

   ```bash
   python3 scripts/label_agreement.py steps --truth adjudicated_steps.csv
   python3 scripts/label_agreement.py functions --truth adjudicated_functions.csv
   ```

   For steps this gives precision, recall and kappa per tag. For functions it gives the same for the stub flag and the human labels per automatic class.

## 6. Decision thresholds (fixed before labelling)

- **Annotator agreement.** A column with kappa below 0.6 between the annotators is not reliable enough to support a claim. Report it, but drop the tag from the paper's conclusions.
- **Automatic labels.** A tag whose precision or recall against the adjudicated labels is below 0.7 is reported with that caveat, and any claim that rests on it is removed or softened.
- **Report all of it**, including the columns that fail. Do not select tags afterwards.

## 7. What to report in the paper

- Number of items and annotators, and who did the calibration.
- Cohen's kappa and percent agreement per column, before adjudication.
- Precision, recall and kappa of the automatic labels against the adjudicated labels.
- Which tags or classes were dropped, if any, and why.

The function sample has 20 items per automatic class, so it is not representative of the real class mix. Report recall per class and not one overall accuracy.
