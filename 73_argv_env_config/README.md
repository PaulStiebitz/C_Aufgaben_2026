# Exercise 73 – `argc`/`argv`: Environment Variables & Program Configuration

## Topic
`argc`/`argv` + `getenv` + Program Configuration Priority

## Objective
Combine command-line arguments, environment variables, a config file, and built-in defaults into a **priority-based configuration** system.

---

## Background

Real programs read settings from multiple sources with a priority order:
```
1. Command-line arguments  (highest priority — overrides everything)
2. Environment variables
3. Config file
4. Built-in defaults       (lowest priority — fallback)
```

---

## Instructions

1. Create `config_priority.c`. Include `<stdlib.h>` for `getenv`.

2. Define:
   ```c
   typedef struct {
       char host[60];
       int  port;
       int  verbose;
       char logfile[100];
   } Config;
   ```

3. Implement a configuration loader with the full priority chain:

   **Step 1 – Apply defaults**:
   ```c
   void config_defaults(Config *c);
   /* host="localhost", port=8080, verbose=0, logfile="app.log" */
   ```

   **Step 2 – Load from file** (`app.cfg`, key=value format):
   ```c
   void config_from_file(Config *c, const char *filename);
   ```

   **Step 3 – Override from environment variables**:
   ```c
   void config_from_env(Config *c);
   ```
   Check: `APP_HOST`, `APP_PORT`, `APP_VERBOSE`, `APP_LOGFILE`.
   Use `getenv("APP_HOST")` — if not `NULL`, override the field.

   **Step 4 – Override from command-line args**:
   ```c
   void config_from_args(Config *c, int argc, char *argv[]);
   ```
   Parse: `--host <h>`, `--port <p>`, `--verbose`, `--logfile <f>`.

4. In `main`:
   - Run all four steps in order.
   - Print the final config with the **source** of each value (default / file / env / arg).

---

## Testing
```bash
# Test environment variable override:
APP_PORT=9090 ./config_priority

# Test argument override:
./config_priority --host production.server --port 443 --verbose

# Test full priority:
APP_HOST=envhost ./config_priority --port 1234
```

## Expected Output
```
Final configuration:
  host    = "production.server"  [from: arg]
  port    = 443                  [from: arg]
  verbose = 1                    [from: arg]
  logfile = "app.log"            [from: default]
```

---

## Hints
- `getenv` returns `char*` (not a copy) — copy it with `strncpy` to store safely.
- Track the source by keeping a parallel `char source[4][20]` array.
- `setenv("APP_PORT", "9090", 1)` can be used in tests (POSIX only; alternatively use environment before running).
