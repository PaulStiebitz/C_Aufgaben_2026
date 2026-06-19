# Exercise 88 – Generic Stack with void Pointers

## Topic
Pointers + `void*` + Dynamic Memory + Generic Programming

## Objective
Build a type-agnostic stack using `void*` so that it can store any data type — the C approach to generics.

---

## Instructions

1. Create `generic_stack.c`.

2. Define:
   ```c
   typedef struct StackNode {
       void            *data;      /* pointer to heap-allocated element */
       struct StackNode *next;
   } StackNode;

   typedef struct {
       StackNode *top;
       int        size;
       size_t     elem_size;       /* size of each element */
       void (*print_elem)(const void *);  /* user-provided print function */
   } GenStack;
   ```

3. Implement:
   ```c
   void  gstack_init(GenStack *s, size_t elem_size, void (*print_fn)(const void*));
   void  gstack_push(GenStack *s, const void *value);
   /* malloc a copy of value (memcpy elem_size bytes), push onto stack */

   int   gstack_pop(GenStack *s, void *out);
   /* copies top element into *out (caller provides buffer), frees the node */

   int   gstack_peek(const GenStack *s, void *out);
   void  gstack_print(const GenStack *s);
   int   gstack_is_empty(const GenStack *s);
   void  gstack_free(GenStack *s);
   ```

4. In `main`, demonstrate with **three different types**:
   - `int` stack: push 10, 20, 30; pop all.
   - `double` stack: push 1.1, 2.2, 3.3; peek and pop.
   - `char[16]` string stack: push `"hello"`, `"world"`, `"C"`; print and pop.

5. Write print functions:
   ```c
   void print_int(const void *v)    { printf("%d", *(const int*)v); }
   void print_double(const void *v) { printf("%.2f", *(const double*)v); }
   void print_str(const void *v)    { printf("%s", (const char*)v); }
   ```

---

## Expected Output
```
=== int stack ===
Push: 10 20 30
Stack (top->bot): 30 20 10
Pop: 30, 20, 10. Empty: yes

=== double stack ===
Push: 1.10 2.20 3.30
Peek: 3.30
Pop: 3.30, 2.20, 1.10.

=== string stack ===
Push: "hello" "world" "C"
Stack (top->bot): C world hello
Pop: C, world, hello.
```

---

## Hints
- `gstack_push`: `malloc(elem_size)`, then `memcpy(new_node->data, value, elem_size)`.
- `gstack_pop`: `memcpy(out, top->data, elem_size)`, then `free(top->data)`, `free(top)`.
- Casting back: `*(const int*)v` works because we stored a copy of the correct type.
- The `print_elem` function pointer lets the stack remain completely type-agnostic.
