# Exercise 78 – Variadic Functions: `sprintf`-style String Builder

## Topic
Variadic Functions + Strings + Dynamic Memory

## Objective
Implement a dynamic string builder that supports `printf`-style format strings and automatically grows its buffer.

---

## Instructions

1. Create `strbuf.h` and `strbuf.c`.

2. Define:
   ```c
   typedef struct {
       char  *data;      /* heap-allocated buffer */
       size_t length;    /* current string length */
       size_t capacity;  /* allocated buffer size */
   } StrBuf;
   ```

3. Implement:
   ```c
   void strbuf_init(StrBuf *sb, size_t initial_capacity);
   void strbuf_free(StrBuf *sb);
   void strbuf_append(StrBuf *sb, const char *str);
   void strbuf_appendf(StrBuf *sb, const char *fmt, ...);  /* printf-style */
   void strbuf_append_char(StrBuf *sb, char c);
   void strbuf_clear(StrBuf *sb);
   const char* strbuf_get(const StrBuf *sb);
   ```

4. Inside `strbuf_appendf`:
   - Use `vsnprintf(NULL, 0, fmt, args)` to compute the required length first.
   - Grow the buffer with `realloc` if necessary (double capacity until it fits).
   - Then write with `vsnprintf(sb->data + sb->length, space, fmt, args_copy)`.
   - Use `va_copy` for the second pass.

5. In `main.c`:
   - Build an HTML fragment using `strbuf_appendf`.
   - Build a CSV row from a struct.
   - Demonstrate appending 1000 times to show dynamic growth.
   - Print final length and capacity.

---

## Expected Output (example)
```
HTML output:
<table>
  <tr><td>Alice</td><td>22</td><td>95.50</td></tr>
  <tr><td>Bob</td><td>25</td><td>88.00</td></tr>
</table>

CSV row: "Alice",22,95.50

After 1000 appends of "abc":
  length   = 3000
  capacity = 4096  (or similar power-of-two)
```

---

## Hints
- `vsnprintf(NULL, 0, fmt, args)` returns the number of characters that **would** have been written — the required buffer size.
- Always use `va_copy` before the second `vsnprintf` call because the first call advances the `va_list` state.
- Double the capacity: `while (new_cap < needed) new_cap *= 2;`
- `strbuf_get` simply returns `sb->data`.
