# Exercise 79 – Variadic Functions: Min/Max/Clamp with Generics via Macros

## Topic
Variadic Functions + Preprocessor Macros + Type-Generic Programming

## Objective
Combine variadic macros (`__VA_ARGS__`), `_Generic`, and variadic functions to create type-generic utilities.

---

## Instructions

1. Create `generic_math.c`.

2. **Part A – Variadic Macros**:
   Define macros that accept any number of arguments:
   ```c
   /* Returns the number of arguments (up to 8) */
   #define NARGS(...) /* implement using __VA_ARGS__ counting trick */

   /* Calls the appropriate function based on argument count */
   #define MIN2(a,b)       ((a)<(b)?(a):(b))
   #define MIN3(a,b,c)     MIN2(MIN2(a,b),c)
   #define MIN4(a,b,c,d)   MIN2(MIN2(a,b),MIN2(c,d))
   ```

3. **Part B – `_Generic` type-dispatch** (C11):
   ```c
   #define ABS(x) _Generic((x),   \
       int:    abs_int,            \
       double: abs_double,         \
       float:  abs_float           \
   )(x)
   ```
   Implement `abs_int`, `abs_double`, `abs_float`.
   Demonstrate `ABS(-5)`, `ABS(-3.14)`, `ABS(-2.7f)`.

4. **Part C – Variadic integer functions**:
   ```c
   int   vmin(int count, ...);     /* minimum of count integers */
   int   vmax(int count, ...);     /* maximum of count integers */
   int   vclamp(int val, int lo, int hi);
   long  vprod(int count, ...);    /* product of count integers */
   ```

5. **Part D – Type-generic `SWAP` macro**:
   ```c
   #define SWAP(type, a, b) do { type _t=(a); (a)=(b); (b)=_t; } while(0)
   ```
   Demonstrate with `int`, `double`, `char*`.

---

## Expected Output
```
MIN2(3,7)         = 3
MIN3(3,7,1)       = 1
MIN4(4,2,8,1)     = 1

ABS(-5)           = 5     (int)
ABS(-3.14)        = 3.14  (double)
ABS(-2.7f)        = 2.70  (float)

vmin(5: 9,2,7,1,5)  = 1
vmax(5: 9,2,7,1,5)  = 9
vclamp(15, 0, 10)   = 10
vprod(4: 2,3,4,5)   = 120

SWAP int:    a=20, b=10
SWAP double: x=3.14, y=2.71
```

---

## Hints
- `_Generic` is a C11 feature — compile with `gcc -std=c11`.
- Variadic macros use `...` and `__VA_ARGS__`: `#define MY_MACRO(...) func(__VA_ARGS__)`.
- The `NARGS` trick uses a macro that shifts args through a pre-counted position sequence.
