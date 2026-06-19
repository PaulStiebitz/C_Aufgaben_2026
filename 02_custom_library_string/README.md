# Exercise 02 – Create a Custom String Utility Library

## Topic
Custom Libraries (`.h` / `.c`)

## Objective
Build a small string utility library using only character arrays and pointers — **without** using `<string.h>` functions.

## Instructions

1. Create a header file `strutil.h` with include guards and the following function declarations:
   - `int my_strlen(const char *s);`
   - `void my_strcpy(char *dest, const char *src);`
   - `int my_strcmp(const char *a, const char *b);` (returns 0 if equal, <0 or >0 otherwise)
   - `void my_strrev(char *s);` (reverses the string in-place)
   - `int my_strcount(const char *s, char c);` (counts occurrences of character `c` in `s`)

2. Create `strutil.c` implementing all five functions using pointer arithmetic.

3. Create `main.c` that tests each function and prints results.

4. Compile in two steps (separate compilation), then link.

## Expected Output (example)
```
my_strlen("hello")         = 5
my_strcpy -> "hello"
my_strcmp("abc","abc")     = 0
my_strcmp("abc","abd")     < 0
my_strrev("hello")         = "olleh"
my_strcount("banana",'a')  = 3
```

## Hints
- Use pointer arithmetic (`*ptr++`) rather than index-based access where possible.
- `my_strrev` can use a two-pointer swap approach.
- Do **not** `#include <string.h>` anywhere.
