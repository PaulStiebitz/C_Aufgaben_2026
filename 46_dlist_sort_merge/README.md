# Exercise 46 – Doubly Linked List: Sort & Merge

## Topic
Doubly Linked Lists – Algorithms

## Objective
Implement insertion sort on a doubly linked list and merge two sorted doubly linked lists.

## Instructions

1. Create `dlist_sort_merge.c`. Use the `DNode` / `DList` structure from exercise 30.

2. Implement:
   - `void dlist_insertion_sort(DList *l);`
     Sorts the list **in-place** using the insertion-sort strategy:
     - For each node, find the correct position in the already-sorted prefix and re-link.
   - `DList dlist_merge_sorted(DList *a, DList *b);`
     Merges two already-sorted lists into one sorted list.
     Build the result by always picking the smaller head from `a` or `b`.
     **Do not allocate new nodes** — move existing nodes.
   - Helper utilities: `dlist_push_back`, `dlist_print_forward`, `dlist_free`.

3. In `main`:
   - Build an unsorted list: `{5, 2, 8, 1, 9, 3}`.
   - Sort it, print.
   - Build two sorted lists: `{1, 4, 7}` and `{2, 3, 8}`.
   - Merge, print.

## Expected Output
```
Unsorted: 5 <-> 2 <-> 8 <-> 1 <-> 9 <-> 3
Sorted:   1 <-> 2 <-> 3 <-> 5 <-> 8 <-> 9

List A: 1 <-> 4 <-> 7
List B: 2 <-> 3 <-> 8
Merged: 1 <-> 2 <-> 3 <-> 4 <-> 7 <-> 8
```

## Hints
- For `dlist_insertion_sort`, "removing" a node and "inserting" it at the right position requires updating 4 pointers (both neighbours of the source and both neighbours of the insertion point).
- For `dlist_merge_sorted`, maintain a pointer to the tail of the result list for O(1) appends.
