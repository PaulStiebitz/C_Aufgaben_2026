# Exercise 38 – Generic Sorting with Function Pointers (qsort)

## Topic
Pointers (Function Pointers) + Standard Library

## Objective
Use the standard library `qsort` with custom comparator functions, and understand how function pointers enable generic algorithms.

## Instructions

1. Create `generic_sort.c`. Use `<stdlib.h>` and `<string.h>`.

2. Define:
   ```c
   typedef struct { char name[30]; int age; float score; } Person;
   ```

3. Implement the following comparator functions (signature: `int cmp(const void*, const void*)`):
   - `int cmp_int_asc(const void *a, const void *b);`
   - `int cmp_int_desc(const void *a, const void *b);`
   - `int cmp_person_by_name(const void *a, const void *b);`
   - `int cmp_person_by_age(const void *a, const void *b);`
   - `int cmp_person_by_score_desc(const void *a, const void *b);`

4. In `main`:
   - Sort an int array `{5,2,8,1,9,3}` ascending then descending, print both.
   - Create an array of 4 `Person` structs, sort by name, then by age, then by score (desc), print each.

5. Write `void print_persons(const Person *arr, int n);`.

## Expected Output (example)
```
Ascending:  1 2 3 5 8 9
Descending: 9 8 5 3 2 1

By name:  Alice Bob Charlie Diana
By age:   Diana(19) Alice(21) Bob(23) Charlie(25)
By score: Charlie(98.0) Alice(95.5) Diana(91.0) Bob(88.5)
```

## Hints
- `qsort(arr, count, elem_size, comparator)` — always pass `sizeof(element)` for `elem_size`.
- Inside the comparator, cast `const void *` to the actual pointer type.
- For floats, avoid direct subtraction in comparators — subtraction may silently truncate to 0.
