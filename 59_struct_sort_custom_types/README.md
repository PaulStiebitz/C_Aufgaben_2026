# Exercise 59 – Sorting Structs with Date and Time Fields

## Topic
Structs + Sorting + Date Comparison

## Objective
Sort structs that contain nested `Date` and `Time` structs as sort keys — practising multi-field struct comparisons.

---

## Instructions

1. Create `sort_datetime.c`.

2. Define:
   ```c
   typedef struct { int day; int month; int year; } Date;
   typedef struct { int hour; int minute; } Time;
   typedef struct {
       char  title[60];
       char  organizer[40];
       Date  date;
       Time  start_time;
       int   duration_min;
   } Event;
   ```

3. Implement helper comparison functions (return negative/0/positive):
   - `int cmp_date(const Date *a, const Date *b);`
     Compare year first, then month, then day.
   - `int cmp_time(const Time *a, const Time *b);`
     Compare hour first, then minute.

4. Implement `qsort` comparators:
   - `int cmp_event_by_date_time(const void *a, const void *b);`
     Sort by date, then by start time (chronological order).
   - `int cmp_event_by_duration_desc(const void *a, const void *b);`
     Sort by duration descending (longest first).
   - `int cmp_event_by_organizer_then_date(const void *a, const void *b);`
     Sort by organizer name, then by date.

5. Create an array of **6 events** (at least 2 on the same date with different times).

6. Implement `void print_event(const Event *e);` and `void print_events(const Event *arr, int n);`.

7. In `main`: print original, then all three sorted views.

---

## Date Comparison Pattern
```c
int cmp_date(const Date *a, const Date *b) {
    if (a->year  != b->year)  return a->year  - b->year;
    if (a->month != b->month) return a->month - b->month;
    return a->day - b->day;
}
```

---

## Expected Output (example)
```
--- Original ---
[Team Meeting]   Alice  15.03.2025 09:00  60 min
[Code Review]    Bob    12.03.2025 14:30  45 min
[Sprint Planning]Alice  15.03.2025 08:00  90 min
[Demo Day]       Carol  20.03.2025 10:00 120 min
...

--- Chronological (date then time) ---
[Code Review]     Bob   12.03.2025 14:30
[Sprint Planning] Alice 15.03.2025 08:00
[Team Meeting]    Alice 15.03.2025 09:00
[Demo Day]        Carol 20.03.2025 10:00

--- By Duration DESC ---
[Demo Day]        120 min
[Sprint Planning]  90 min
[Team Meeting]     60 min
[Code Review]      45 min
```

---

## Hints
- Reuse `cmp_date` and `cmp_time` inside the `qsort` comparators to keep them clean.
- Comparing dates as `year*10000 + month*100 + day` also works but is less readable.
- Use designated initialisers for nested structs: `{.date={15,3,2025}, .start_time={9,0}}`.
