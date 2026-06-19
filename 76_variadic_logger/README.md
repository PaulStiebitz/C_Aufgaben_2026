# Exercise 76 – Variadic Functions: Flexible Logger

## Topic
Variadic Functions + File I/O + Enums

## Objective
Build a production-style logging library with severity levels, timestamps, and formatted messages using variadic functions.

---

## Instructions

1. Create `logger.h` and `logger.c`.

2. Define:
   ```c
   typedef enum { LOG_DEBUG, LOG_INFO, LOG_WARN, LOG_ERROR, LOG_FATAL } LogLevel;

   typedef struct {
       LogLevel  min_level;   /* only log messages >= min_level */
       FILE     *output;      /* e.g. stderr or a file */
       int       show_level;  /* prefix with [LEVEL] */
       int       show_time;   /* prefix with timestamp (use __TIME__) */
   } Logger;
   ```

3. Implement:
   ```c
   void logger_init(Logger *l, LogLevel min_level, FILE *output);

   /* Core logging function — variadic, like printf */
   void logger_log(Logger *l, LogLevel level, const char *fmt, ...);

   /* Convenience macros */
   #define LOG_DEBUG(l, ...) logger_log((l), LOG_DEBUG, __VA_ARGS__)
   #define LOG_INFO(l, ...)  logger_log((l), LOG_INFO,  __VA_ARGS__)
   #define LOG_WARN(l, ...)  logger_log((l), LOG_WARN,  __VA_ARGS__)
   #define LOG_ERROR(l, ...) logger_log((l), LOG_ERROR, __VA_ARGS__)
   ```

4. Inside `logger_log`:
   - If `level < l->min_level`, return immediately (filtered out).
   - Build the prefix: optionally `[INFO] ` and/or `[HH:MM:SS] `.
   - Use `vfprintf(l->output, fmt, args)` to forward the variadic args to `fprintf`.

5. In `main.c`:
   - Create two loggers: one to `stderr` (min=INFO), one to `app.log` file (min=DEBUG).
   - Log messages at all levels through both loggers.
   - Show that DEBUG messages appear in the file but not on stderr.

---

## Key: `vfprintf`
```c
void logger_log(Logger *l, LogLevel level, const char *fmt, ...) {
    va_list args;
    va_start(args, fmt);
    /* ... print prefix ... */
    vfprintf(l->output, fmt, args);  // forward entire va_list to fprintf
    va_end(args);
}
```

---

## Expected Output
```
--- stderr (min=INFO) ---
[INFO]  Server started on port 8080
[WARN]  Memory usage at 85%
[ERROR] Failed to open config file: No such file or directory

--- app.log (min=DEBUG) ---
[DEBUG] Entering function parse_config
[DEBUG] Read 42 bytes
[INFO]  Server started on port 8080
[WARN]  Memory usage at 85%
[ERROR] Failed to open config file: No such file or directory
```

---

## Hints
- `vfprintf` is the key: it takes a `va_list` directly, letting you delegate formatted output.
- `__VA_ARGS__` in macros passes the entire argument list to the function.
- `__TIME__` is a compile-time string like `"14:22:05"` — for a runtime clock use `time.h` (optional).
- `LOG_FATAL` could call `exit(EXIT_FAILURE)` after logging.
