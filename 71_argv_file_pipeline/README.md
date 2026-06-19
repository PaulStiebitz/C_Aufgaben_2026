# Exercise 71 – `argc`/`argv`: File Pipeline Tool

## Topic
`argc`/`argv` + File I/O – Pipeline Processing

## Objective
Build a CLI tool that acts like a Unix pipeline stage: reads from a file (or stdin), transforms lines, and writes to a file (or stdout) — all controlled by arguments.

---

## Instructions

1. Create `linetool.c`.

2. The tool has this interface:
   ```
   ./linetool [options] [input_file] [-o output_file]
   ```
   Options:
   | Flag | Effect |
   |------|--------|
   | `--upper`          | Convert all lines to uppercase |
   | `--lower`          | Convert all lines to lowercase |
   | `--trim`           | Strip leading/trailing whitespace from each line |
   | `--number`         | Prefix each output line with its line number |
   | `--reverse`        | Reverse the order of lines (output last line first) |
   | `--grep <pattern>` | Only output lines containing `pattern` |
   | `--skip <n>`       | Skip the first `n` lines |
   | `--max <n>`        | Output at most `n` lines |
   | `-o <file>`        | Write output to `file` instead of stdout |

   If `input_file` is omitted, read from stdin.

3. Implementation steps:
   - Parse all options from `argv`.
   - Open input (file or `stdin`) and output (file or `stdout`).
   - Read all lines into a buffer (max 1000 lines × 256 chars) — needed for `--reverse`.
   - Apply `--skip` and `--max` to determine the active range.
   - Apply transformations in order: grep → trim → upper/lower.
   - If `--reverse`, iterate backwards.
   - Print each kept line with optional `--number` prefix.

4. In `main`, test by calling the program with different argument combinations.

---

## Example Usage
```
$ ./linetool input.txt --upper --number -o out.txt
$ ./linetool input.txt --grep "error" --number
$ ./linetool input.txt --reverse --max 3
$ ./linetool input.txt --skip 2 --max 4 --lower
```

## Expected Output (example, input has 5 lines)
```
$ ./linetool sample.txt --number --grep "the"
3: The quick brown fox
7: In the beginning
```

---

## Hints
- Reading all lines into a buffer first (rather than streaming) allows `--reverse` to work.
- Apply filters and transforms inside a single output loop.
- Use `FILE *in = stdin; FILE *out = stdout;` as defaults, then override based on args.
- A `-o` flag followed by a filename: check `strcmp(argv[i], "-o") == 0`, then take `argv[i+1]`.
