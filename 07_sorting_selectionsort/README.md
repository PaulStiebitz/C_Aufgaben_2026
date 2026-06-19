# Exercise 07 – Selection Sort

## Topic
Sorting Algorithms

## Objective
Implement the **Selection Sort** algorithm and observe how it selects the minimum element in each pass.

## Instructions

1. Create `selectionsort.c`.

2. Implement the function:
   ```c
   void selection_sort(int *arr, int n);
   ```
   - Divide the array into a sorted (left) and unsorted (right) part.
   - In each iteration, find the **minimum** element in the unsorted part.
   - Swap it with the first element of the unsorted part.
   - Advance the boundary by one.

3. In `main`:
   - Declare an array of at least 10 integers.
   - Print the array before and after sorting.
   - Print which element is swapped in each iteration (for learning purposes).

4. Add `void print_array(const int *arr, int n);`.

## Expected Output (example, array = {29,10,14,37,13})
```
Before: 29 10 14 37 13
Pass 1: swap 29 <-> 10  => 10 29 14 37 13
Pass 2: swap 29 <-> 13  => 10 13 14 37 29
Pass 3: swap 14 <-> 14  => 10 13 14 37 29
Pass 4: swap 37 <-> 29  => 10 13 14 29 37
After:  10 13 14 29 37
```

## Questions to Consider
- How many comparisons does Selection Sort always make regardless of input order?
- What is the time complexity of Selection Sort?
