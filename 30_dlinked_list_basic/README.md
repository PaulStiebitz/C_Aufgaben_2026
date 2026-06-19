# Exercise 30 – Doubly Linked List: Basic Operations

## Topic
Doubly Linked Lists

## Objective
Implement a doubly linked list where each node has both `next` and `prev` pointers, enabling bidirectional traversal.

## Instructions

1. Create `dlinked_list.c`.

2. Define:
   ```c
   typedef struct DNode {
       int          data;
       struct DNode *next;
       struct DNode *prev;
   } DNode;
   typedef struct { DNode *head; DNode *tail; int size; } DList;
   ```

3. Implement:
   - `void  dlist_init(DList *l);`
   - `void  dlist_push_front(DList *l, int value);`
   - `void  dlist_push_back(DList *l, int value);`
   - `void  dlist_print_forward(const DList *l);` – head → tail.
   - `void  dlist_print_backward(const DList *l);` – tail → head.
   - `void  dlist_free(DList *l);`

4. In `main`:
   - Push back: 1, 2, 3.
   - Push front: 0.
   - Print forward and backward.
   - Print size.

## Expected Output
```
Forward:  0 <-> 1 <-> 2 <-> 3 <-> NULL
Backward: 3 <-> 2 <-> 1 <-> 0 <-> NULL
Size: 4
```

## Hints
- `push_front`: new node's `next = head`, `head->prev = new_node`, update head.
- `push_back`: use the `tail` pointer for O(1) insertion.
- Always update **both** `next` and `prev` when inserting or removing nodes.
- When the list is empty, both `head` and `tail` must point to the new node.
