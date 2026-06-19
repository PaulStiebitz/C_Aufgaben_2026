# Exercise 23 – Unions: Memory Layout & Tagged Variant

## Topic
Unions + Structs

## Objective
Explore how unions share memory and implement a type-safe tagged union (discriminated union) pattern.

## Instructions

1. Create `unions_tagged.c`.

2. **Part A – Memory Layout**:
   - Define `union DataU { int i; float f; double d; char bytes[8]; };`
   - Print `sizeof(DataU)`.
   - Store an integer, then inspect the raw `bytes[]` — print each byte as hex.
   - Explain in a comment why the size equals the largest member.

3. **Part B – Tagged Union (JSON-like value)**:
   ```c
   typedef enum { JSON_NULL, JSON_BOOL, JSON_INT, JSON_FLOAT, JSON_STRING } JsonType;
   typedef struct {
       JsonType type;
       union {
           int   bool_val;   /* 0 or 1 */
           int   int_val;
           float float_val;
           char  str_val[64];
       } data;
   } JsonValue;
   ```
   - Write `void json_print(const JsonValue *v);` that prints the value according to its type:
     - `null`, `true`/`false`, integer, float, or `"string"`.
   - In `main`, create one `JsonValue` of each type and print them.

## Expected Output (example)
```
sizeof(DataU) = 8
int 42 as bytes: 2a 00 00 00 00 00 00 00

JSON values:
null
true
42
3.140000
"hello world"
```

## Hints
- Casting `(unsigned char *)` lets you inspect individual bytes safely.
- Little-endian systems store the least significant byte first.
