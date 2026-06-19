# Exercise 09 – Merge Sort

## Topic
Sorting Algorithms (Divide & Conquer)

## Objective
Implement **Merge Sort** recursively and understand divide-and-conquer sorting.

## Instructions

1. Create `mergesort.c`.

2. Implement two functions:
   ```c
   void merge(int *arr, int left, int mid, int right);
   void merge_sort(int *arr, int left, int right);
   ```
   - `merge_sort` splits the array at the midpoint and recursively sorts both halves.
   - `merge` merges two sorted sub-arrays `arr[left..mid]` and `arr[mid+1..right]` into a single sorted segment.
   - Use a **temporary array** inside `merge` for the merge step.

3. In `main`:
   - Declare an array of at least 10 elements.
   - Print before and after sorting.

4. Add `void print_array(const int *arr, int n);`.

## Expected Output (example, array = {38,27,43,3,9,82,10})
```
Before: 38 27 43 3 9 82 10
After:   3  9 10 27 38 43 82
```

## Hints
- The base case for `merge_sort` is when `left >= right`.
- Use `int mid = left + (right - left) / 2;` to avoid integer overflow.
- Allocate the temporary buffer with `malloc` or declare it statically.

## Questions to Consider
- What is the time complexity of Merge Sort (best, average, worst)?
- What extra memory does Merge Sort require?
