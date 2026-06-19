# Exercise 92 – File + Struct: Student Grade Book

## Topic
File I/O + Structs + Sorting + Statistics — Full Pipeline

## Objective
Build a complete grade-book application that loads student records from a file, performs computations, filters and sorts, and writes multiple output reports.

---

## Instructions

1. Create `gradebook.c`.

2. Define:
   ```c
   #define MAX_SUBJECTS 5

   typedef struct {
       int   id;
       char  name[50];
       float grades[MAX_SUBJECTS];  /* e.g. Math, Physics, CS, English, History */
       float average;               /* computed, not stored in file */
       char  letter_grade;          /* computed: A B C D F */
   } Student;
   ```

3. **Input file** (`grades.csv`):
   ```
   id,name,math,physics,cs,english,history
   1,Alice,92,88,95,79,85
   2,Bob,74,65,80,90,72
   3,Charlie,55,60,50,65,58
   4,Diana,98,95,97,92,90
   5,Eve,70,75,68,80,77
   ```

4. Implement:
   - `int load_grades(const char *file, Student *arr, int max);`
   - `void compute_stats(Student *arr, int n);` — fills `average` and `letter_grade` for each student.
     - A: ≥90, B: ≥80, C: ≥70, D: ≥60, F: <60
   - `void sort_by_average_desc(Student *arr, int n);`
   - `void sort_by_name(Student *arr, int n);`
   - `void print_report(const Student *arr, int n);` — formatted table.
   - `void write_report(const char *filename, const Student *arr, int n);`
   - `Student class_best(const Student *arr, int n);`
   - `Student class_worst(const Student *arr, int n);`
   - `float subject_average(const Student *arr, int n, int subject_idx);`
   - `void write_failing_students(const char *filename, const Student *arr, int n);`
     — writes only students with `letter_grade == 'F'`.

5. In `main`:
   - Load, compute, sort by average, print report to screen.
   - Write full report to `report.txt`.
   - Print best/worst student.
   - Print subject averages for all 5 subjects.
   - Write failing students to `failing.txt`.

---

## Expected Output
```
=== Grade Report (sorted by average) ===
 ID  Name        Math  Phys    CS  Eng  Hist   Avg  Grade
  4  Diana         98    95    97   92    90  94.4   A
  1  Alice         92    88    95   79    85  87.8   B
  5  Eve           70    75    68   80    77  74.0   C
  2  Bob           74    65    80   90    72  76.2   C
  3  Charlie       55    60    50   65    58  57.6   F

Best:  Diana  (94.4, A)
Worst: Charlie (57.6, F)

Subject averages:
  Math:    77.8
  Physics: 76.6
  CS:      78.0
  English: 81.2
  History: 76.4

Failing students written to failing.txt (1 student).
```
