# Exercise 48 – Bitwise Operations & Flags

## Topic
Bitwise Operators + Enums

## Objective
Learn bitwise operations and use bit flags to store multiple boolean options in a single integer.

## Instructions

1. Create `bitwise.c`.

2. **Part A – Bitwise Basics**:
   Implement and demonstrate (print input, operation, and result for each):
   - `int set_bit(int n, int pos);` – sets bit at position `pos`.
   - `int clear_bit(int n, int pos);` – clears bit at position `pos`.
   - `int toggle_bit(int n, int pos);` – flips bit at position `pos`.
   - `int check_bit(int n, int pos);` – returns 1 if bit is set, 0 otherwise.
   - `void print_binary(unsigned int n, int bits);` – prints `n` in binary (MSB first, `bits` wide).

3. **Part B – Permission Flags**:
   ```c
   typedef enum {
       PERM_READ    = 1 << 0,   /* 0b001 */
       PERM_WRITE   = 1 << 1,   /* 0b010 */
       PERM_EXECUTE = 1 << 2    /* 0b100 */
   } Permission;
   ```
   - Write `void print_permissions(int flags);` – prints `rwx` style (e.g. `r-x`, `rw-`).
   - Create three variables: `user = READ|WRITE|EXECUTE`, `group = READ|EXECUTE`, `other = READ`.
   - Print their permissions.
   - Grant WRITE to `group`, revoke EXECUTE from `user`, toggle READ on `other`.

## Expected Output (example)
```
set_bit(0b0000, 2)   = 0b0100  (4)
clear_bit(0b1111, 1) = 0b1101  (13)
toggle_bit(0b1010,1) = 0b1000  (8)
check_bit(0b1010, 3) = 1

user:  rwx
group: r-x
other: r--
After changes:
user:  rw-
group: rw-  (was r-x, added w)
other: ---  (toggled r off)
```

## Hints
- `set_bit(n, p)` → `n | (1 << p)`.
- `clear_bit(n, p)` → `n & ~(1 << p)`.
- `toggle_bit(n, p)` → `n ^ (1 << p)`.
- `check_bit(n, p)` → `(n >> p) & 1`.
