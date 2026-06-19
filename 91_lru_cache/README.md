# Exercise 91 – LRU Cache

## Topic
Doubly Linked List + Hash Map + Structs

## Objective
Implement a **Least-Recently-Used (LRU) cache** — a fixed-capacity key-value store that evicts the least recently accessed item when full.

---

## Instructions

1. Create `lru_cache.c`.

2. Define (integer key → integer value):
   ```c
   #define LRU_CAP 4
   #define HASH_SIZE 8

   typedef struct CacheNode {
       int              key;
       int              value;
       struct CacheNode *prev;
       struct CacheNode *next;
   } CacheNode;

   typedef struct {
       CacheNode *head;     /* most recently used */
       CacheNode *tail;     /* least recently used */
       CacheNode *table[HASH_SIZE]; /* hash map: key -> node */
       int        size;
       int        capacity;
   } LRUCache;
   ```

3. Implement:
   ```c
   void lru_init(LRUCache *c, int capacity);

   int  lru_get(LRUCache *c, int key);
   /* Returns value if found (and moves node to front). Returns -1 if not found. */

   void lru_put(LRUCache *c, int key, int value);
   /* Insert or update. If full, evict the tail (LRU) before inserting. */

   void lru_print(const LRUCache *c);
   /* Print from MRU to LRU: key:value -> key:value -> ... */

   void lru_free(LRUCache *c);
   ```

4. Hash function: `key % HASH_SIZE` (chaining for collisions).

5. In `main`:
   ```
   put(1,10), put(2,20), put(3,30), put(4,40)
   get(1)     -> moves 1 to front
   put(5,50)  -> evicts LRU (which is now 2)
   get(2)     -> returns -1 (evicted)
   print      -> 5:50 1:10 4:40 3:30
   ```

---

## Expected Output
```
put(1,10) put(2,20) put(3,30) put(4,40)
Cache: 4:40 3:30 2:20 1:10

get(1) = 10
Cache: 1:10 4:40 3:30 2:20

put(5,50) -> evict LRU: 2
Cache: 5:50 1:10 4:40 3:30

get(2) = -1 (not found)
```

---

## Hints
- The doubly linked list keeps track of recency (head = most recent, tail = least recent).
- The hash map provides O(1) lookup by key.
- On `lru_get`: detach the node from its position, reattach at the head.
- On `lru_put` when full: `free` the tail node and remove it from the hash map, then insert the new node at the head.
