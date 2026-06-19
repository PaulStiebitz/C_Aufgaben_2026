# Exercise 60 – Generic Struct Sort with Configurable Comparator Table

## Topic
Structs + Sorting + Function Pointer Tables

## Objective
Build a **configurable sort system** where the sort key and direction are chosen at runtime using a table of named comparators.

---

## Instructions

1. Create `sort_generic.c`.

2. Define:
   ```c
   typedef struct {
       int   id;
       char  name[40];
       char  country[30];
       int   year_born;
       float rating;
   } Athlete;
   ```

3. Define a comparator registry:
   ```c
   typedef struct {
       const char *label;
       int (*cmp)(const void *, const void *);
   } SortOption;
   ```
   Populate an array `SortOption sort_options[]` with at least 5 entries:
   - `"id_asc"`, `"name_asc"`, `"country_asc"`, `"rating_desc"`, `"age_asc"` (youngest = highest `year_born`).

4. Implement a lookup function:
   ```c
   int (*find_comparator(const char *label))(const void*, const void*);
   ```
   Returns the comparator function pointer for the given label, or `NULL` if not found.

5. In `main`:
   - Create an array of 6 `Athlete` structs.
   - Accept a **sort key** from the user:
     - Either hard-code a loop over all sort options (for testing), OR
     - Read a sort key from `argv[1]` (combine with exercise 52).
   - For each sort option: copy the array, sort the copy, print.

6. Implement `void print_athletes(const Athlete *arr, int n);`.

---

## Expected Output (example)
```
Available sort options: id_asc, name_asc, country_asc, rating_desc, age_asc

--- Sorted by: name_asc ---
[3] Alice  Germany  2001  9.25
[1] Bob    France   1998  8.70
...

--- Sorted by: rating_desc ---
[3] Alice  Germany  2001  9.25
[5] Carol  Brazil   2000  9.10
...

--- Sorted by: age_asc (youngest first) ---
[3] Alice  Germany  2001  9.25
...
```

---

## Hints
- Copy the array before each sort: `Athlete copy[N]; memcpy(copy, arr, sizeof(arr));`
- A function-pointer table lets you select sort behaviour without a chain of `if/else`.
- `find_comparator` loops over `sort_options` and uses `strcmp` to find a match.
- Extending the sort system later requires only adding one entry to the `sort_options` table.
