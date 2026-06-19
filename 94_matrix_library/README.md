# Exercise 94 – Matrix Library (`.h` / `.c`)

## Topic
Custom Library + 2D Arrays + Dynamic Memory + File I/O

## Objective
Build a complete dynamically-allocated matrix library with all standard operations, split into header and implementation files.

---

## Instructions

1. Create `matrix.h` and `matrix.c`.

2. Define:
   ```c
   typedef struct {
       double **data;
       int      rows;
       int      cols;
   } Matrix;
   ```

3. Implement (all in `matrix.c`, declared in `matrix.h`):
   ```c
   Matrix* mat_create(int rows, int cols);          /* alloc, zero-init */
   Matrix* mat_create_identity(int n);              /* n×n identity matrix */
   void    mat_free(Matrix *m);
   void    mat_set(Matrix *m, int r, int c, double v);
   double  mat_get(const Matrix *m, int r, int c);
   void    mat_print(const Matrix *m);

   Matrix* mat_add(const Matrix *a, const Matrix *b);
   Matrix* mat_sub(const Matrix *a, const Matrix *b);
   Matrix* mat_mul(const Matrix *a, const Matrix *b);
   Matrix* mat_transpose(const Matrix *m);
   Matrix* mat_scale(const Matrix *m, double scalar);

   int     mat_equals(const Matrix *a, const Matrix *b, double eps);
   /* element-wise comparison within epsilon tolerance */

   double  mat_trace(const Matrix *m);     /* sum of diagonal elements */
   double  mat_frobenius(const Matrix *m); /* sqrt(sum of squares of all elements) */

   int     mat_save_csv(const Matrix *m, const char *filename);
   Matrix* mat_load_csv(const char *filename); /* returns newly allocated matrix */
   ```

4. Write `main.c` that:
   - Creates two 3×3 matrices.
   - Demonstrates all operations.
   - Saves to CSV, loads back, verifies equality.

---

## Expected Output (example)
```
A:              B:
1 2 3           9 8 7
4 5 6           6 5 4
7 8 9           3 2 1

A + B:          A * B:
10 10 10        30 24 18
10 10 10        84 69 54
10 10 10       138 114 90

Transpose(A):   Scale(A, 2.0):
1 4 7           2  4  6
2 5 8           8 10 12
3 6 9          14 16 18

Identity(3):    trace(A) = 15.00
1 0 0           frobenius(A) = 16.88
0 1 0
0 0 1

A == A: 1    A == B: 0

Saved A to a.csv. Loaded back. A == loaded: 1
```

---

## Hints
- `double **data`: allocate as `malloc(rows * sizeof(double*))`, then each row: `malloc(cols * sizeof(double))`.
- `mat_free` must free each row pointer, then the pointer array, then the struct.
- Matrix multiply: `result[i][j] += a->data[i][k] * b->data[k][j]` for all k.
- CSV save: one row per line, values comma-separated; first line can optionally store `rows,cols`.
