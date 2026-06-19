# Exercise 69 – `argc`/`argv`: Long and Short Options (getopt-style)

## Topic
`argc`/`argv` – Option Parsing (getopt-style)

## Objective
Implement a manual option parser that supports both short (`-v`) and long (`--verbose`) options, with and without values, like the POSIX `getopt` pattern.

---

## Instructions

1. Create `optparser.c`.

2. Define a supported options table:
   ```c
   typedef struct {
       char  short_name;     /* e.g. 'v' for -v, '\0' if none */
       const char *long_name;/* e.g. "verbose", NULL if none  */
       int   takes_value;    /* 1 if option requires an argument, 0 otherwise */
       const char *description;
   } OptionDef;
   ```

3. Define these options:
   | Short | Long        | Value? | Description |
   |-------|-------------|--------|-------------|
   | `-v`  | `--verbose` | No     | Enable verbose output |
   | `-q`  | `--quiet`   | No     | Suppress all output |
   | `-o`  | `--output`  | Yes    | Output file name |
   | `-n`  | `--count`   | Yes    | Repeat count (integer) |
   | `-h`  | `--help`    | No     | Print help and exit |

4. Implement:
   ```c
   void print_help(const char *prog_name, const OptionDef *opts, int n);

   /* Parses argv, fills a result struct, returns 0 on success or prints error + returns 1 */
   int parse_options(int argc, char *argv[], /* result fields */ ...);
   ```
   Store results in a struct:
   ```c
   typedef struct {
       int  verbose;
       int  quiet;
       char output[100];  /* empty string if not given */
       int  count;        /* default 1 */
       char *positional_args[10];
       int  positional_count;
   } ParsedOptions;
   ```

5. In `main`, call `parse_options`, print the parsed values, then simulate a program that uses them.

---

## Expected Output
```
$ ./optparser -v --output result.txt -n 3 file1.txt file2.txt
verbose   = 1
quiet     = 0
output    = "result.txt"
count     = 3
positional: file1.txt, file2.txt

$ ./optparser --help
Usage: optparser [options] [files...]
Options:
  -v, --verbose        Enable verbose output
  -q, --quiet          Suppress all output
  -o, --output <file>  Output file name
  -n, --count  <n>     Repeat count
  -h, --help           Print this help

$ ./optparser --output
Error: --output requires a value.
```

---

## Hints
- Walk `argv[i]` in a loop. Check if `argv[i][0] == '-'` to detect options.
- For `--long-option`: `argv[i][1] == '-'`, compare `argv[i]+2` with `long_name`.
- For a value option: the value is `argv[i+1]` — increment `i` before the next iteration.
- Positional arguments are those that don't start with `-`.
- `--` (double dash alone) conventionally ends option parsing; everything after is positional.
