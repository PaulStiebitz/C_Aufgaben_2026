# Exercise 66 – File Handling: Line-Oriented Text Processing

## Topic
File I/O – Text Processing (grep-like, wc-like)

## Objective
Process text files line by line to implement real-world tools: search (like `grep`), count (like `wc`), head/tail, and simple find-and-replace.

---

## Instructions

1. Create `text_tools.c`. Each function opens, processes, and closes its own file handle.

2. Implement the following tools:

   **A – `file_grep`**:
   ```c
   int file_grep(const char *filename, const char *pattern, int print_line_numbers);
   ```
   - Prints every line that contains `pattern` (use `strstr`).
   - If `print_line_numbers != 0`, prefix with `"lineN: "`.
   - Returns the count of matching lines.

   **B – `file_head` / `file_tail`**:
   ```c
   void file_head(const char *filename, int n);   /* print first n lines */
   void file_tail(const char *filename, int n);   /* print last n lines */
   ```
   - `file_tail`: read all lines into a circular buffer of `n` slots, then print.

   **C – `file_replace`**:
   ```c
   int file_replace(const char *filename, const char *find, const char *replace_with,
                    const char *out_filename);
   ```
   - Reads `filename` line by line.
   - Replaces **all occurrences** of `find` in each line with `replace_with`.
   - Writes to `out_filename`.
   - Returns the total number of substitutions made.

   **D – `file_stats`**:
   ```c
   void file_stats(const char *filename);
   ```
   Prints: filename, size in bytes, number of lines, number of words, number of unique characters (a-z, case-insensitive).

3. Create a sample text file `sample.txt` with at least 10 lines (mixed content).

4. In `main`, test every tool on `sample.txt`.

---

## Expected Output (example)
```
=== grep "the" (with line numbers) ===
line3:  The quick brown fox
line7:  In the beginning
Matches: 2

=== head 3 ===
Line 1: ...
Line 2: ...
Line 3: ...

=== tail 2 ===
Line 9: ...
Line 10: ...

=== replace "fox" -> "cat" -> out.txt: 1 substitution ===

=== stats: sample.txt ===
Size:    312 bytes
Lines:   10
Words:   52
Unique letters: 22
```

---

## Hints
- For `file_tail`: use `char lines[N][256]` as a circular buffer; use modulo to wrap the write index.
- For `file_replace`: since `strstr` only finds the first occurrence, loop inside each line.
- Build the replace logic step by step: find the match offset, copy the prefix, copy the replacement, continue from after the match.
