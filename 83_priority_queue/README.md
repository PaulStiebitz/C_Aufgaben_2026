# Exercise 83 – Priority Queue (Min-Heap)

## Topic
Arrays + Structs + Heap Data Structure

## Objective
Implement a priority queue backed by a binary min-heap stored in an array.

---

## Instructions

1. Create `priority_queue.c`.

2. Define:
   ```c
   #define PQ_CAP 32

   typedef struct {
       int priority;   /* lower value = higher priority */
       char label[32];
   } PQItem;

   typedef struct {
       PQItem data[PQ_CAP];
       int    size;
   } PriorityQueue;
   ```

3. Min-heap property: `data[(i-1)/2].priority <= data[i].priority` for all `i > 0`.

4. Implement:
   ```c
   void pq_init(PriorityQueue *pq);
   int  pq_push(PriorityQueue *pq, int priority, const char *label);
   /* returns 0 ok; inserts at end, then sift up */

   PQItem pq_pop(PriorityQueue *pq);
   /* remove and return item with lowest priority value;
      swap root with last, reduce size, sift down */

   PQItem pq_peek(const PriorityQueue *pq); /* view min without removing */
   int    pq_is_empty(const PriorityQueue *pq);
   void   pq_print(const PriorityQueue *pq);  /* prints heap array, not sorted order */
   ```

5. Implement the heap helpers:
   ```c
   void sift_up(PriorityQueue *pq, int i);
   void sift_down(PriorityQueue *pq, int i);
   ```

6. In `main`:
   - Insert: `{5,"medium"}, {1,"critical"}, {3,"high"}, {7,"low"}, {2,"urgent"}`.
   - Pop all items — they should come out in priority order (1,2,3,5,7).

---

## Expected Output
```
Inserted 5 items.
Heap array: [1,critical] [2,urgent] [3,high] [5,medium] [7,low]

Pop sequence (lowest priority first):
  1 critical
  2 urgent
  3 high
  5 medium
  7 low
Queue is now empty.
```

---

## Hints
- Parent of index `i`: `(i-1)/2`. Children: `2*i+1` (left), `2*i+2` (right).
- `sift_up`: compare with parent, swap if smaller, repeat.
- `sift_down`: compare with smaller child, swap if larger, repeat.
- The heap array order is **not** sorted — only the minimum is guaranteed at index 0.
