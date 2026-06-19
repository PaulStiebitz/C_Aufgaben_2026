# Exercise 33 – String Operations with `<string.h>`

## Topic
String Library (`<string.h>`)

## Objective
Practise the most commonly used C standard string functions and understand their behaviour and edge cases.

## Instructions

1. Create `string_lib.c` and `#include <string.h>`, `#include <stdio.h>`.

2. Demonstrate each function with short examples and print the result:

   | Function | Task |
   |----------|------|
   | `strlen`   | Length of `"programming"` |
   | `strcpy`   | Copy `"hello"` into a buffer, modify the copy, show original is unchanged |
   | `strncpy`  | Copy only first 3 chars of `"abcde"` into a 10-char buffer (zero-pad rest) |
   | `strcat`   | Concatenate `"Hello, "` and `"World!"` |
   | `strncat`  | Append at most 4 chars of `"!!!"` to `"C is great"` |
   | `strcmp`   | Compare `"apple"` vs `"banana"`, `"same"` vs `"same"` |
   | `strchr`   | Find first `'o'` in `"root"` |
   | `strrchr`  | Find last  `'o'` in `"root"` |
   | `strstr`   | Find `"world"` in `"hello world"` |
   | `strtok`   | Tokenise `"one,two,three,four"` by `","` |
   | `memset`   | Fill a 10-char buffer with `'*'` |
   | `memcpy`   | Copy 5 bytes of an int array |

3. For each line, print the function name, the input, and the result.

## Hints
- `strcpy`/`strcat` do not check bounds — always ensure the destination buffer is large enough.
- `strtok` modifies the original string and is **not** re-entrant.
- `strncpy` does **not** guarantee null-termination if `src` is longer than `n` — add `'\0'` manually.
