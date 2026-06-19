# Exercise 43 – Recursive Functions with Pointers

## Topic
Pointers + Recursion

## Objective
Write recursive functions that operate on arrays and linked lists using pointers.

## Instructions

1. Create `recursion.c`.

2. Implement the following recursive functions:

   **Arrays:**
   - `int sum_recursive(const int *arr, int n);` – sum of all elements.
   - `int max_recursive(const int *arr, int n);` – maximum value.
   - `void print_reverse_recursive(const int *arr, int n);` – prints in reverse using recursion (no loop, no extra array).
   - `int binary_search(const int *arr, int low, int high, int target);` – returns index or -1.

   **Strings:**
   - `int strlen_recursive(const char *s);` – length without `strlen`.
   - `void strrev_recursive(char *s, int left, int right);` – reverse string in-place.
   - `int is_palindrome_recursive(const char *s, int left, int right);`

3. In `main`, test all functions with suitable examples.

## Expected Output (example)
```
Array: 3 1 4 1 5 9 2 6
sum    = 31
max    = 9
reverse: 6 2 9 5 1 4 1 3
binary_search(5) = index 4

strlen("recursion") = 9
strrev("hello")    = "olleh"
palindrome("racecar") = 1
palindrome("hello")   = 0
```

## Hints
- Each recursive call reduces the problem: `sum(arr, n) = arr[0] + sum(arr+1, n-1)`.
- Base case for `print_reverse_recursive`: `if (n == 0) return;` — print last, then recurse on `n-1`.
- For `binary_search`, the base case is `low > high` (return -1) or `arr[mid] == target` (return `mid`).
