# Exercise 72 – `argc`/`argv`: Calculator with Expression Mode

## Topic
`argc`/`argv` – Arithmetic CLI Tool

## Objective
Build a command-line calculator that supports two modes: simple (3 args) and expression mode (parsing an infix expression from multiple argv tokens).

---

## Instructions

1. Create `calc.c`.

2. **Mode A – Simple mode**:
   ```
   ./calc <number> <operator> <number>
   ```
   - Supported operators: `+`, `-`, `*`, `/`, `%` (integer modulo), `^` (power).
   - Parse both numbers with `strtod`.
   - Print the result.

3. **Mode B – Multi-operand**:
   ```
   ./calc sum 1 2 3 4 5
   ./calc product 2 3 4
   ./calc min 7 3 9 1 5
   ./calc max 7 3 9 1 5
   ./calc avg 10 20 30
   ```
   - Detect `argv[1]` as a keyword (`sum`, `product`, `min`, `max`, `avg`).
   - Parse all remaining args as doubles.
   - Compute and print result.

4. **Mode C – Help & error**:
   - If no args, print full usage.
   - If the operator is unknown, print an error.
   - Division by zero: print error.
   - Invalid number (non-numeric arg): print error.

5. Implement:
   ```c
   double power(double base, double exp);  /* iterative integer power */
   void   print_usage(const char *prog);
   ```

---

## Expected Output
```
$ ./calc 10 + 3
10 + 3 = 13.00

$ ./calc 10 / 0
Error: division by zero.

$ ./calc 2 ^ 8
2 ^ 8 = 256.00

$ ./calc sum 1 2 3 4 5
sum(1, 2, 3, 4, 5) = 15.00

$ ./calc avg 10 20 30
avg(10, 20, 30) = 20.00

$ ./calc min 7 3 9 1
min(7, 3, 9, 1) = 1.00

$ ./calc
Usage: calc <n> <op> <n>  |  calc <fn> <n1> [n2 ...]
Operators: + - * / % ^
Functions: sum product min max avg
```

---

## Hints
- `strcmp(argv[1], "sum") == 0` detects multi-operand mode.
- Detect simple mode when `argc == 4` and `argv[2]` is a known operator.
- For `%`, cast operands to `int` and use the C `%` operator.
- `strtod` with endptr checks (as in exercise 68) to reject invalid numbers.
