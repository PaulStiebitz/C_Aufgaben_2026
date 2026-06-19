# Exercise 06 – Bubble Sort

## Topic
Sorting Algorithms

## Objective
Implement the **Bubble Sort** algorithm from scratch and understand its time complexity.

## Instructions

1. Create `bubblesort.c` with a `main` function.

2. Implement the function:
   ```c
   void bubble_sort(int *arr, int n);
   ```
   - Repeatedly compare adjacent elements and swap them if they are in the wrong order.
   - After each full pass, the largest unsorted element is "bubbled" to its correct position.
   - **Optimization**: stop early if no swaps occurred during a pass (add a `swapped` flag).

3. In `main`:
   - Define an integer array of at least 10 elements.
   - Print the array **before** sorting.
   - Call `bubble_sort`.
   - Print the array **after** sorting.

4. Add a helper function `void print_array(const int *arr, int n);`.

## Expected Output (example, array = {64,34,25,12,22,11,90})
```
Before: 64 34 25 12 22 11 90
After:  11 12 22 25 34 64 90
```

## Questions to Consider (no need to answer in code)
- What is the worst-case time complexity of Bubble Sort?
- How does the `swapped` optimization affect best-case performance?
- In what situations is Bubble Sort a reasonable choice?
