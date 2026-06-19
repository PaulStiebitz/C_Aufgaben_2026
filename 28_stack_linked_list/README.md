# Exercise 28 – Stack Using a Linked List

## Topic
Linked Lists (Singly) – Applied Data Structure

## Objective
Implement a stack (Last-In, First-Out) using a singly linked list as the underlying storage.

## Instructions

1. Create `stack.c`.

2. Define:
   ```c
   typedef struct Node { int data; struct Node *next; } Node;
   typedef struct { Node *top; int size; } Stack;
   ```

3. Implement:
   - `void stack_init(Stack *s);`
   - `void stack_push(Stack *s, int value);` – adds element at the top.
   - `int  stack_pop(Stack *s);` – removes and returns the top element; print an error and return -1 if empty.
   - `int  stack_peek(const Stack *s);` – returns the top element without removing it; error + return -1 if empty.
   - `int  stack_is_empty(const Stack *s);`
   - `void stack_print(const Stack *s);` – prints top → bottom.
   - `void stack_free(Stack *s);`

4. In `main`:
   - Push 10, 20, 30, 40.
   - Peek.
   - Pop twice.
   - Print remaining stack.
   - Pop until empty; try one extra pop.

## Expected Output
```
Push: 10 20 30 40
Peek: 40
Pop: 40
Pop: 30
Stack: 20 -> 10 -> (bottom)
Pop: 20
Pop: 10
Stack is empty.
Error: pop from empty stack
```

## Hints
- The top of the stack is the `head` of the linked list — `push` = `push_front`, `pop` = remove front.
- Check `stack_is_empty` before popping/peeking.
