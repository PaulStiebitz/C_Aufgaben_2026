# Exercise 82 – Circular Buffer (Ring Buffer)

## Topic
Arrays + Pointers + Structs

## Objective
Implement a fixed-capacity circular buffer (ring buffer) — a FIFO data structure that wraps around without shifting elements.

---

## Instructions

1. Create `ringbuffer.c`.

2. Define:
   ```c
   #define RING_CAP 8

   typedef struct {
       int  data[RING_CAP];
       int  head;    /* index of the next element to read */
       int  tail;    /* index of the next position to write */
       int  count;   /* number of elements currently stored */
   } RingBuffer;
   ```

3. Implement:
   ```c
   void ring_init(RingBuffer *rb);
   int  ring_push(RingBuffer *rb, int value);  /* returns 0 ok, -1 if full */
   int  ring_pop(RingBuffer *rb, int *out);    /* returns 0 ok, -1 if empty */
   int  ring_peek(const RingBuffer *rb, int *out); /* peek front, no remove */
   int  ring_is_full(const RingBuffer *rb);
   int  ring_is_empty(const RingBuffer *rb);
   void ring_print(const RingBuffer *rb);      /* print all elements in order */
   ```

4. In `main`:
   - Push 1–6 (6 elements).
   - Pop 3 elements.
   - Push 7–10 (fills up, 8/8).
   - Try to push one more (full).
   - Print.
   - Pop all, verify order is FIFO.

---

## Expected Output
```
Push 1-6: [1 2 3 4 5 6]  count=6
Pop x3:   1, 2, 3        count=3
Push 7-10:[4 5 6 7 8 9 10] count=7 -> 8
Push 11:  FULL (count=8)
Ring: [4 5 6 7 8 9 10 ?]  head=3, tail=3

Pop all: 4 5 6 7 8 9 10 (last was 8/8 slot)
Ring empty: 1
```

---

## Hints
- Advance head/tail with: `head = (head + 1) % RING_CAP`.
- Full condition: `count == RING_CAP` (using `count` is cleaner than the `head == tail` ambiguity).
- `ring_print` starts from `head`, prints `count` elements using modulo index arithmetic.
- Ring buffers are used in audio streaming, UART drivers, and producer/consumer scenarios.
