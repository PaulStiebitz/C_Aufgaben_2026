# Exercise 84 – Struct Array with Runtime Schema

## Topic
Structs + Arrays + Function Pointers + File I/O

## Objective
Build a table-like data store where the **schema** (column names and types) is defined at runtime and rows are stored as arrays of unions.

---

## Instructions

1. Create `runtime_table.c`.

2. Define:
   ```c
   typedef enum { COL_INT, COL_FLOAT, COL_STRING } ColType;

   typedef union {
       int   i;
       float f;
       char  s[32];
   } Cell;

   typedef struct {
       char    name[20];
       ColType type;
   } Column;

   #define MAX_COLS 8
   #define MAX_ROWS 50

   typedef struct {
       Column columns[MAX_COLS];
       int    col_count;
       Cell   rows[MAX_ROWS][MAX_COLS];
       int    row_count;
   } Table;
   ```

3. Implement:
   ```c
   void table_define(Table *t, int col_count, ...);
   /* variadic: pairs of (char *name, ColType type) */

   void table_insert_row(Table *t, ...);
   /* variadic: one value per column in schema order */
   /* for COL_INT: pass int, COL_FLOAT: pass double (promoted), COL_STRING: pass char* */

   void table_print(const Table *t);
   /* print header + all rows, auto-align columns */

   void table_sort_by_col(Table *t, int col_index, int ascending);
   /* sort rows by a given column */

   void table_save_csv(const Table *t, const char *filename);
   void table_filter_print(const Table *t, int col_index, const char *op, Cell threshold);
   /* op: "=", "<", ">", ">=", "<=" for int/float; "=" for string */
   ```

4. In `main`:
   - Define a 3-column table: `(name:STRING, age:INT, score:FLOAT)`.
   - Insert 5 rows.
   - Print the table.
   - Sort by score descending.
   - Filter: `age > 21`.
   - Save to CSV.

---

## Expected Output
```
+----------+-----+-------+
| name     | age | score |
+----------+-----+-------+
| Alice    |  22 | 95.50 |
| Bob      |  25 | 88.00 |
| Charlie  |  21 | 72.30 |
| Diana    |  23 | 91.00 |
| Eve      |  20 | 85.50 |
+----------+-----+-------+

Sorted by score DESC:
Alice 95.50 / Diana 91.00 / Bob 88.00 / Eve 85.50 / Charlie 72.30

Filter age > 21:
Alice(22), Bob(25), Diana(23)
```

---

## Hints
- `table_define` uses variadic pairs: `va_arg(args, char*)` for name, `va_arg(args, int)` for `ColType` (enum is promoted to int).
- `table_insert_row` checks each column's type and uses `va_arg` accordingly.
- `table_sort_by_col` can use a comparison function that reads the right union field based on `columns[col_index].type`.
