# Exercise 77 – Variadic Functions: Formatted Table Printer

## Topic
Variadic Functions + Strings + Formatting

## Objective
Build a reusable table-printing library that accepts column headers and rows as variadic arguments and produces neatly aligned output.

---

## Instructions

1. Create `table.h` and `table.c`.

2. Define:
   ```c
   #define MAX_COLS 8
   #define MAX_ROWS 50

   typedef struct {
       int   col_count;
       int   col_widths[MAX_COLS];
       char  headers[MAX_COLS][40];
       char  rows[MAX_ROWS][MAX_COLS][40];
       int   row_count;
   } Table;
   ```

3. Implement:
   ```c
   /* Initialise table with n column headers (variadic char* args) */
   void table_init(Table *t, int col_count, ...);

   /* Add a row: variadic char* args, one per column */
   void table_add_row(Table *t, ...);

   /* Print the table with box-drawing ASCII borders */
   void table_print(const Table *t);
   ```

4. Inside `table_init`:
   - Use `va_arg(args, char*)` for each header.
   - Track the maximum column width seen (update on each `table_add_row` too).

5. `table_print` output format:
   ```
   +----------+-------+--------+
   | Name     | Age   | Score  |
   +----------+-------+--------+
   | Alice    | 22    | 95.50  |
   | Bob      | 25    | 88.00  |
   +----------+-------+--------+
   ```
   - Use `%-*s` printf format with computed column widths for alignment.

6. In `main.c`:
   ```c
   Table t;
   table_init(&t, 4, "Name", "City", "Age", "Score");
   table_add_row(&t, "Alice", "Berlin", "22", "95.5");
   table_add_row(&t, "Bob",   "Munich", "25", "88.0");
   table_add_row(&t, "Charlie", "Hamburg", "21", "72.3");
   table_print(&t);
   ```

---

## Expected Output
```
+----------+---------+-----+-------+
| Name     | City    | Age | Score |
+----------+---------+-----+-------+
| Alice    | Berlin  |  22 | 95.5  |
| Bob      | Munich  |  25 | 88.0  |
| Charlie  | Hamburg |  21 | 72.3  |
+----------+---------+-----+-------+
```

---

## Hints
- Store all data as strings in the `rows` buffer — convert numbers to strings before calling `table_add_row`.
- Track `col_widths[j] = max(col_widths[j], strlen(cell))` on every insert.
- `printf("%-*s", width, str)` left-aligns `str` in a field of `width` characters.
- The separator line is: `"+" + ("-" * (width+2)) + "+"` for each column.
