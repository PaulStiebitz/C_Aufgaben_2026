# Exercise 95 – Full argv + File + Struct Pipeline

## Topic
`argc`/`argv` + File I/O + Structs + Sorting

## Objective
Build a complete CLI tool that reads structured data from an input file, processes it based on command-line flags, and writes output to a file — combining exercises 52–74.

---

## Instructions

1. Create `data_tool.c`.

2. **Interface**:
   ```
   ./data_tool [options] <input.csv>

   Options:
     --sort <field>      Sort by field: name|age|salary|department
     --sort-desc         Reverse sort order
     --filter-dept <dep> Only include employees from given department
     --filter-min-salary <n>  Only employees with salary >= n
     --output <file>     Write filtered/sorted data to file (default: stdout)
     --format <fmt>      Output format: csv|table|json  (default: table)
     --stats             Print summary statistics at the end
     --help              Print usage
   ```

3. Define:
   ```c
   typedef struct {
       int   id;
       char  name[50];
       char  department[30];
       int   age;
       float salary;
   } Employee;
   ```

4. Implement all operations:
   - `load_csv`: read employees from file.
   - `filter_dept`, `filter_min_salary`: return filtered subset.
   - Sorting via `qsort` with selectable comparator.
   - Output formatters: `print_table`, `print_csv`, `print_json`.
   - Stats: count, average salary, min/max salary, salary by dept.

5. All options are optional; defaults apply when omitted.

---

## Example Usage
```
$ ./data_tool employees.csv
(prints all employees as table)

$ ./data_tool --sort salary --sort-desc --filter-dept "Engineering" employees.csv
(prints Engineering employees, highest salary first)

$ ./data_tool --stats --output report.txt --format json employees.csv
(writes JSON to report.txt, prints stats to stdout)
```

---

## Expected Table Output (example)
```
+-----+---------+--------------+-----+-----------+
| ID  | Name    | Department   | Age | Salary    |
+-----+---------+--------------+-----+-----------+
|   3 | Charlie | Engineering  |  28 | €72000.00 |
|   1 | Alice   | Engineering  |  30 | €55000.00 |
+-----+---------+--------------+-----+-----------+
Stats: 2 employees, avg salary: €63500.00
```

---

## Hints
- Build the option parsing first (from exercise 69 pattern), then add each feature.
- Keep format-specific output in separate functions so `main` stays clean.
- Test each option independently before combining them.
