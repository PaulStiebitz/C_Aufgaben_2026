# Exercise 26 – Singly Linked List: Search, Insert & Delete

## Topic
Linked Lists (Singly) – Intermediate

## Objective
Extend the singly linked list with searching, positional insertion, and node deletion.

## Instructions

1. Create `linked_list_ops.c` (you may reuse the `Node` definition from exercise 25).

2. Implement:
   - `Node* list_find(Node *head, int value);` – returns pointer to the first node with `data == value`, or `NULL`.
   - `Node* list_insert_after(Node *head, int after_value, int new_value);`
     Inserts a new node **after** the first node containing `after_value`. If not found, print a warning and return `head` unchanged.
   - `Node* list_delete(Node *head, int value);`
     Removes the **first** node containing `value`. Returns updated head. If not found, print a warning.
   - `Node* list_delete_all(Node *head, int value);`
     Removes **all** nodes with `data == value`.
   - `void list_print(const Node *head);`
   - `void list_free(Node *head);`

3. In `main`:
   - Build list: 1 → 3 → 3 → 7 → 3 → 9.
   - Insert 5 after value 3 (first occurrence).
   - Delete first occurrence of 3.
   - Delete all remaining 3s.
   - Print at each step.

## Expected Output
```
Initial:       1 -> 3 -> 3 -> 7 -> 3 -> 9 -> NULL
Insert 5 after 3: 1 -> 3 -> 5 -> 3 -> 7 -> 3 -> 9 -> NULL
Delete first 3:   1 -> 5 -> 3 -> 7 -> 3 -> 9 -> NULL
Delete all 3:     1 -> 5 -> 7 -> 9 -> NULL
```

## Hints
- Keep a `prev` pointer when traversing to wire up the `next` links after deletion.
- The head node is a special case in deletion (no predecessor).
