# Exercise 58 – Stable Sort and Index Sort

## Topic
Structs + Sorting + Stability

## Objective
Understand **sort stability** and implement an **index sort** that preserves the original order of equal elements.

---

## Background

A **stable sort** guarantees that elements with equal keys keep their original relative order.  
`qsort` in C is **not guaranteed to be stable**.

One portable solution: add an **original index** to the comparator so ties are broken by insertion order.

---

## Instructions

1. Create `stable_sort.c`.

2. Define:
   ```c
   typedef struct {
       char  name[30];
       int   score;
       int   original_index;  /* filled in before sorting */
   } Result;
   ```

3. Create an array of 8 `Result` structs where **4 students share the same score** of 85.

4. **Part A – Unstable `qsort`**:
   - Sort by `score` descending using a standard comparator (ignores `original_index`).
   - Print. Note that the relative order of the 4 tied students may vary.

5. **Part B – Stable sort via index tiebreak**:
   - Before sorting, fill `original_index` for each element: `arr[i].original_index = i;`
   - Write a comparator `int cmp_score_stable(const void *a, const void *b)`:
     - Primary: `score` descending.
     - Tiebreak: `original_index` ascending (preserves original order).
   - Sort and print. The 4 tied students must appear in their original order.

6. **Part C – Indirect index sort** (sort an index array, not the data):
   - Keep the `Result` array untouched.
   - Create `int indices[8] = {0,1,2,3,4,5,6,7};`
   - Sort `indices` using `qsort` with a comparator that compares `arr[*(int*)a].score`.
   - Print elements via `arr[indices[i]]` — the result array is never moved.

---

## Expected Output (example)
```
--- Part A (unstable, score desc) ---
Charlie  92
Alice    88
Diana    85   <- these four may appear in any order
Bob      85
Frank    85
Eve      85
...

--- Part B (stable, score desc, ties by original order) ---
Charlie  92
Alice    88
Diana    85   <- index 2 (first 85 in original)
Bob      85   <- index 3
Frank    85   <- index 5
Eve      85   <- index 6
...

--- Part C (index sort, data unchanged) ---
sorted indices: 0 1 2 3 5 6 ...
Print via indices: Charlie 92, Alice 88, Diana 85 ...
```

---

## Hints
- The tiebreak comparator: `if (sa->score != sb->score) return sb->score - sa->score; return sa->original_index - sb->original_index;`
- Index sort comparator needs a **global pointer** to the data array, or use a wrapper struct.
- Stable sort matters for UI (e.g., sorting a table by one column should not shuffle equal rows).
