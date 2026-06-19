# Exercise 22 – Bit Fields in Structs

## Topic
Structs + Bit Fields

## Objective
Use bit fields inside a struct to pack multiple small values into a single machine word.

## Instructions

1. Create `bitfields.c`.

2. Define a struct representing a hardware status register using bit fields:
   ```c
   typedef struct {
       unsigned int power_on   : 1;
       unsigned int error      : 1;
       unsigned int mode       : 2;   /* 0=idle, 1=run, 2=pause, 3=shutdown */
       unsigned int brightness : 4;   /* 0-15 */
       unsigned int reserved   : 24;
   } StatusReg;
   ```

3. Implement:
   - `void print_status(const StatusReg *r);` – prints each field by name and value.
   - A function `const char* mode_name(unsigned int mode);` that maps 0–3 to strings.

4. In `main`:
   - Create and initialize a `StatusReg` variable using designated initializers.
   - Print its size (`sizeof`).
   - Modify fields individually and print again.
   - Try setting `brightness = 20` (overflow) and show what value is actually stored.

## Expected Output (example)
```
sizeof(StatusReg) = 4 bytes
power_on:   1
error:      0
mode:       1 (run)
brightness: 7
---
After update:
brightness: 15
---
Overflow test (set brightness=20): stored value = 4
```

## Hints
- `unsigned int field : N` declares a field of exactly N bits.
- Values that exceed the bit width are **truncated** (modulo `2^N`).
- Bit fields cannot be addressed with `&`.
