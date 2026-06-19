# Exercise 75 – Variadic Functions: Type-Tagged Arguments

## Topic
Variadic Functions + Unions + Enums

## Objective
Build a type-safe variadic function using a **tag + value** pattern to accept mixed types at runtime.

---

## Background

Standard variadic functions (`va_arg`) require the caller and callee to agree on types — C does not enforce this. One solution: pass a **type tag** before each value so the function knows what to extract.

---

## Instructions

1. Create `typed_variadic.c`.

2. Define:
   ```c
   typedef enum { ARG_END, ARG_INT, ARG_DOUBLE, ARG_STRING, ARG_BOOL } ArgType;
   typedef union  { int i; double d; const char *s; int b; } ArgVal;
   typedef struct { ArgType type; ArgVal val; } TypedArg;
   ```

3. Implement:
   ```c
   /* Accepts pairs: (ArgType, value), ..., terminated by ARG_END.
      Returns the number of arguments processed. */
   int typed_print(const char *label, ...);
   ```
   - Use `va_arg` to read the `ArgType` tag first, then branch on it to read the right type.
   - For `ARG_INT`: `va_arg(args, int)`.
   - For `ARG_DOUBLE`: `va_arg(args, double)`.
   - For `ARG_STRING`: `va_arg(args, char*)`.
   - For `ARG_BOOL`: `va_arg(args, int)`, print `"true"` or `"false"`.
   - Stop on `ARG_END`.
   - Print `"label[N]: value"` for each argument.

4. Also implement:
   ```c
   double typed_sum_numbers(int count, ...);
   /* Accepts 'count' pairs of (ArgType, value) where type is INT or DOUBLE.
      Returns the sum. */
   ```

5. In `main`:
   ```c
   typed_print("demo",
       ARG_INT, 42,
       ARG_DOUBLE, 3.14,
       ARG_STRING, "hello",
       ARG_BOOL, 1,
       ARG_END);

   double total = typed_sum_numbers(3,
       ARG_INT, 10,
       ARG_DOUBLE, 5.5,
       ARG_INT, 7);
   ```

---

## Expected Output
```
demo[0]: (int)    42
demo[1]: (double) 3.140000
demo[2]: (string) "hello"
demo[3]: (bool)   true

typed_sum(10, 5.5, 7) = 22.50
```

---

## Hints
- Each argument is two `va_arg` calls: first the tag (`int` / `ArgType`), then the value.
- `ARG_BOOL` uses `int` under the hood (enum values are ints).
- This pattern is similar to how `printf` works internally — the format string is the "tag" channel.
