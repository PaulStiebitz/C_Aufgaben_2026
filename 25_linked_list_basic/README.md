# Exercise 25 – Singly Linked List: Build & Traverse

## Topic
Linked Lists (Singly)

## Objective
Implement a singly linked list from scratch: creating nodes, inserting at front/back, and traversing.

## Instructions

1. Create `linked_list.c`.

2. Define:
   ```c
   typedef struct Node {
       int          data;
       struct Node *next;
   } Node;
   ```

3. Implement:
   - `Node* node_create(int value);` – allocates and returns a new node.
   - `Node* list_push_front(Node *head, int value);` – prepends a node, returns new head.
   - `Node* list_push_back(Node *head, int value);` – appends a node, returns (possibly unchanged) head.
   - `void  list_print(const Node *head);` – prints `val1 -> val2 -> ... -> NULL`.
   - `int   list_length(const Node *head);` – counts nodes.
   - `void  list_free(Node *head);` – frees all nodes.

4. In `main`:
   - Push back: 1, 2, 3, 4, 5.
   - Push front: 0.
   - Print list and length.
   - Free.

## Expected Output
```
List: 0 -> 1 -> 2 -> 3 -> 4 -> 5 -> NULL
Length: 6
```

## Hints
- For `push_back`, traverse until `current->next == NULL`, then attach the new node.
- `push_front` returns a new head — callers must use the returned pointer: `head = list_push_front(head, 0);`
- `list_free` must save `next` before calling `free(current)`.
