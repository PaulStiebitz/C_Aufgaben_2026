# Exercise 100 – Grand Capstone: CLI Database Engine

## Topic
ALL Topics Combined — Grand Finale

## Objective
Build a complete, multi-file mini database engine from scratch.  
This is the ultimate exam preparation exercise — it covers every topic in the course.

---

## Feature Requirements

### Data Model
```c
// table.h
typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_TEXT } FieldType;

typedef struct {
    char      name[32];
    FieldType type;
} Schema;

typedef union { int i; float f; char s[64]; } Field;

typedef struct Row {
    Field        *fields;   /* heap-alloc, count = schema col_count */
    struct Row   *next;
} Row;

typedef struct {
    char    name[32];
    Schema *columns;
    int     col_count;
    Row    *rows;
    int     row_count;
} DBTable;

typedef struct {
    DBTable tables[8];
    int     table_count;
} Database;
```

---

### Required Operations

#### DDL (Data Definition)
```
CREATE TABLE <name> (<col> <type>, ...)
DROP TABLE <name>
DESCRIBE <name>
```

#### DML (Data Manipulation)
```
INSERT INTO <table> VALUES (<v1>, <v2>, ...)
SELECT * FROM <table>
SELECT * FROM <table> WHERE <col> = <value>
SELECT * FROM <table> ORDER BY <col> [ASC|DESC]
DELETE FROM <table> WHERE <col> = <value>
UPDATE <table> SET <col> = <value> WHERE <id_col> = <id>
```

#### Persistence
```
SAVE <filename>     -- save entire database to binary file
LOAD <filename>     -- restore from binary file
EXPORT <table> CSV <filename>
```

#### Meta
```
TABLES              -- list all tables
QUIT / EXIT
HELP
```

---

### Architecture (multi-file)

| File | Contents |
|------|----------|
| `main.c` | REPL loop, top-level dispatch |
| `db.h/c` | `Database` CRUD, table lookup |
| `table.h/c` | `DBTable` operations (insert, select, delete, update) |
| `schema.h/c` | Schema definition and type parsing |
| `parser.h/c` | Command string → parsed command struct |
| `output.h/c` | Formatted table output |
| `persist.h/c` | Binary save/load, CSV export |

---

### Example Session
```
db> CREATE TABLE employees (id INT, name TEXT, salary FLOAT)
Table "employees" created.

db> INSERT INTO employees VALUES (1, Alice, 55000.0)
db> INSERT INTO employees VALUES (2, Bob, 48000.0)
db> INSERT INTO employees VALUES (3, Charlie, 72000.0)

db> SELECT * FROM employees
+----+---------+-----------+
| id | name    | salary    |
+----+---------+-----------+
|  1 | Alice   | 55000.00  |
|  2 | Bob     | 48000.00  |
|  3 | Charlie | 72000.00  |
+----+---------+-----------+
3 rows.

db> SELECT * FROM employees WHERE id = 2
|  2 | Bob     | 48000.00  |

db> SELECT * FROM employees ORDER BY salary DESC
|  3 | Charlie | 72000.00  |
|  1 | Alice   | 55000.00  |
|  2 | Bob     | 48000.00  |

db> UPDATE employees SET salary = 60000.0 WHERE id = 2
Updated 1 row.

db> DELETE FROM employees WHERE id = 1
Deleted 1 row.

db> SAVE mydb.bin
Saved 1 table, 2 rows to mydb.bin.

db> EXPORT employees CSV employees.csv
Exported 2 rows to employees.csv.

db> QUIT
Goodbye.
```

---

## Topics Used

| Topic | Where |
|-------|-------|
| Custom libraries `.h`/`.c` | All 7 files |
| Structs, nested structs | `Row`, `Schema`, `DBTable`, `Database` |
| Unions | `Field` (int/float/text) |
| Enums | `FieldType`, command types |
| Dynamic memory | `Row`, `fields`, `Schema` arrays |
| Linked lists | `Row *next` chain |
| Sorting (qsort) | `ORDER BY` implementation |
| Pointers, double pointers | Row traversal, schema access |
| Strings, `<string.h>` | Name matching, text fields |
| File I/O (text + binary) | `SAVE`, `LOAD`, `EXPORT` |
| `argc`/`argv` | `./db [--file mydb.bin]` startup flag |
| Variadic functions | Formatted output printer |
| Preprocessor macros | Error checking, debug logging |
| Function pointers | Command dispatch table |

---

## Checklist
- [ ] All DDL commands work
- [ ] All DML commands work
- [ ] Binary save/load round-trip verified
- [ ] CSV export produces valid CSV
- [ ] Formatted table output auto-aligns columns
- [ ] WHERE clause works for INT, FLOAT, TEXT
- [ ] ORDER BY works ascending and descending
- [ ] No memory leaks (`malloc` paired with `free`)
- [ ] Compiles cleanly with `gcc -Wall -Wextra -std=c11`
- [ ] At least 7 source files (multi-file project)
