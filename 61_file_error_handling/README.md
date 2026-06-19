# Exercise 61 – File Handling: Error Checking & `errno`

## Topic
File I/O – Robust Error Handling

## Objective
Write defensive file code that properly handles all error cases using `errno`, `perror`, `strerror`, and return codes.

---

## Instructions

1. Create `file_errors.c`. Include `<errno.h>`, `<string.h>`, `<stdio.h>`.

2. **Part A – fopen errors**:
   - Try to open a file that does not exist for reading. Catch the `NULL` return.
   - Print the error using all three methods:
     ```c
     perror("fopen");                         // prints to stderr
     fprintf(stderr, "%s\n", strerror(errno)); // manual
     fprintf(stderr, "errno = %d\n", errno);  // numeric code
     ```
   - Try to open a file with an invalid path (`"/root/secret.txt"` or `"///bad///path"`).

3. **Part B – fread / fwrite errors**:
   - Write 10 integers to `data.bin`.
   - Close and re-open for reading.
   - Use a loop with `fread` reading one int at a time.
   - Check `feof(fp)` and `ferror(fp)` after each read.
   - After the loop, print how many items were actually read.

4. **Part C – Utility function**:
   Implement:
   ```c
   FILE* safe_fopen(const char *path, const char *mode);
   ```
   - Opens the file, checks for `NULL`, prints a detailed error message and calls `exit(EXIT_FAILURE)` on failure.
   - Returns `FILE*` on success.

5. **Part D – File existence check**:
   Implement:
   ```c
   int file_exists(const char *path);  /* returns 1 if file exists, 0 otherwise */
   long file_size(const char *path);   /* returns size in bytes, -1 on error */
   ```
   Use `fopen` + `fseek(SEEK_END)` + `ftell`.

---

## Expected Output (example)
```
=== Part A ===
fopen("nofile.txt", "r"): No such file or directory
errno = 2

=== Part B ===
Read 10/10 integers: 0 1 2 3 4 5 6 7 8 9
feof=1, ferror=0

=== Part D ===
file_exists("data.bin")    = 1
file_exists("ghost.txt")   = 0
file_size("data.bin")      = 40 bytes
```

---

## Hints
- `errno` is set by failing system/library calls. Always read it **immediately** after the failure.
- `perror(s)` prints `"s: <error message>\n"` to `stderr` automatically.
- `strerror(errno)` returns a human-readable string for the current error code.
- Reset `errno = 0` before a call if you want a clean state.
- `SEEK_END` is the origin for seeking from the end of the file.
