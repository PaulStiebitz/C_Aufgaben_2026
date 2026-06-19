# Exercise 39 – File I/O with Structs

## Topic
File I/O + Structs

## Objective
Write struct data to a text file and read it back; practice `fprintf`, `fscanf`, `fopen`, `fclose`.

## Instructions

1. Create `file_io.c`.

2. Define:
   ```c
   typedef struct { char name[40]; int age; float salary; } Employee;
   ```

3. **Write**:
   - Create an array of 4 `Employee` values.
   - Open `"employees.txt"` for writing (`"w"`).
   - Write the number of employees on the first line.
   - Write each employee as: `"name age salary\n"`.
   - Close the file.

4. **Read back**:
   - Open `"employees.txt"` for reading (`"r"`).
   - Read the count, then read that many employees using `fscanf`.
   - Print all employees.

5. **Append**:
   - Open in append mode (`"a"`), add one more employee, close.
   - Re-read the file and print all entries to verify.

6. Always check return values of `fopen` (NULL = error).

## Expected Output
```
Written 4 employees to employees.txt.

Read from file:
1. Alice    age=30 salary=55000.00
2. Bob      age=25 salary=48000.00
3. Charlie  age=35 salary=72000.00
4. Diana    age=28 salary=61000.00

After append (5 employees):
...
5. Eve      age=22 salary=42000.00
```

## Hints
- `fscanf(fp, "%s %d %f", name, &age, &salary)` returns the number of items successfully read.
- Names with spaces would break `fscanf %s` — keep names as single words for this exercise.
- Always `fclose(fp)` — even on error paths.
