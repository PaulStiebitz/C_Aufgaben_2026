# Exercise 68 – `argc`/`argv`: Numeric Type Validation & Conversion

## Topic
`argc`/`argv` – Robust Argument Parsing

## Objective
Parse command-line arguments with full type validation — distinguish integers from floats from strings, detect out-of-range values, and report meaningful errors.

---

## Instructions

1. Create `arg_types.c`.

2. Implement these helper functions that parse a `const char *str` and validate it:
   ```c
   /* Returns 1 if str is a valid integer (optional leading +/-), else 0 */
   int   parse_int(const char *str, int *out);

   /* Returns 1 if str is a valid float, else 0 */
   int   parse_float(const char *str, float *out);

   /* Returns 1 if str is a valid integer in [min, max], else prints error + returns 0 */
   int   parse_int_range(const char *str, int *out, int min, int max);

   /* Returns 1 if the string is a valid boolean: "true","1","yes" -> 1; "false","0","no" -> 0 */
   int   parse_bool(const char *str, int *out);
   ```
   - Use `strtol`/`strtod` with endptr checks (the endptr must point to `'\0'` for a fully valid conversion).

3. **Program**: the tool accepts:
   ```
   ./arg_types <width> <height> <scale> <visible>
   ```
   - `width`, `height`: positive integers (1–9999).
   - `scale`: float (0.1–100.0).
   - `visible`: boolean string.
   - Print a summary or detailed errors if any argument is invalid.

4. Test all error cases:
   - Non-numeric string where int expected.
   - Float string where int expected (`"3.14"`).
   - Out-of-range value.
   - Partial number (`"42abc"`).

---

## Expected Output
```
$ ./arg_types 800 600 1.5 true
width   = 800
height  = 600
scale   = 1.50
visible = true

$ ./arg_types 800 600 abc true
Error: "abc" is not a valid float for <scale>.

$ ./arg_types 99999 600 1.5 true
Error: width 99999 is out of range [1, 9999].

$ ./arg_types 800 600 1.5 maybe
Error: "maybe" is not a valid boolean (use true/false/1/0/yes/no).
```

---

## Hints
- `strtol(str, &end, 10)`: if `*end != '\0'`, the conversion was partial — reject it.
- `strtod` works the same way for floats.
- Checking for trailing garbage catches inputs like `"42abc"` that `atoi` would silently accept as 42.
