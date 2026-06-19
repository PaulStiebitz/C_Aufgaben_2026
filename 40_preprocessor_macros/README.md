# Exercise 40 – Preprocessor Macros & Conditional Compilation

## Topic
Preprocessor / Macros

## Objective
Learn to use `#define` macros with parameters, `#ifdef`/`#ifndef`, and `#pragma once` / include guards.

## Instructions

1. Create `macros.c`.

2. Define the following macros:
   ```c
   #define MAX(a, b)       ((a) > (b) ? (a) : (b))
   #define MIN(a, b)       ((a) < (b) ? (a) : (b))
   #define SQUARE(x)       ((x) * (x))
   #define CLAMP(x, lo, hi) (MAX((lo), MIN((x), (hi))))
   #define SWAP(type, a, b) do { type _t = (a); (a) = (b); (b) = _t; } while(0)
   #define ARRAY_SIZE(arr)  (sizeof(arr) / sizeof((arr)[0]))
   ```

3. Demonstrate each macro with at least two calls and print the results.

4. Add a `DEBUG` build option:
   ```c
   #ifdef DEBUG
   #define LOG(msg) fprintf(stderr, "[DEBUG] %s:%d: %s\n", __FILE__, __LINE__, msg)
   #else
   #define LOG(msg)   /* no-op */
   #endif
   ```
   Use `LOG("Starting program")` and `LOG("Done")`.
   Compile twice:
   ```
   gcc macros.c -o macros_release
   gcc macros.c -DDEBUG -o macros_debug
   ```

5. Explain in comments why `SQUARE(1+2)` would give the wrong result without parentheses.

## Expected Output (release)
```
MAX(3,7)         = 7
MIN(3,7)         = 3
SQUARE(5)        = 25
CLAMP(15, 0, 10) = 10
SWAP: a=20, b=10
ARRAY_SIZE({1,2,3,4,5}) = 5
```

## Hints
- Always wrap macro parameters in parentheses to avoid operator precedence bugs.
- The `do { ... } while(0)` idiom makes multi-statement macros safe in `if/else` bodies.
- `__FILE__` and `__LINE__` are built-in preprocessor identifiers.
