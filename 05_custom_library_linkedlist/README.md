# Exercise 05 – Create a Linked-List Utility Library

## Topic
Custom Libraries (`.h` / `.c`) + Structs + Pointers

## Objective
Design a reusable library for a singly linked list of integers by splitting the definition and implementation across `.h` and `.c` files.

## Instructions

1. In `list.h`, declare:
   - A struct `Node` with an `int data` field and a `struct Node *next` pointer.
   - A struct `List` with a `Node *head` field and an `int size` counter.
   - Function prototypes:
     - `void list_init(List *l);`
     - `void list_push_front(List *l, int value);`
     - `void list_push_back(List *l, int value);`
     - `void list_print(const List *l);`
     - `void list_free(List *l);`

2. Implement all functions in `list.c`.

3. Write `main.c` to test pushing values from both ends and printing.

4. Compile in separate steps and link.

## Expected Output (example)
```
Push back: 1 2 3
Push front: 0 -> 1 -> 2 -> 3 -> NULL
List size: 4
```

## Hints
- Use `typedef struct Node Node;` so you can refer to the type without the `struct` keyword.
- Always free all nodes with `list_free` at the end to avoid memory leaks.
- Use `malloc` / `free` from `<stdlib.h>`.
