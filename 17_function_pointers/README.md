# Exercise 17 – Function Pointers

## Topic
Pointers (Function Pointers)

## Objective
Learn how to declare, assign, and call function pointers, and how to use them as parameters (callbacks).

## Instructions

1. Create `function_pointers.c`.

2. Implement four simple math functions:
   ```c
   int add(int a, int b);
   int subtract(int a, int b);
   int multiply(int a, int b);
   int divide_int(int a, int b);  // integer division; guard against b==0
   ```

3. **Part A – Basic function pointer**:
   - Declare a function pointer variable `int (*op)(int, int);`.
   - Assign each of the four functions to it in turn, call it with the same operands, and print the result.

4. **Part B – Array of function pointers**:
   - Declare `int (*ops[4])(int, int) = {add, subtract, multiply, divide_int};`
   - Loop over all four, call each, and print a table.

5. **Part C – Callback**:
   - Write `void apply_and_print(int a, int b, int (*func)(int, int), const char *name)`.
   - Call it for each operation.

## Expected Output (example, a=12, b=4)
```
add(12,4)      = 16
subtract(12,4) = 8
multiply(12,4) = 48
divide(12,4)   = 3
```

## Hints
- Syntax: `int (*ptr)(int, int) = add;` — the name of a function decays to a pointer.
- Calling: `ptr(a, b)` or `(*ptr)(a, b)` — both work.
