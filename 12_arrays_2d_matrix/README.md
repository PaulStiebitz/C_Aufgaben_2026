# Exercise 12 – 2D Arrays and Matrix Operations

## Topic
Arrays (2D)

## Objective
Work with two-dimensional arrays representing matrices and implement basic matrix operations.

## Instructions

1. Create `matrix.c`.

2. Define `#define ROWS 3` and `#define COLS 3` at the top.

3. Implement the following functions:
   - `void print_matrix(int m[ROWS][COLS])` – prints the matrix in a grid.
   - `void add_matrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS])` – element-wise addition.
   - `void multiply_matrices(int a[ROWS][COLS], int b[ROWS][COLS], int result[ROWS][COLS])` – matrix multiplication.
   - `void transpose(int m[ROWS][COLS], int result[ROWS][COLS])` – fills `result` with the transpose of `m`.

4. In `main`, declare two 3×3 matrices, demonstrate all four operations.

## Expected Output (example)
```
Matrix A:        Matrix B:
1 2 3            9 8 7
4 5 6            6 5 4
7 8 9            3 2 1

A + B:           A * B:
10 10 10         30 24 18
10 10 10         84 69 54
10 10 10        138 114 90

Transpose of A:
1 4 7
2 5 8
3 6 9
```

## Hints
- The matrix multiplication formula: `result[i][j] += a[i][k] * b[k][j]` for all valid `k`.
- Initialize `result` to all zeros before multiplying.
