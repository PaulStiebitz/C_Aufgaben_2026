# Exercise 10 – Quick Sort & Heap Sort

## Topic
Sorting Algorithms (Advanced)

## Objective
Implement both **Quick Sort** and **Heap Sort** and compare their approaches.

## Instructions

### Part A – Quick Sort

1. Implement:
   ```c
   int partition(int *arr, int low, int high);
   void quick_sort(int *arr, int low, int high);
   ```
   - Use the **last element** as the pivot.
   - `partition` rearranges elements so all values ≤ pivot are to its left.
   - `quick_sort` recursively sorts the two sub-arrays.

### Part B – Heap Sort

2. Implement:
   ```c
   void heapify(int *arr, int n, int i);
   void heap_sort(int *arr, int n);
   ```
   - `heapify` ensures the subtree rooted at index `i` satisfies the max-heap property.
   - `heap_sort`: first **build** a max-heap (call `heapify` from `n/2-1` down to `0`), then repeatedly extract the max by swapping `arr[0]` with `arr[n-1]` and re-heapifying.

3. In `main`:
   - Test both algorithms on the **same** array (use a copy for the second sort).
   - Print results of both.

## Expected Output (example, array = {12,11,13,5,6,7})
```
Quick Sort:  5  6  7 11 12 13
Heap Sort:   5  6  7 11 12 13
```

## Questions to Consider
- What is the worst-case for Quick Sort and how can it be avoided?
- Why does Heap Sort have guaranteed O(n log n) performance?
