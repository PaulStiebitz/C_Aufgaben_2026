# Exercise 87 – Sparse Matrix (Linked List of Structs)

## Topic
Linked Lists + Structs + 2D Data

## Objective
Represent a sparse matrix (most elements are zero) efficiently using a linked list of non-zero entries instead of a full 2D array.

---

## Instructions

1. Create `sparse_matrix.c`.

2. Define:
   ```c
   typedef struct Entry {
       int          row;
       int          col;
       double       value;
       struct Entry *next;
   } Entry;

   typedef struct {
       int    rows;
       int    cols;
       Entry *head;
       int    nnz;   /* number of non-zero elements */
   } SparseMatrix;
   ```

3. Implement:
   ```c
   SparseMatrix* sm_create(int rows, int cols);
   void sm_set(SparseMatrix *m, int row, int col, double value);
   /* Insert or update (row,col). If value==0, remove the entry. */

   double sm_get(const SparseMatrix *m, int row, int col);
   /* Returns 0.0 if not present */

   void sm_print_dense(const SparseMatrix *m);
   /* Prints full matrix including zeros for visual verification */

   void sm_print_sparse(const SparseMatrix *m);
   /* Prints only non-zero entries: "(row,col): value" */

   SparseMatrix* sm_add(const SparseMatrix *a, const SparseMatrix *b);
   /* Returns a new matrix = a + b. Dimensions must match. */

   void sm_free(SparseMatrix *m);
   ```

4. In `main`:
   - Create a 4×4 sparse matrix, set a few values.
   - Print sparse and dense views.
   - Create a second 4×4 matrix.
   - Add them; print the result.
   - Call `sm_get` for existing and non-existing positions.

---

## Expected Output (example)
```
Matrix A (4x4, nnz=3):
Sparse: (0,2):5.0  (1,1):3.0  (3,0):8.0
Dense:
  0.0  0.0  5.0  0.0
  0.0  3.0  0.0  0.0
  0.0  0.0  0.0  0.0
  8.0  0.0  0.0  0.0

sm_get(0,2) = 5.0
sm_get(2,3) = 0.0

A + B:
Dense:
  1.0  0.0  5.0  0.0
  ...
```

---

## Hints
- Keep entries sorted by (row, col) for consistent output — insert in order.
- `sm_set` must find the entry by traversing; if found, update; if not found, insert in sorted position.
- `sm_add` can iterate through both lists simultaneously (like merge) since they're sorted.
