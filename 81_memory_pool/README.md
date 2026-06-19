# Exercise 81 – Memory Pool Allocator

## Topic
Pointers + Dynamic Memory + Structs

## Objective
Implement a simple fixed-size memory pool that pre-allocates a large block and dispenses fixed-size chunks — avoiding repeated `malloc`/`free` calls.

---

## Instructions

1. Create `mempool.c`.

2. Define:
   ```c
   #define POOL_CAPACITY 64

   typedef struct {
       char  *buffer;           /* the big pre-allocated block */
       int    chunk_size;       /* size of each chunk in bytes */
       int    capacity;         /* total number of chunks */
       int    used;             /* number of currently allocated chunks */
       char  *free_list[POOL_CAPACITY]; /* pointers to free chunks */
       int    free_count;
   } MemPool;
   ```

3. Implement:
   ```c
   int   pool_init(MemPool *p, int chunk_size, int capacity);
   void* pool_alloc(MemPool *p);       /* returns next free chunk, NULL if full */
   void  pool_free(MemPool *p, void *ptr); /* returns chunk to free list */
   void  pool_destroy(MemPool *p);     /* frees the underlying buffer */
   void  pool_stats(const MemPool *p); /* print used/free/capacity */
   ```

4. In `main`:
   - Create a pool of 8 chunks, each `sizeof(int)*4 = 16` bytes.
   - Allocate 6 chunks, write data into each.
   - Print stats.
   - Free 2 chunks.
   - Allocate 3 more (should reuse freed slots).
   - Print stats.
   - Try allocating when full.
   - Destroy pool.

---

## Expected Output
```
Pool created: 8 chunks x 16 bytes = 128 bytes
Allocated 6 chunks.
Stats: used=6, free=2, capacity=8

Freed 2 chunks.
Stats: used=4, free=4, capacity=8

Allocated 3 more.
Stats: used=7, free=1, capacity=8

Allocate when full (8/8): NULL (pool exhausted)
Pool destroyed.
```

---

## Hints
- `pool_init`: call `malloc(chunk_size * capacity)`, then push all chunk addresses onto `free_list`.
- `pool_alloc`: pop from `free_list` (decrement `free_count`, return `free_list[free_count]`).
- `pool_free`: push back onto `free_list`.
- This avoids heap fragmentation and is faster than `malloc` for many small, same-sized allocations.
