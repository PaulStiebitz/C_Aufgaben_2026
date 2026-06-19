# Exercise 16 – Pointers to Pointers (Double Pointers)

## Topic
Pointers

## Objective
Understand double pointers (`int **`) and how they are used to modify a pointer from within a function.

## Instructions

1. Create `double_pointer.c`.

2. **Part A – Swap via pointer**:
   - Write `void swap(int *a, int *b)` that swaps two integers.
   - Demonstrate it in `main`.

3. **Part B – Modify a pointer inside a function**:
   - Write `void set_to_null(int **ptr)` that sets `*ptr = NULL`.
   - Write `void allocate_array(int **ptr, int n)` that allocates `n` ints on the heap and fills them `1..n`.
   - In `main`, declare `int *arr = NULL;`, call `allocate_array(&arr, 5)`, print the array, then call `set_to_null`... wait, free first, then set to null manually or via a function.

4. **Part C – Array of strings**:
   - Declare `char *words[] = {"apple", "banana", "cherry", "date", "elderberry"};`
   - Write `void print_strings(char **arr, int n)` that prints each string with its index.
   - Write `void sort_strings(char **arr, int n)` that sorts the strings alphabetically using bubble sort and `strcmp`.
   - Print before and after sorting.

## Expected Output (example)
```
swap: a=10, b=20 -> a=20, b=10
Allocated: 1 2 3 4 5
Before sort: apple banana cherry date elderberry
After sort:  apple banana cherry date elderberry
```

## Hints
- `char **arr` when used as an array of strings is a pointer to `char*` elements.
- When sorting strings in a `char*[]` array, swap the **pointers**, not the characters.
