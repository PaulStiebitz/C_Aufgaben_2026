# Exercise 32 – Doubly Linked List: Deque (Double-Ended Queue)

## Topic
Doubly Linked Lists – Applied Data Structure

## Objective
Use a doubly linked list to implement a **deque** (double-ended queue) that supports O(1) push/pop from both ends.

## Instructions

1. Create `deque.c`.

2. Reuse `DNode` and define:
   ```c
   typedef struct { DNode *front; DNode *back; int size; } Deque;
   ```

3. Implement:
   - `void deque_init(Deque *d);`
   - `void push_front(Deque *d, int value);`
   - `void push_back(Deque *d, int value);`
   - `int  pop_front(Deque *d);` – error + return -1 if empty.
   - `int  pop_back(Deque *d);` – error + return -1 if empty.
   - `int  peek_front(const Deque *d);`
   - `int  peek_back(const Deque *d);`
   - `void deque_print(const Deque *d);` – front → back.
   - `void deque_free(Deque *d);`

4. In `main`, demonstrate pushing from both ends, peeking, popping from both ends, and show the final state.

## Expected Output
```
push_back(1), push_back(2), push_front(0), push_front(-1)
Deque: -1 0 1 2
peek_front=-1, peek_back=2
pop_front: -1  => Deque: 0 1 2
pop_back:   2  => Deque: 0 1
```

## Hints
- A deque combines the behaviours of a stack and a queue.
- All four push/pop operations only touch `front` or `back` — no traversal required.
