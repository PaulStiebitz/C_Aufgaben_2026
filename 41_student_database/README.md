# Exercise 41 – Mixed: Student Database (Structs + Sorting + File I/O)

## Topic
Structs + Sorting + File I/O

## Objective
Build a simple student database program that reads from a file, sorts by multiple criteria, and writes results back to a file.

## Instructions

1. Create `student_db.c`.

2. Define:
   ```c
   #define MAX_STUDENTS 100
   typedef struct {
       char  name[50];
       int   id;
       float grade;  /* 1.0 (best) to 5.0 (fail) */
   } Student;
   ```

3. Implement:
   - `int load_students(const char *filename, Student *arr, int max);`
     Reads students from `students.txt` (one per line: `"id name grade"`). Returns count.
   - `void save_students(const char *filename, const Student *arr, int n);`
     Writes all students to file in the same format.
   - `void sort_by_grade(Student *arr, int n);` (ascending, best first = lowest value)
   - `void sort_by_name(Student *arr, int n);`
   - `void print_students(const Student *arr, int n);`
   - `float class_average(const Student *arr, int n);`
   - `Student best_student(const Student *arr, int n);`

4. Create a sample `students.txt` file manually with at least 5 entries.

5. In `main`: load, print, sort by grade, print, print best student and class average.

## Expected Output (example)
```
Loaded 5 students.
--- By Grade ---
1. [1003] Charlie  1.30
2. [1001] Alice    1.70
3. [1005] Eve      2.30
4. [1002] Bob      2.70
5. [1004] Diana    3.30
Best student: Charlie (1.30)
Class average: 2.26
```

## `students.txt` format
```
1001 Alice 1.7
1002 Bob 2.7
1003 Charlie 1.3
1004 Diana 3.3
1005 Eve 2.3
```

## Hints
- Use `fscanf(fp, "%d %s %f", &s.id, s.name, &s.grade)`.
- Use `qsort` with appropriate comparators.
