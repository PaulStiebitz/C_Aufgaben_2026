# Exercise 86 – Struct Serialisation to JSON String

## Topic
Structs + Strings + File I/O + Variadic Functions

## Objective
Manually generate a JSON string representation of a struct — practising string building, formatted output, and file writing.

---

## Instructions

1. Create `json_writer.c`.

2. Define:
   ```c
   typedef struct {
       int   id;
       char  name[50];
       float score;
       int   active;   /* treated as boolean: true/false */
       char  tags[3][20];
       int   tag_count;
   } Record;
   ```

3. Implement:
   ```c
   /* Write a single Record as a JSON object to the given FILE* */
   void record_to_json(const Record *r, FILE *out);

   /* Write an array of Records as a JSON array */
   void records_array_to_json(const Record *arr, int n, FILE *out, int pretty);
   /* if pretty=1: indent with 2 spaces */
   ```

4. The `record_to_json` output must be valid JSON:
   ```json
   {
     "id": 1,
     "name": "Alice",
     "score": 95.50,
     "active": true,
     "tags": ["math", "science"]
   }
   ```

5. In `main`:
   - Create 3 records.
   - Print the JSON array to `stdout` (pretty-printed).
   - Write the JSON to `output.json` (compact, no spaces).
   - Read back `output.json` and print its raw content.

---

## Expected Output (pretty, stdout)
```json
[
  {
    "id": 1,
    "name": "Alice",
    "score": 95.50,
    "active": true,
    "tags": ["math", "science"]
  },
  {
    "id": 2,
    "name": "Bob",
    "score": 88.00,
    "active": false,
    "tags": ["history"]
  }
]
```

---

## Hints
- Escape strings: replace `"` with `\"`, `\` with `\\`, newlines with `\n`.
- Use `fprintf(out, "%s", indent)` to handle indentation uniformly.
- For the comma after each object (except the last), check `i < n-1`.
- `int active` → print `"true"` if non-zero, `"false"` if zero.
