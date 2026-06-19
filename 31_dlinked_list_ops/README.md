# Exercise 31 – Doubly Linked List: Insert & Delete

## Topic
Doubly Linked Lists – Intermediate

## Objective
Extend the doubly linked list with insert-at-position, delete-by-value, and sorted insertion.

## Instructions

1. Create `dlinked_list_ops.c` (reuse the `DNode` / `DList` structure from exercise 30).

2. Implement:
   - `void dlist_insert_at(DList *l, int index, int value);`
     Insert a new node at the given zero-based index.  
     Index 0 = insert before head.  
     Index ≥ size = append at tail.
   - `void dlist_delete_value(DList *l, int value);`
     Remove the first node with `data == value`. Print a warning if not found.
   - `void dlist_insert_sorted(DList *l, int value);`
     Inserts `value` so that the list remains sorted in ascending order.
   - `void dlist_print_forward(const DList *l);`
   - `void dlist_free(DList *l);`

3. In `main`:
   - Build list: 10 → 30 → 50.
   - Insert 20 at index 1. Print.
   - Delete value 30. Print.
   - Use `dlist_insert_sorted` to build a sorted list from `{5, 1, 8, 3, 7}`. Print.

## Expected Output
```
After insert at 1:  10 <-> 20 <-> 30 <-> 50
After delete 30:    10 <-> 20 <-> 50
Sorted inserts:  1 <-> 3 <-> 5 <-> 7 <-> 8
```

## Hints
- For `dlist_delete_value`, update `prev->next` and `next->prev` to bypass the deleted node.
- Handle the edge cases: deleting the head, deleting the tail.
- `dlist_insert_sorted` traverses forward until it finds a node with `data > value`.
