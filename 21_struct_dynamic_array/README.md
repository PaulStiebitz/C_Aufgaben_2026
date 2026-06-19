# Exercise 21 – Struct with Dynamic Array (Heap Allocation)

## Topic
Structs + Dynamic Memory

## Objective
Combine structs with heap-allocated arrays to build a dynamically growing data structure.

## Instructions

1. Create `struct_dynamic.c`.

2. Define a `Vector` struct that acts as a resizable integer array:
   ```c
   typedef struct {
       int   *data;
       int    size;
       int    capacity;
   } Vector;
   ```

3. Implement:
   - `void vector_init(Vector *v, int initial_capacity);` – allocates `data`, sets size=0.
   - `void vector_push(Vector *v, int value);` – appends value; if `size == capacity`, double the capacity with `realloc`.
   - `int  vector_get(const Vector *v, int index);` – returns element (check bounds, print error if out of range).
   - `void vector_print(const Vector *v);` – prints all elements.
   - `void vector_free(Vector *v);` – frees `data`, sets pointer to NULL.

4. In `main`:
   - Create a Vector with capacity 2.
   - Push 8 integers (forcing at least 2 reallocations).
   - Print the vector, capacity, and size.
   - Access an out-of-bounds index.
   - Free.

## Expected Output (example)
```
Pushed: 1 2 3 4 5 6 7 8
Size: 8, Capacity: 8
Vector: 1 2 3 4 5 6 7 8
Error: index 10 out of bounds (size=8)
```

## Hints
- `capacity` starts at 2, doubles: 2 → 4 → 8.
- Always save the `realloc` result to a **temporary pointer** and check for `NULL` before reassigning.
