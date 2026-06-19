# Exercise 04 – Create a Statistics Library

## Topic
Custom Libraries (`.h` / `.c`)

## Objective
Create a library that performs basic statistical computations on an array of `double` values.

## Instructions

1. Create `stats.h` with include guards and declare:
   - `double stats_min(const double *arr, int n);`
   - `double stats_max(const double *arr, int n);`
   - `double stats_sum(const double *arr, int n);`
   - `double stats_mean(const double *arr, int n);`
   - `double stats_variance(const double *arr, int n);`
   - `double stats_stddev(const double *arr, int n);`

2. Implement all functions in `stats.c`.
   - Variance formula: `Σ(xᵢ - mean)² / n`
   - Standard deviation: `sqrt(variance)`

3. Write `main.c` that defines a sample array, calls all functions, and prints the results.

4. Compile and link (remember `-lm` for `sqrt`).

## Expected Output (example, array = {2, 4, 4, 4, 5, 5, 7, 9})
```
Min      = 2.00
Max      = 9.00
Sum      = 40.00
Mean     = 5.00
Variance = 4.00
Std Dev  = 2.00
```

## Hints
- Pass the array length `n` explicitly since C does not know the size of a passed array.
- `stats_stddev` can simply call `stats_variance` internally.
