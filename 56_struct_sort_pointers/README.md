# Exercise 56 – Sorting an Array of Struct Pointers

## Topic
Structs + Pointers + Sorting

## Objective
Instead of sorting the structs themselves (which copies large objects), sort an **array of pointers** to structs — a common performance optimization.

---

## Background

When structs are large, copying them during sorting is expensive.  
A better approach: keep the struct array untouched, and sort a separate `pointer array`:

```
structs:   [Alice][Bob][Charlie][Diana]   <- never moved
pointers:  [ *3 ][ *1 ][ *0  ][ *2  ]   <- sorted by name
```

---

## Instructions

1. Create `sort_pointers.c`.

2. Define:
   ```c
   typedef struct {
       int   id;
       char  name[50];
       char  city[30];
       float balance;
   } Account;
   ```

3. Create an array of **7 `Account` structs** on the stack.

4. Create a separate array `Account *ptrs[7]` and point each element to the corresponding struct.

5. Implement comparators that operate on `Account **` (pointer-to-pointer):
   - `int cmp_ptr_by_name(const void *a, const void *b);`
   - `int cmp_ptr_by_balance_desc(const void *a, const void *b);`
   - `int cmp_ptr_by_city_then_name(const void *a, const void *b);`

6. Implement `void print_accounts_via_ptrs(Account **ptrs, int n);`.

7. In `main`:
   - Print via original pointer array (unsorted).
   - Sort `ptrs` by name, print.
   - Sort `ptrs` by balance descending, print.
   - Verify the original `Account` array is **unchanged** (print `structs[0]`).

---

## Comparator Pattern for Pointer Arrays
```c
int cmp_ptr_by_name(const void *a, const void *b) {
    // a and b are pointers to elements of the ptr array, i.e. Account**
    const Account *pa = *(const Account **)a;
    const Account *pb = *(const Account **)b;
    return strcmp(pa->name, pb->name);
}
```

---

## Expected Output (example)
```
--- Unsorted ---
[101] Bob     Berlin   €1200.00
[102] Alice   Munich   €3400.00
...

--- By Name ---
[102] Alice   Munich   €3400.00
[101] Bob     Berlin   €1200.00
...

--- By Balance DESC ---
[105] Frank   ...      €9900.00
...

Original structs[0] unchanged: [101] Bob Berlin €1200.00
```

---

## Hints
- Double-dereference: `*(const Account **)a` extracts the `Account*` from the void ptr pointing to an element of the `Account*[]` array.
- This technique is used in the real world whenever elements are large or frequently re-sorted.
