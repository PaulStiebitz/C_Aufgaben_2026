# Exercise 53 – Variadic Functions (`stdarg.h`)

## Topic
Variadic Functions – `va_list`, `va_start`, `va_arg`, `va_end`, `va_copy`

## Objective
Write functions that accept a variable number of arguments, just like `printf` and `scanf`.

---

## Background

C allows functions with a variable argument list using the `...` syntax and the macros in `<stdarg.h>`:

```c
#include <stdarg.h>

void my_func(int count, ...) {
    va_list args;
    va_start(args, count);          // initialise, last named param = count

    for (int i = 0; i < count; i++) {
        int val = va_arg(args, int); // fetch next argument as int
        // use val
    }

    va_end(args);                   // clean up
}
```

**Rules:**
- There must be **at least one named parameter** before `...`.
- The caller and callee must agree on the **number and types** of extra arguments — C does not check this.
- Always call `va_end` before returning.

---

## Part A – Sum and Average of Integers

1. Create `variadic.c`.

2. Implement:
   ```c
   int   sum_ints(int count, ...);      /* sum of 'count' int arguments */
   double avg_ints(int count, ...);     /* average of 'count' int arguments */
   int   max_of(int count, ...);        /* maximum of 'count' int arguments */
   ```

3. In `main`, test with:
   - `sum_ints(4, 10, 20, 30, 40)` → 100
   - `avg_ints(5, 1, 2, 3, 4, 5)` → 3.0
   - `max_of(6, 3, 9, 2, 7, 1, 8)` → 9

### Expected Output
```
sum_ints(4: 10,20,30,40)   = 100
avg_ints(5: 1,2,3,4,5)     = 3.00
max_of(6: 3,9,2,7,1,8)     = 9
```

---

## Part B – String Concatenation

4. Implement:
   ```c
   /* Concatenates 'count' strings into dest (which has size dest_size).
      Returns dest. */
   char* concat_strings(char *dest, size_t dest_size, int count, ...);
   ```
   - Use `va_arg(args, char*)` to fetch each string.
   - Append each string to `dest` using manual pointer logic or `strncat`.
   - Stop early if `dest` would overflow.

5. Test:
   ```c
   concat_strings(buf, sizeof(buf), 4, "Hello", ", ", "World", "!");
   ```

### Expected Output
```
concat(4): "Hello, World!"
```

---

## Part C – Mini `printf` Clone

6. Implement a simplified `my_printf` that handles the format specifiers `%d`, `%f`, `%s`, `%c`, and `%%`:
   ```c
   void my_printf(const char *fmt, ...);
   ```
   - Walk through `fmt` character by character.
   - On `%`, check the next character and call `va_arg` with the appropriate type.
   - For `%d`: fetch `int`, convert to string manually (or use `sprintf` internally).
   - For `%s`: fetch `char*`, print character by character.
   - For `%f`: fetch `double` (note: `float` is promoted to `double` in variadic calls), print with 2 decimal places.
   - For `%c`: fetch `int` (chars are promoted to int), print the character.
   - For `%%`: print a literal `%`.
   - All other characters: print as-is.

7. Test:
   ```c
   my_printf("Name: %s, Age: %d, Score: %f, Grade: %c\n",
             "Alice", 22, 95.5, 'A');
   my_printf("100%% done!\n");
   ```

### Expected Output
```
Name: Alice, Age: 22, Score: 95.50, Grade: A
100% done!
```

---

## Part D – Type-Safe Variadic with Sentinel

8. Implement a function that takes a variable number of `int` arguments **without** a count, terminated by a sentinel value `-1`:
   ```c
   int sum_until_sentinel(int first, ...);
   /* Sums all int arguments until it encounters -1 (the sentinel). */
   ```

9. Test:
   ```c
   sum_until_sentinel(5, 10, 15, 20, -1)   // = 50
   sum_until_sentinel(1, -1)                // = 1
   sum_until_sentinel(-1)                   // = 0 (first arg is sentinel)
   ```

### Expected Output
```
sum_until_sentinel(5,10,15,20,-1) = 50
sum_until_sentinel(1,-1)          = 1
sum_until_sentinel(-1)            = 0
```

---

## Part E – `va_copy`

10. Implement:
    ```c
    void print_and_sum(int count, ...);
    ```
    - Uses `va_copy` to make a copy of the argument list.
    - First pass (original `va_list`): print all values.
    - Second pass (`va_copy`): compute and print the sum.
    - Always `va_end` both the original and the copy.

### Expected Output
```
Values: 4 8 15 16 23 42
Sum:    108
```

---

## Full `<stdarg.h>` Reference

| Macro | Signature | Purpose |
|-------|-----------|---------|
| `va_list` | type | Holds state for traversing variadic args |
| `va_start(ap, last)` | macro | Initialise `ap`; `last` = last named param |
| `va_arg(ap, type)` | macro | Fetch next argument as `type` |
| `va_end(ap)` | macro | Clean up `ap` — **always required** |
| `va_copy(dst, src)` | macro | Copy state for a second pass |

---

## Hints
- `float` arguments are **automatically promoted to `double`** in variadic calls — always use `va_arg(args, double)` for floats.
- `char` and `short` are promoted to `int` — always use `va_arg(args, int)` for them.
- Never call `va_arg` more times than there are actual arguments — this is **undefined behaviour**.
- The sentinel pattern (Part D) avoids needing a count but requires caller discipline.
- `va_copy` is essential whenever you need to iterate the argument list more than once.
