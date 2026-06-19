# Exercise 55 – Sorting Structs by Multiple Fields (Multi-Key Sort)

## Topic
Structs + Sorting + Comparator Chaining

## Objective
Sort structs using **multi-key comparators** where ties in the primary key are resolved by a secondary (and tertiary) key — just like SQL's `ORDER BY col1, col2`.

---

## Instructions

1. Create `sort_multikey.c`.

2. Define:
   ```c
   typedef struct {
       char  department[30];
       char  name[40];
       int   age;
       float gpa;
   } Student;
   ```

3. Create an array of **8 students** where several students share the same `department` and some also share the same `gpa`.

4. Implement these comparators:
   - `int cmp_dept_then_name(const void *a, const void *b);`
     Primary: `department` alphabetically; Secondary: `name` alphabetically.
   - `int cmp_dept_then_gpa_desc(const void *a, const void *b);`
     Primary: `department` alphabetically; Secondary: `gpa` descending (best first).
   - `int cmp_dept_then_gpa_then_age(const void *a, const void *b);`
     Primary: `department`; Secondary: `gpa` descending; Tertiary: `age` ascending.

5. Write `void print_students(const Student *arr, int n);`.

6. In `main`: print original, then each sorted version with a header.

---

## Multi-Key Comparator Pattern
```c
int cmp_dept_then_name(const void *a, const void *b) {
    const Student *sa = (const Student *)a;
    const Student *sb = (const Student *)b;

    int r = strcmp(sa->department, sb->department); // primary key
    if (r != 0) return r;                           // different dept? done.
    return strcmp(sa->name, sb->name);              // same dept? compare name
}
```

---

## Expected Output (example)
```
--- By Department, then Name ---
CS      Alice   20  3.90
CS      Bob     22  3.50
CS      Charlie 21  3.70
Math    Diana   23  3.80
Math    Eve     20  3.60

--- By Department, then GPA desc ---
CS      Alice   20  3.90
CS      Charlie 21  3.70
CS      Bob     22  3.50
Math    Diana   23  3.80
Math    Eve     20  3.60

--- By Department, then GPA desc, then Age asc ---
(ties in GPA broken by younger age first)
```

---

## Hints
- The pattern `if (r != 0) return r; return next_comparison;` is the standard multi-key idiom.
- For descending secondary sort: negate: `return -cmp_gpa(a, b);` or flip operands.
- You can chain as many levels as needed.
