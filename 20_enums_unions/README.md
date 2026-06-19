# Exercise 20 – Enums and Unions

## Topic
Enums & Unions

## Objective
Understand the purpose of `enum` for named constants and `union` for memory-efficient type variants.

## Instructions

### Part A – Enums

1. Define an enum for days of the week:
   ```c
   typedef enum { MON=1, TUE, WED, THU, FRI, SAT, SUN } Weekday;
   ```

2. Write `const char* weekday_name(Weekday d);` that returns the name as a string.

3. Write `int is_weekend(Weekday d);` returning 1 for SAT/SUN, 0 otherwise.

4. Loop from MON to SUN, print name and whether it's a weekend day.

### Part B – Unions

5. Define:
   ```c
   typedef union {
       int   i;
       float f;
       char  c;
   } Value;
   ```

6. Demonstrate that all fields share the same memory by:
   - Setting `v.i = 65`, then printing `v.i`, `v.f`, `v.c` — show the aliasing effect.

7. Define a **tagged union**:
   ```c
   typedef enum { TYPE_INT, TYPE_FLOAT, TYPE_CHAR } ValueType;
   typedef struct { ValueType type; Value val; } TaggedValue;
   ```
   Write `void print_value(const TaggedValue *tv);` that prints the correct field based on `type`.

## Expected Output (example)
```
Mon: weekday | Tue: weekday | ... | Sat: WEEKEND | Sun: WEEKEND
Union aliasing: i=65, f=9.1e-44, c='A'
TaggedValue(INT)   -> 42
TaggedValue(FLOAT) -> 3.14
TaggedValue(CHAR)  -> 'Z'
```

## Hints
- Enums start at 0 by default; you can override with `= value`.
- Only **one** union member holds a meaningful value at a time — the tagged union pattern makes this safe.
