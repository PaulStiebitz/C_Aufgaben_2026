# Exercise 08 – Insertion Sort

## Topic
Sorting Algorithms

## Objective
Implement the **Insertion Sort** algorithm, which builds the sorted array one element at a time.

## Instructions

1. Create `insertionsort.c`.

2. Implement:
   ```c
   void insertion_sort(int *arr, int n);
   ```
   - Start from index 1.
   - Store the current element as `key`.
   - Shift all larger elements in the sorted part one position to the right.
   - Insert `key` at the correct position.

3. In `main`:
   - Use an array of at least 10 elements.
   - Print the array state after **each insertion step** to show how the sorted region grows.

4. Add `void print_array(const int *arr, int n);`.

## Expected Output (example, array = {5,2,4,6,1,3})
```
Initial:  5 2 4 6 1 3
Step 1:   2 5 4 6 1 3
Step 2:   2 4 5 6 1 3
Step 3:   2 4 5 6 1 3
Step 4:   1 2 4 5 6 3
Step 5:   1 2 3 4 5 6
Sorted:   1 2 3 4 5 6
```

## Questions to Consider
- When is Insertion Sort faster than Bubble Sort in practice?
- What is the best-case time complexity and when does it occur?
