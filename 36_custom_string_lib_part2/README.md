# Exercise 36 – Implement Your Own String Library (Part 2)

## Topic
String Library – Custom Implementation (Advanced)

## Objective
Continue building your own string library with more complex functions.

## Instructions

1. Extend `mystring.h` / `mystring.c` from Exercise 35 (or start fresh).

2. Implement (without using `<string.h>`):
   - `char* my_strtok(char *str, const char *delim);`
     Stateful tokenizer (use a `static` pointer internally). Returns tokens one at a time.
   - `char* my_strrev(char *s);`
     Reverses a string in-place, returns the string.
   - `int   my_str_is_palindrome(const char *s);`
     Returns 1 if the string reads the same forwards and backwards, 0 otherwise (case-sensitive).
   - `int   my_str_to_int(const char *s, int *out);`
     Converts a decimal string to int. Handles leading sign (`+`/`-`). Returns 0 on success, -1 on invalid input.
   - `void  my_str_to_upper(char *s);`
   - `void  my_str_to_lower(char *s);`

3. Write comprehensive tests in `main.c`.

## Expected Output (example)
```
strtok("a,b,c,d", ","): a | b | c | d
strrev("hello")         = "olleh"
palindrome("racecar")   = 1
palindrome("hello")     = 0
str_to_int("  -42")     = -42 (ok)
str_to_int("12x3")      = -1 (error)
to_upper("Hello World") = "HELLO WORLD"
```

## Hints
- `my_strtok` uses a `static char *save;` to remember where to continue.
- For `my_str_to_int`, skip leading whitespace, check for sign, then convert digits.
- Use `<ctype.h>` for `toupper`/`tolower`/`isdigit`/`isspace` — those are not in `<string.h>`.
