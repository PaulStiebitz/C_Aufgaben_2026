# Exercise 96 – Library: Dynamic String Array

## Topic
Custom Library + Dynamic Memory + Strings

## Objective
Build a reusable `strarray` library that manages a dynamically-growing array of heap-allocated strings with full CRUD and set operations.

---

## Instructions

1. Create `strarray.h` and `strarray.c`.

2. Define:
   ```c
   typedef struct {
       char  **items;
       int     count;
       int     capacity;
   } StrArray;
   ```

3. Implement:
   ```c
   void strarray_init(StrArray *a, int initial_capacity);
   void strarray_free(StrArray *a);

   void strarray_push(StrArray *a, const char *s);    /* heap-copy + append */
   void strarray_insert(StrArray *a, int idx, const char *s);
   void strarray_remove(StrArray *a, int idx);        /* free + shift left */

   int  strarray_find(const StrArray *a, const char *s);   /* -1 if not found */
   int  strarray_contains(const StrArray *a, const char *s);

   void strarray_sort_asc(StrArray *a);
   void strarray_sort_desc(StrArray *a);
   void strarray_reverse(StrArray *a);

   void strarray_print(const StrArray *a);
   void strarray_join(const StrArray *a, const char *sep, char *out, size_t out_size);
   /* joins all strings with separator into out */

   StrArray strarray_filter(const StrArray *a, int (*pred)(const char *));
   /* returns new StrArray containing only elements where pred returns 1 */

   StrArray strarray_unique(const StrArray *a);
   /* returns new StrArray with duplicate strings removed (preserves first occurrence) */
   ```

4. In `main.c`:
   - Push 8 strings (some duplicates).
   - Sort ascending, print.
   - Filter: only strings of length > 4, print.
   - Unique, print.
   - Join with `", "`, print the result string.
   - Remove index 2, insert `"newitem"` at index 0.

---

## Expected Output (example)
```
Original: banana apple cherry apple date elderberry fig apple
Sorted:   apple apple apple banana cherry date elderberry fig
Unique:   apple banana cherry date elderberry fig
Filter (len>4): banana apple cherry elderberry
Joined: "apple, apple, apple, banana, cherry, date, elderberry, fig"
```

---

## Hints
- `strarray_push`: if full, `realloc` to double capacity; then `strdup(s)` (or `malloc+strcpy`) to store a copy.
- `strarray_remove`: `free(items[idx])`, shift remaining items left, decrement count.
- `strarray_filter` / `strarray_unique` return **new** `StrArray`s — caller must `strarray_free` them.
- `strarray_join`: compute total length first, then `malloc` + build with `strcat` or `memcpy`.
