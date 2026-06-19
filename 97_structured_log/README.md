# Exercise 97 – Variadic + File: Structured Log File

## Topic
Variadic Functions + File I/O + Structs + Enums

## Objective
Build a logging system that writes structured log entries (with timestamp simulation, level, module, and formatted message) to a log file — combining variadic formatting with file I/O.

---

## Instructions

1. Create `structlog.h` and `structlog.c`.

2. Define:
   ```c
   typedef enum { TRACE, DEBUG, INFO, WARN, ERROR, FATAL } Level;

   typedef struct {
       FILE    *file;
       Level    min_level;
       int      entry_count;
       long     byte_count;
   } LogFile;
   ```

3. Implement:
   ```c
   int  log_open(LogFile *lf, const char *filename, Level min_level);
   void log_close(LogFile *lf);

   void log_write(LogFile *lf, Level level, const char *module,
                  const char *fmt, ...);
   /* writes: "[LEVEL] [module] message\n" */

   /* Convenience macros: */
   #define LOG_INFO(lf, mod, ...)  log_write((lf), INFO,  (mod), __VA_ARGS__)
   #define LOG_WARN(lf, mod, ...)  log_write((lf), WARN,  (mod), __VA_ARGS__)
   #define LOG_ERROR(lf, mod, ...) log_write((lf), ERROR, (mod), __VA_ARGS__)

   void log_stats(const LogFile *lf);
   /* print: entries written, bytes written, log file path */

   int  log_rotate(LogFile *lf, const char *new_filename);
   /* close current file, rename it to new_filename, open a new empty file */
   ```

4. In `main.c`:
   - Open `app.log` with min_level=DEBUG.
   - Write 10+ log entries across different levels and modules.
   - Print stats.
   - Rotate the log (rename to `app.log.1`, open fresh `app.log`).
   - Write 3 more entries.
   - Read and print both log files.

---

## Expected log file content
```
[INFO ] [server  ] Starting server on port 8080
[DEBUG] [db      ] Connected to database at /var/db/app.db
[INFO ] [server  ] New connection from 127.0.0.1
[WARN ] [memory  ] Heap usage at 78% (156 MB / 200 MB)
[ERROR] [parser  ] Syntax error at line 42: unexpected token '}'
[INFO ] [server  ] Request processed in 12ms
```

---

## Hints
- Use `vfprintf` to forward the variadic args to the file (same as exercise 76).
- `log_rotate`: `fclose(lf->file)`, `rename(current_path, new_filename)`, `fopen(current_path, "w")`.
- Store the filename in `LogFile` so rotate can reference it.
- `log_stats` reads from the stored counters — no need to seek the file.
