# Exercise 35 – Implement Your Own String Library (Part 1)

## Topic
String Library – Custom Implementation

## Objective
Reimplement the core `<string.h>` functions manually to deeply understand how they work under the hood.

## Instructions

1. Create `mystring.h` and `mystring.c`.

2. Implement (without using any `<string.h>` functions):
   - `size_t my_strlen(const char *s);`
   - `char*  my_strcpy(char *dest, const char *src);`
   - `char*  my_strncpy(char *dest, const char *src, size_t n);`
   - `char*  my_strcat(char *dest, const char *src);`
   - `int    my_strcmp(const char *a, const char *b);`
   - `int    my_strncmp(const char *a, const char *b, size_t n);`
   - `char*  my_strchr(const char *s, int c);`
   - `char*  my_strstr(const char *haystack, const char *needle);`

3. Create `main.c` that tests every function with at least two cases (matching and non-matching where applicable).

4. Compile as a library + main and link.

## Expected Output (example)
```
my_strlen("hello") = 5
my_strcpy: "hello world"
my_strcat: "foobar"
my_strcmp("abc","abc") = 0
my_strcmp("abc","abd") < 0
my_strchr("hello",'l') = "llo"
my_strstr("one two three","two") = "two three"
my_strstr("abc","xyz") = NULL
```

## Hints
- `my_strstr` can use a nested loop: outer iterates over haystack, inner checks for needle.
- `my_strncpy` must zero-pad the destination if `strlen(src) < n`.
- Use only pointer arithmetic — no array indexing.
