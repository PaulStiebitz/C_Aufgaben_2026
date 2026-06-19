# Exercise 01 – Create a Custom Math Library

## Topic
Custom Libraries (`.h` / `.c`)

## Objective
Learn how to split C code into a header file and an implementation file by building a small math utility library.

## Instructions

1. Create a header file `mathlib.h` that declares the following functions:
   - `int add(int a, int b);`
   - `int subtract(int a, int b);`
   - `int multiply(int a, int b);`
   - `double divide(double a, double b);` (return `0.0` and print an error if `b == 0`)
   - `int absolute(int x);`

2. Create an implementation file `mathlib.c` that **includes** `mathlib.h` and defines all declared functions.

3. Create a `main.c` that includes `mathlib.h`, calls each function with sample values, and prints the results.

4. Use **include guards** (`#ifndef / #define / #endif`) in `mathlib.h`.

5. Compile and link manually:
   ```
   gcc -c mathlib.c -o mathlib.o
   gcc -c main.c -o main.o
   gcc mathlib.o main.o -o program
   ./program
   ```

## Expected Output (example)
```
add(3, 4)       = 7
subtract(10, 3) = 7
multiply(6, 7)  = 42
divide(10, 4)   = 2.500000
absolute(-9)    = 9
divide(5, 0)    = Error: division by zero
```

## Hints
- The header file only contains **declarations** (prototypes), not definitions.
- Use `#ifndef MATHLIB_H` as your include guard name.
- Remember to `#include "mathlib.h"` (with quotes, not angle brackets) for local headers.
