# Exercise 15 – Dynamic Memory Allocation

## Topic
Pointers + Dynamic Memory

## Objective
Practice allocating, using, and freeing heap memory with `malloc`, `calloc`, and `realloc`.

## Instructions

1. Create `dynamic_memory.c`.

2. **Part A – malloc**:
   - Ask the user how many integers to store (read at runtime).
   - Allocate an array of that size using `malloc`.
   - Fill it with values `1, 2, 3, ..., n`.
   - Print the array.
   - Free the memory.

3. **Part B – calloc**:
   - Allocate an array of 5 doubles using `calloc`.
   - Print all values (they should all be `0.0`).
   - Set each element to `i * 1.5`.
   - Print again.
   - Free the memory.

4. **Part C – realloc**:
   - Start with a `malloc` of 3 integers: `{10, 20, 30}`.
   - Use `realloc` to grow the array to 6 integers.
   - Add `{40, 50, 60}` to the new slots.
   - Print the full array.
   - Free.

5. Always check that the result of `malloc`/`calloc`/`realloc` is not `NULL`.

## Expected Output (example, n=4)
```
Part A: 1 2 3 4
Part B (zeroed): 0.0 0.0 0.0 0.0 0.0
Part B (filled): 0.0 1.5 3.0 4.5 6.0
Part C: 10 20 30 40 50 60
```

## Hints
- `malloc(n * sizeof(int))` — always multiply by `sizeof`.
- `calloc(n, sizeof(double))` — zeroes memory automatically.
- `realloc` may return a different pointer; always reassign: `ptr = realloc(ptr, new_size);`.
- `free(NULL)` is safe and does nothing.
