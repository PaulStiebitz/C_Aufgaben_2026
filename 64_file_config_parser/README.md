# Exercise 64 – File Handling: Config File Parser

## Topic
File I/O – INI-Style Configuration Files

## Objective
Parse a simple `key = value` configuration file (like `.ini` or `.env`) into a struct, and write config back to a file.

---

## Instructions

1. Create `config_parser.c`.

2. Define a config struct:
   ```c
   typedef struct {
       char  server_host[60];
       int   server_port;
       int   max_connections;
       char  log_level[10];   /* "DEBUG", "INFO", "WARN", "ERROR" */
       int   timeout_sec;
       char  db_path[100];
   } AppConfig;
   ```

3. **Config file format** (`app.cfg`):
   ```
   # Server settings
   server_host  = localhost
   server_port  = 8080
   max_connections = 100
   
   # Logging
   log_level    = INFO
   timeout_sec  = 30
   
   # Database
   db_path      = /var/data/myapp.db
   ```
   Rules:
   - Lines starting with `#` are comments → skip.
   - Empty lines → skip.
   - Each data line: `key = value` (whitespace around `=` is allowed).

4. Implement:
   ```c
   int  config_load(const char *filename, AppConfig *cfg);
   void config_print(const AppConfig *cfg);
   int  config_save(const char *filename, const AppConfig *cfg);
   ```
   - `config_load`: reads `app.cfg`, uses `strtok`/`sscanf` to split on `=`, trims whitespace, assigns fields.
   - `config_save`: writes the struct back as a formatted config file.

5. In `main`:
   - Load `app.cfg`, print all fields.
   - Modify `server_port` to 9090 and `log_level` to `"DEBUG"`.
   - Save to `app_modified.cfg`.
   - Load `app_modified.cfg` and print to verify.

---

## Expected Output
```
Loaded app.cfg:
  server_host    = localhost
  server_port    = 8080
  max_connections= 100
  log_level      = INFO
  timeout_sec    = 30
  db_path        = /var/data/myapp.db

Saved modified config to app_modified.cfg.

Loaded app_modified.cfg:
  server_host    = localhost
  server_port    = 9090
  log_level      = DEBUG
  ...
```

---

## Hints
- To trim whitespace around a token: advance the pointer past leading spaces, then null-terminate before trailing spaces.
- `sscanf(line, " %49[^=] = %99[^\n]", key, value)` can split on `=` and trim leading spaces.
- Use `strncmp` to check if a key matches: `if (strcmp(key, "server_port") == 0) cfg->server_port = atoi(value);`
- A helper `void trim(char *s)` that removes leading/trailing whitespace is very useful here.
