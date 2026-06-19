# Exercise 63 – File Handling: CSV Parser & Writer

## Topic
File I/O – Structured Text Files (CSV)

## Objective
Read and write CSV (Comma-Separated Values) files, handle quoted fields, and convert parsed tokens into typed struct fields.

---

## Instructions

1. Create `csv_parser.c`.

2. Define:
   ```c
   typedef struct {
       int   id;
       char  first_name[30];
       char  last_name[30];
       int   age;
       char  email[60];
       float score;
   } Person;
   ```

3. **Part A – Write CSV**:
   - Create an array of 5 `Person` structs.
   - Open `persons.csv` for writing.
   - Write a **header row**: `id,first_name,last_name,age,email,score`.
   - Write each person as a comma-separated line.
   - Close.

4. **Part B – Read CSV**:
   Implement:
   ```c
   int csv_read_persons(const char *filename, Person *arr, int max_count);
   ```
   - Skip the header line (`fgets` once before the loop).
   - Use `fgets` + manual parsing with `strtok(line, ",")` for each row.
   - Convert tokens with `atoi`/`atof`.
   - Return the number of persons read.

5. **Part C – Filter & re-export**:
   - Read back all persons.
   - Filter: keep only those with `score >= 75.0`.
   - Write the filtered subset to `high_scorers.csv` (with header).
   - Print how many were kept.

6. **Part D – Append a new row**:
   - Open `persons.csv` in append mode (`"a"`).
   - Add a 6th person.
   - Re-read and print the updated count.

---

## `persons.csv` Example
```csv
id,first_name,last_name,age,email,score
1,Alice,Smith,22,alice@mail.com,92.5
2,Bob,Jones,25,bob@mail.com,68.0
3,Charlie,Brown,21,charlie@mail.com,85.0
4,Diana,Prince,23,diana@mail.com,74.5
5,Eve,White,20,eve@mail.com,95.0
```

---

## Expected Output
```
Written 5 persons to persons.csv.
Read back: 5 persons.

High scorers (score >= 75.0): 3
  Alice Smith   92.50
  Charlie Brown 85.00
  Eve White     95.00

After append: 6 persons in persons.csv.
```

---

## Hints
- `strtok` modifies the string — work on a copy if you need the original.
- Strip trailing `\n` from `fgets` output: `line[strcspn(line, "\n")] = '\0';`
- CSV fields that contain commas should be quoted — for this exercise, assume clean data without embedded commas.
- Always print both the header and at least one data row to verify the format.
