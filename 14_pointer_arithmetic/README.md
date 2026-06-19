# Exercise 14 – Pointer Arithmetic and Arrays

## Topic
Pointers

## Objective
Understand the relationship between pointers and arrays by traversing and modifying arrays using pointer arithmetic instead of index notation.

## Instructions

1. Create `pointer_arithmetic.c`.

2. Declare an integer array of 8 elements.

3. Implement the following functions using **only pointer arithmetic** (no `[]` indexing):
   - `void print_with_pointer(const int *ptr, int n)` – traverses and prints using `*(ptr + i)`.
   - `void double_values(int *ptr, int n)` – multiplies each element by 2.
   - `int pointer_sum(const int *ptr, int n)` – returns the sum using a `while` loop and advancing the pointer.
   - `int *find_value(int *ptr, int n, int target)` – returns a pointer to the first occurrence of `target`, or `NULL` if not found.

4. Demonstrate all functions in `main`. For `find_value`, print the found element's **index** (compute it as `result - arr`).

## Expected Output (example, array = {4,8,15,16,23,42,4,2})
```
Original:     4  8 15 16 23 42  4  2
Sum:          114
Doubled:      8 16 30 32 46 84  8  4
Find 30:      index 2 -> value 30
Find 99:      not found
```

## Hints
- `ptr++` advances the pointer by `sizeof(int)` bytes automatically.
- The difference `found_ptr - arr` gives the zero-based index.
- Dereferencing `NULL` causes undefined behaviour — always check before using.
