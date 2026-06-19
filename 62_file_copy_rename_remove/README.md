# Exercise 62 – File Handling: Copy, Rename, Remove

## Topic
File I/O – File Management (`rename`, `remove`, `tmpfile`)

## Objective
Implement file copy at the byte level and practise the standard file management functions.

---

## Instructions

1. Create `file_management.c`.

2. **Part A – Byte-level file copy**:
   Implement:
   ```c
   int file_copy(const char *src, const char *dst);
   ```
   - Opens `src` for binary reading and `dst` for binary writing.
   - Reads and writes in **chunks** of 512 bytes using `fread`/`fwrite` in a loop.
   - Returns 0 on success, -1 on any error (print `perror` on failure).
   - Verify the copy by printing both file sizes.

3. **Part B – Rename and remove**:
   - Create `original.txt` with some text.
   - Use `rename("original.txt", "renamed.txt")` to rename it.
   - Check the return value.
   - Use `remove("renamed.txt")` to delete it.
   - Try to open `renamed.txt` — it should fail.

4. **Part C – Temporary file**:
   - Use `tmpfile()` to create an anonymous temporary file.
   - Write 5 lines to it.
   - `rewind` to the start.
   - Read and print all lines.
   - `fclose` — the temp file is automatically deleted.

5. **Part D – Line count utility**:
   Implement:
   ```c
   int count_lines(const char *filename);   /* returns number of '\n' characters */
   long count_bytes(const char *filename);  /* returns file size */
   int  count_words(const char *filename);  /* splits by whitespace */
   ```

---

## Expected Output (example)
```
=== Part A ===
Copied "source.bin" (1024 bytes) -> "copy.bin" (1024 bytes). OK.

=== Part B ===
Created original.txt.
Renamed to renamed.txt. (rename returned 0)
Deleted renamed.txt.   (remove returned 0)
Open renamed.txt: No such file or directory.

=== Part C ===
Temp file: wrote 5 lines, read back:
  Line 1
  Line 2
  ...

=== Part D ===
lines=5, bytes=143, words=21 in "log.txt"
```

---

## Hints
- `rename(old, new)` returns 0 on success, non-zero on failure.
- `remove(path)` returns 0 on success.
- `tmpfile()` returns `FILE*` — never a path; the file vanishes on `fclose` or program exit.
- Copy-in-chunks pattern: `while ((n = fread(buf, 1, sizeof(buf), src)) > 0) fwrite(buf, 1, n, dst);`
- `ferror(fp)` after the loop checks whether the loop ended due to an error or clean EOF.
