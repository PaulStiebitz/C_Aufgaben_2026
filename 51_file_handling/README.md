# Exercise 51 – File Handling: Text & Binary Files

## Topic
File I/O – `fopen`, `fclose`, `fread`, `fwrite`, `fseek`, `ftell`, `rewind`

## Objective
Master all major file-handling operations in C: reading/writing text files line by line, working with binary files, and using file-position functions.

---

## Part A – Text File Operations

1. Create `filehandling.c`.

2. **Write a text file**:
   - Open `log.txt` in write mode (`"w"`).
   - Write 5 log lines using `fprintf`:
     ```
     [INFO]  Program started
     [DEBUG] Variable x = 42
     [WARN]  Low memory
     [ERROR] File not found
     [INFO]  Program ended
     ```
   - Close the file.

3. **Read line by line**:
   - Open `log.txt` in read mode (`"r"`).
   - Use `fgets` in a `while` loop to read and print each line.
   - Count and print the total number of lines.
   - Close the file.

4. **Append to the file**:
   - Open `log.txt` in append mode (`"a"`).
   - Add two more lines.
   - Close and re-read the file, print all lines again.

5. **Read word by word**:
   - Open `log.txt` and use `fscanf(fp, "%s", word)` to read every whitespace-separated token.
   - Count and print total tokens.

---

## Part B – Binary File Operations

6. Define:
   ```c
   typedef struct { int id; float temperature; char location[20]; } SensorRecord;
   ```

7. **Write binary**:
   - Create an array of 4 `SensorRecord` values.
   - Open `sensors.bin` in binary write mode (`"wb"`).
   - Write all records with a **single** `fwrite` call.
   - Close.

8. **Read binary**:
   - Open `sensors.bin` in binary read mode (`"rb"`).
   - Read all records back with `fread`.
   - Print each record.

9. **Random access**:
   - Use `fseek(fp, 2 * sizeof(SensorRecord), SEEK_SET)` to jump to the 3rd record.
   - Read and print just that record.
   - Use `ftell` to print the current file offset before and after the read.
   - Use `rewind(fp)` to go back to the start; read and print the first record.

---

## Expected Output (example)

```
=== Part A: Text File ===
Written log.txt (5 lines).

--- Read log.txt ---
[INFO]  Program started
[DEBUG] Variable x = 42
[WARN]  Low memory
[ERROR] File not found
[INFO]  Program ended
Total lines: 5

--- After append (7 lines) ---
...
Total tokens: 21

=== Part B: Binary File ===
Written 4 records to sensors.bin.

--- All records ---
ID:1  Temp:23.50  Location:Berlin
ID:2  Temp:31.20  Location:Munich
ID:3  Temp:18.90  Location:Hamburg
ID:4  Temp:27.10  Location:Cologne

--- Random access: record 3 ---
Offset before: 0 (after fseek to record 2)
ID:3  Temp:18.90  Location:Hamburg
Offset after read: 60

--- After rewind: record 1 ---
ID:1  Temp:23.50  Location:Berlin
```

---

## Key Functions Reference

| Function | Purpose |
|----------|---------|
| `fopen(path, mode)` | Open file; returns `FILE*` or `NULL` on error |
| `fclose(fp)` | Close file |
| `fprintf(fp, fmt, ...)` | Write formatted text |
| `fscanf(fp, fmt, ...)` | Read formatted text |
| `fgets(buf, n, fp)` | Read one line (safe) |
| `fwrite(ptr, size, n, fp)` | Write `n` binary objects |
| `fread(ptr, size, n, fp)` | Read `n` binary objects |
| `fseek(fp, offset, origin)` | Move file position |
| `ftell(fp)` | Get current file position |
| `rewind(fp)` | Reset position to start |
| `feof(fp)` | Returns non-zero at end of file |
| `ferror(fp)` | Returns non-zero on I/O error |

---

## Hints
- **Always** check `fopen` return value: `if (fp == NULL) { perror("fopen"); return 1; }`.
- `perror("msg")` prints `msg: <system error message>` — very useful for debugging.
- Text mode (`"r"`, `"w"`) vs binary mode (`"rb"`, `"wb"`) matters on Windows (line-endings); use binary for structs always.
- `fseek(fp, 0, SEEK_END)` + `ftell(fp)` gives you the file size in bytes.
- Do not mix `fgets`/`fprintf` and `fread`/`fwrite` on the same file handle.
