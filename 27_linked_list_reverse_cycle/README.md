# Exercise 27 – Linked List: Reverse & Detect Cycle

## Topic
Linked Lists (Singly) – Algorithms

## Objective
Implement in-place list reversal and Floyd's cycle detection algorithm.

## Instructions

1. Create `linked_list_algo.c`.

2. Implement:
   - `Node* list_reverse(Node *head);`
     Reverses the list **in-place** (no extra list). Returns the new head.
     Approach: maintain `prev`, `current`, `next` pointers while iterating.

   - `int list_has_cycle(Node *head);`
     Returns 1 if the list contains a cycle, 0 otherwise.
     Use **Floyd's two-pointer (tortoise and hare)** algorithm:
     - `slow` moves 1 step, `fast` moves 2 steps.
     - If `slow == fast`, there is a cycle.

3. In `main`:
   - Build list: 1 → 2 → 3 → 4 → 5.
   - Print, check for cycle (none), reverse, print again.
   - Manually create a cyclic list (set `tail->next` to some earlier node) and test `list_has_cycle`.

4. Add `void list_print(const Node *head)` and `void list_free_no_cycle(Node *head)`.

## Expected Output
```
Original:  1 -> 2 -> 3 -> 4 -> 5 -> NULL
Has cycle: 0
Reversed:  5 -> 4 -> 3 -> 2 -> 1 -> NULL

Cyclic list (do not print!):
Has cycle: 1
```

## Hints
- Do **not** try to print a cyclic list — it causes an infinite loop.
- `list_reverse` uses exactly 3 pointer variables; no extra memory is needed.
