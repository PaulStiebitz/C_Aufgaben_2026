# Exercise 13 – String Basics: Input, Output & Character Traversal

## Topic
Strings & Arrays

## Objective
Practice handling C strings (null-terminated character arrays) with standard I/O and manual traversal.

## Instructions

1. Create `strings_basic.c`.

2. Prompt the user to enter a string (up to 99 characters). Use `fgets` to read it.

3. Implement and call:
   - `int count_chars(const char *s)` – counts total characters (excluding `\0` and `\n`).
   - `int count_vowels(const char *s)` – counts vowels (a, e, i, o, u, case-insensitive).
   - `int count_words(const char *s)` – counts words (sequences of non-space characters).
   - `void to_uppercase(char *s)` – converts the string to uppercase in-place.
   - `void to_lowercase(char *s)` – converts the string to lowercase in-place.

4. Print results for each function.

## Expected Output (example, input: "Hello World from C")
```
Input:          "Hello World from C"
Characters:     18
Vowels:         5
Words:          4
Uppercase:      "HELLO WORLD FROM C"
Lowercase:      "hello world from c"
```

## Hints
- Use `<ctype.h>` for `toupper()`, `tolower()`, `isspace()`, `isalpha()`.
- `fgets` stores the newline `\n` — strip it with: `s[strcspn(s, "\n")] = '\0';`
- Do **not** use `gets()`.
