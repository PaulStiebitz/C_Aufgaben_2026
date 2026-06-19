# Exercise 45 – Pointer-Based String Splitter & Joiner

## Topic
Pointers + Strings + Dynamic Memory

## Objective
Implement `split` and `join` functions that work on dynamically allocated arrays of string pointers.

## Instructions

1. Create `split_join.c`.

2. Implement:
   ```c
   /* Splits 'str' by 'delim' into dynamically allocated tokens.
      Stores the count in *out_count.
      Returns a heap-allocated array of heap-allocated strings. */
   char** str_split(const char *str, char delim, int *out_count);

   /* Joins an array of strings with 'separator' between them.
      Returns a heap-allocated result string. */
   char*  str_join(char **parts, int count, const char *separator);

   /* Frees the array returned by str_split. */
   void   str_split_free(char **parts, int count);
   ```

3. In `main`:
   - Split `"one:two:three:four:five"` by `':'`. Print each token and the count.
   - Join them back with `" | "`. Print the result.
   - Split a CSV line `"Alice,30,Berlin,3.8"` by `','`. Print each field.
   - Free all allocations.

## Expected Output
```
Split "one:two:three:four:five" by ':' -> 5 tokens:
  [0] one
  [1] two
  [2] three
  [3] four
  [4] five
Joined: "one | two | three | four | five"

CSV fields:
  [0] Alice
  [1] 30
  [2] Berlin
  [3] 3.8
```

## Hints
- `str_split`: make one pass to count delimiters, allocate `char**`, then iterate again copying each token using `malloc` + `strncpy`.
- `str_join`: first compute the total length needed (sum of all token lengths + separator lengths), then `malloc` and fill.
- Always `free` in the reverse order of allocation.
