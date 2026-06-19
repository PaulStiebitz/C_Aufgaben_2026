# Exercise 74 – `argc`/`argv`: Batch File Processor

## Topic
`argc`/`argv` + File I/O – Multi-File Tool

## Objective
Process multiple input files given on the command line, aggregate statistics, and write a report — combining everything from exercises 68–73.

---

## Instructions

1. Create `batch_processor.c`.

2. **Interface**:
   ```
   ./batch [options] file1.txt file2.txt ...
   Options:
     --report <file>   write summary report to <file> (default: stdout)
     --mode  <mode>    stats | grep | transform   (default: stats)
     --pattern <str>   (for grep mode) search pattern
     --transform <op>  (for transform mode): upper | lower | trim | number
     --ignore-errors   skip unreadable files instead of aborting
   ```

3. Implement three processing modes:

   **`stats` mode**: for each file, print:
   - filename, size (bytes), lines, words, longest line length.
   - At the end: totals across all files.

   **`grep` mode**: for each file, print filename + matching lines (with line numbers).
   Summary: total matches across all files.

   **`transform` mode**: for each file, apply the transformation and write result to `<original>_out.txt`.
   Summary: total lines processed.

4. Aggregate results across all files.

5. Write a final report to `--report` file (or stdout if not specified).

---

## Example Usage
```
$ ./batch --mode stats report1.txt notes.txt readme.md
```

## Expected Output
```
=== File Stats ===
FILE              SIZE   LINES  WORDS  LONGEST
report1.txt        312       5     21       62
notes.txt          180       3     12       44
readme.md         1024      20     98       80
----------------------------------------------
TOTAL            1516      28    131        -

=== Summary written to stdout ===

$ ./batch --mode grep --pattern "TODO" src1.c src2.c
src1.c:12: /* TODO: fix this */
src2.c:44: // TODO: refactor
Total matches: 2
```

---

## Hints
- Store per-file results in a struct array; loop over `argv` to collect filenames (skip anything starting with `--`).
- `--ignore-errors`: on `fopen` failure, print a warning and `continue` to the next file.
- Keep a running total struct and update it after each file.
- Separate the file processing logic from the main argument parsing.
