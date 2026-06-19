# Exercise 54 – Sorting Structs by a Single Field

## Topic
Structs + Sorting + `qsort`

## Objective
Sort an array of structs by one field using both a manual bubble sort and `qsort` with a comparator function.

---

## Instructions

1. Create `sort_single.c`.

2. Define:
   ```c
   typedef struct {
       char  name[40];
       int   age;
       float salary;
   } Employee;
   ```

3. Initialize an array of **6 employees** with mixed values.

4. Implement sorting comparators for `qsort`:
   - `int cmp_by_age_asc(const void *a, const void *b);`
   - `int cmp_by_age_desc(const void *a, const void *b);`
   - `int cmp_by_salary_asc(const void *a, const void *b);`
   - `int cmp_by_name_asc(const void *a, const void *b);`

5. Also implement a manual **bubble sort** that sorts by `age` ascending (without `qsort`):
   ```c
   void bubble_sort_by_age(Employee *arr, int n);
   ```
   The swap must exchange the **entire struct**, not just one field.

6. Implement `void print_employees(const Employee *arr, int n);`.

7. In `main`:
   - Print original array.
   - Sort and print by age ascending (bubble sort).
   - Sort and print by age descending (`qsort`).
   - Sort and print by salary ascending (`qsort`).
   - Sort and print by name alphabetically (`qsort`).

---

## Expected Output (example)
```
--- Original ---
Bob     32  €4200.00
Alice   25  €5100.00
Diana   28  €3800.00
Charlie 35  €6200.00
Eve     22  €4500.00
Frank   30  €5500.00

--- By Age ASC (bubble sort) ---
Eve     22  €4500.00
Alice   25  €5100.00
Diana   28  €3800.00
Frank   30  €5500.00
Bob     32  €4200.00
Charlie 35  €6200.00

--- By Age DESC (qsort) ---
Charlie 35  €6200.00
...

--- By Salary ASC ---
Diana   28  €3800.00
...

--- By Name ASC ---
Alice   25  €5100.00
...
```

---

## Hints
- Swapping structs: `Employee tmp = arr[i]; arr[i] = arr[j]; arr[j] = tmp;` — C copies the whole struct.
- For float comparators, avoid direct subtraction (may truncate to 0). Use ternary: `return (a->salary > b->salary) ? 1 : (a->salary < b->salary) ? -1 : 0;`
- `qsort(arr, 6, sizeof(Employee), comparator)`.
