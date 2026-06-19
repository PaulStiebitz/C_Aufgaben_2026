# Exercise 47 – Implement a Simple Hash Map

## Topic
Arrays + Structs + Pointers + Hashing

## Objective
Build a basic hash map (dictionary) that maps string keys to integer values using an array of linked-list buckets (separate chaining).

## Instructions

1. Create `hashmap.c`.

2. Define:
   ```c
   #define BUCKET_COUNT 16

   typedef struct Entry {
       char         key[64];
       int          value;
       struct Entry *next;
   } Entry;

   typedef struct { Entry *buckets[BUCKET_COUNT]; int size; } HashMap;
   ```

3. Implement:
   - `unsigned int hash(const char *key);`
     Simple hash: sum all char values, multiply by 31, then `% BUCKET_COUNT`.
   - `void hmap_init(HashMap *m);`
   - `void hmap_put(HashMap *m, const char *key, int value);`
     Inserts or **updates** existing key.
   - `int  hmap_get(const HashMap *m, const char *key, int *out_value);`
     Returns 1 if found (writes to `*out_value`), 0 if not found.
   - `void hmap_delete(HashMap *m, const char *key);`
   - `void hmap_print(const HashMap *m);` – print each bucket's chain.
   - `void hmap_free(HashMap *m);`

4. In `main`:
   - Insert: `{"apple":3, "banana":7, "cherry":1, "apple":5}` (update "apple").
   - Get "banana" and "grape" (not found).
   - Delete "cherry".
   - Print map.

## Expected Output (example)
```
put apple=3, put banana=7, put cherry=1, update apple=5
get banana -> 7
get grape  -> not found
delete cherry
--- HashMap ---
bucket[2]: apple=5
bucket[9]: banana=7
```

## Hints
- Hash function with `djb2` or simple sum both work for this exercise.
- Chaining means each bucket is a linked list — collisions just add nodes.
- `hmap_put` must check if the key already exists before inserting a new node.
