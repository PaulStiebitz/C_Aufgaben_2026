# Exercise 29 – Queue Using a Linked List

## Topic
Linked Lists (Singly) – Applied Data Structure

## Objective
Implement a queue (First-In, First-Out) backed by a singly linked list with both `head` and `tail` pointers.

## Instructions

1. Create `queue.c`.

2. Define:
   ```c
   typedef struct Node { int data; struct Node *next; } Node;
   typedef struct { Node *head; Node *tail; int size; } Queue;
   ```

3. Implement:
   - `void queue_init(Queue *q);`
   - `void enqueue(Queue *q, int value);` – adds to the **tail**.
   - `int  dequeue(Queue *q);` – removes from the **head**; error + return -1 if empty.
   - `int  queue_front(const Queue *q);` – returns head value without removing.
   - `int  queue_is_empty(const Queue *q);`
   - `void queue_print(const Queue *q);` – front → back.
   - `void queue_free(Queue *q);`

4. In `main`:
   - Enqueue 1, 2, 3, 4, 5.
   - Print queue.
   - Dequeue twice, print.
   - Enqueue 6, print.
   - Dequeue all.

## Expected Output
```
Queue: 1 2 3 4 5  (front -> back)
Dequeue: 1
Dequeue: 2
Queue: 3 4 5
Enqueue 6
Queue: 3 4 5 6
Dequeue: 3
Dequeue: 4
Dequeue: 5
Dequeue: 6
Queue is empty.
```

## Hints
- Maintaining a `tail` pointer makes `enqueue` O(1) — no traversal needed.
- When the queue becomes empty after a dequeue, set both `head` and `tail` to `NULL`.
