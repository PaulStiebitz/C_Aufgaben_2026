# Exercise 65 – File Handling: Binary Index File

## Topic
File I/O – Binary Files + Random Access + Index Tables

## Objective
Build a binary data file with a separate index for O(1) random access by record number — a simplified database file format.

---

## Instructions

1. Create `binary_index.c`.

2. Define:
   ```c
   typedef struct {
       int   id;
       char  name[40];
       float value;
   } Record;

   typedef struct {
       int  record_count;
       long offsets[100];   /* byte offset of each record in data.bin */
   } Index;
   ```

3. **Write phase**:
   - Create 8 `Record` values.
   - Open `data.bin` (binary write).
   - For each record:
     - Use `ftell` to get the current offset — store it in `index.offsets[i]`.
     - Write the record with `fwrite`.
   - Set `index.record_count = 8`.
   - Close `data.bin`.
   - Write the `Index` struct to `index.bin` (single `fwrite`).

4. **Read phase (sequential)**:
   - Load `index.bin` with `fread`.
   - Open `data.bin` for reading.
   - Loop over all records sequentially and print each.

5. **Random access phase**:
   - Use the loaded index to jump directly to record `i` using `fseek(fp, index.offsets[i], SEEK_SET)`.
   - Implement:
     ```c
     int read_record_by_index(FILE *fp, const Index *idx, int i, Record *out);
     ```
   - In `main`: read and print records 0, 5, 3 (out of order) to prove random access works.

6. **Update in place**:
   - Open `data.bin` in `"rb+"` mode (read + write, no truncate).
   - Seek to record 2's offset and overwrite it with a modified version.
   - Re-read all records sequentially to confirm the change.

---

## Expected Output
```
=== Sequential read ===
[0] id=1  name=Alpha   value=10.50
[1] id=2  name=Beta    value=20.00
...

=== Random access ===
Record 0: id=1  name=Alpha   value=10.50
Record 5: id=6  name=Zeta    value=60.75
Record 3: id=4  name=Delta   value=40.25

=== After in-place update (record 2 modified) ===
[0] id=1  Alpha   10.50
[1] id=2  Beta    20.00
[2] id=99 UPDATED 99.99   <- modified
[3] id=4  Delta   40.25
...
```

---

## Hints
- `ftell` before `fwrite` gives the **offset of the record about to be written**.
- `fseek(fp, offset, SEEK_SET)` jumps to an absolute byte position.
- Opening with `"rb+"` allows both reading and writing without truncating.
- This technique is the foundation of flat-file databases and binary log files.
