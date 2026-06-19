# Exercise 52 – Terminal Input via `main`: `argc` & `argv`

## Topic
`main(int argc, char *argv[])` – Command-Line Arguments

## Objective
Understand how C programs receive arguments from the shell, validate and parse them, and use them to control program behaviour.

---

## Background

Every C program's entry point can receive arguments from the shell:

```c
int main(int argc, char *argv[])
```

| Variable | Meaning |
|----------|---------|
| `argc` | **Arg**ument **C**ount – total number of tokens (including the program name) |
| `argv` | **Arg**ument **V**ector – array of `char*` strings, `argv[0]` = program name |

Example: running `./calc add 10 20` gives:
```
argc    = 4
argv[0] = "./calc"
argv[1] = "add"
argv[2] = "10"
argv[3] = "20"
```

---

## Part A – Basic Argument Inspection

1. Create `args_inspect.c`.
2. Print `argc` and every `argv[i]` with its index.
3. Print the program name (without path) — find the last `/` in `argv[0]` using `strrchr`.

### Expected Output
```
$ ./args_inspect hello world 42
argc = 4
argv[0] = ./args_inspect   (program: args_inspect)
argv[1] = hello
argv[2] = world
argv[3] = 42
```

---

## Part B – Typed Argument Parsing

1. Create `typed_args.c`.
2. The program expects exactly 3 arguments: `<name> <age> <height_cm>`.
   - Validate the count: if wrong, print usage and exit with code 1.
   - Convert `age` with `atoi` and `height_cm` with `atof`.
   - Validate ranges: `age` must be 0–150, `height_cm` must be 30–300.
   - Print a summary.

### Expected Output
```
$ ./typed_args Alice 22 168
Name:   Alice
Age:    22
Height: 168.0 cm

$ ./typed_args Alice
Usage: ./typed_args <name> <age> <height_cm>

$ ./typed_args Alice 200 168
Error: age 200 is out of range (0-150).
```

---

## Part C – Flag-Based CLI Tool

1. Create `flags.c`.
2. Parse the following optional flags (any order, any combination):
   ```
   -v          verbose mode (print extra info)
   -n <count>  repeat the message <count> times (default: 1)
   -u          convert message to uppercase
   <message>   the text to display (last non-flag argument)
   ```
3. Iterate over `argv[1..argc-1]` with a `while` / `for` loop; use `strcmp` for flag names.
4. If no message is given, print an error.

### Expected Output
```
$ ./flags -n 3 -u "hello world"
HELLO WORLD
HELLO WORLD
HELLO WORLD

$ ./flags -v "test"
[verbose] argc=3, message="test", count=1, uppercase=0
test

$ ./flags
Error: no message provided.
Usage: ./flags [-v] [-u] [-n <count>] <message>
```

---

## Part D – File Processing via Arguments

1. Create `wordcount.c`.
2. Accept one or more filenames as arguments: `./wordcount file1.txt file2.txt`.
3. For each file:
   - Count lines, words, and characters (like the Unix `wc` command).
   - Print per-file stats.
4. If multiple files, also print a **total** row.
5. If a file cannot be opened, print an error and continue with the next file.

### Expected Output
```
$ ./wordcount log.txt notes.txt
  lines  words  chars  filename
      5     21    143  log.txt
      3     12     88  notes.txt
      8     33    231  total
```

---

## Hints
- `argc` is always at least 1 (the program name).
- All `argv` values are **strings** — use `atoi`/`atof`/`strtol` to convert to numbers.
- To check for a flag like `-n` that takes a value, access `argv[i+1]` and increment `i` an extra time.
- Use `strcmp(argv[i], "-v") == 0` — never `argv[i] == "-v"` (that compares pointers, not content).
- `exit(1)` terminates the program with error code 1 from anywhere (needs `<stdlib.h>`).
