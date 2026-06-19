# Exercise 11 – Array Basics: Declaration, Traversal & Modification

## Topic
Arrays

## Objective
Practice declaring, initializing, and traversing 1D arrays using loops and pointers.

## Instructions

1. Create `arrays_basic.c`.

2. Declare and initialize an integer array of 10 elements with values of your choice.

3. Implement and call the following (write each as a separate function):
   - `void print_array(const int *arr, int n)` – prints all elements space-separated.
   - `int sum(const int *arr, int n)` – returns the sum of all elements.
   - `int find_max(const int *arr, int n)` – returns the largest element.
   - `int find_min(const int *arr, int n)` – returns the smallest element.
   - `void reverse_array(int *arr, int n)` – reverses the array in-place.

4. Print the original array, then sum, max, min, then the reversed array.

## Expected Output (example, array = {3,7,1,9,4,6,2,8,5,0})
```
Original: 3 7 1 9 4 6 2 8 5 0
Sum:      45
Max:      9
Min:      0
Reversed: 0 5 8 2 6 4 9 1 7 3
```

## Hints
- Use `sizeof(arr) / sizeof(arr[0])` **only** in the same scope where the array is declared.
- Pass the length `n` as a parameter to all functions.
