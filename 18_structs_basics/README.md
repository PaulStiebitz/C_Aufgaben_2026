# Exercise 18 – Structs: Definition, Initialization & Functions

## Topic
Structs

## Objective
Define and use `struct` types to group related data, and write functions that accept structs by value and by pointer.

## Instructions

1. Create `structs_basic.c`.

2. Define the following struct:
   ```c
   typedef struct {
       char name[50];
       int age;
       float gpa;
   } Student;
   ```

3. Implement:
   - `Student create_student(const char *name, int age, float gpa);` – returns an initialized `Student`.
   - `void print_student(const Student *s);` – prints all fields.
   - `void birthday(Student *s);` – increments `s->age` by 1.
   - `Student best_student(const Student *a, const Student *b);` – returns the student with the higher GPA.

4. In `main`:
   - Create at least 3 students.
   - Print them.
   - Call `birthday` on one.
   - Find and print the best student.

## Expected Output (example)
```
Name: Alice,   Age: 20, GPA: 3.80
Name: Bob,     Age: 22, GPA: 3.50
Name: Charlie, Age: 21, GPA: 3.95

After birthday, Bob is now 23.
Best student: Charlie (GPA: 3.95)
```

## Hints
- Prefer passing structs **by pointer** (`Student *`) to avoid copying large structs.
- `const Student *` signals read-only access; use it for `print_student` and `best_student`.
- Use `strncpy` to copy string fields.
