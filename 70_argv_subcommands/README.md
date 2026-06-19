# Exercise 70 – `argc`/`argv`: Sub-Commands (git-style)

## Topic
`argc`/`argv` – Sub-Command Dispatch

## Objective
Build a multi-command CLI tool where the first argument is a **sub-command** (like `git add`, `git commit`), each with its own argument handling.

---

## Instructions

1. Create `subcmd.c`.

2. Implement a mini task manager with these sub-commands:
   ```
   ./tasks add    <title> [--priority high|medium|low]
   ./tasks list   [--sort name|priority|id] [--filter high|medium|low]
   ./tasks done   <id>
   ./tasks remove <id>
   ./tasks clear
   ./tasks help   [<command>]
   ```

3. Define:
   ```c
   typedef enum { PRIO_LOW, PRIO_MEDIUM, PRIO_HIGH } Priority;
   typedef struct {
       int      id;
       char     title[80];
       Priority priority;
       int      done;
   } Task;
   ```

4. Store tasks in a global array `Task tasks[100]; int task_count = 0;` (in-memory only — no file needed).

5. Implement a **command dispatch table**:
   ```c
   typedef struct {
       const char *name;
       int (*handler)(int argc, char *argv[]);
   } Command;
   ```
   Fill `Command commands[]` with entries for all sub-commands.

6. In `main`:
   - If `argc < 2`, print usage and exit.
   - Look up `argv[1]` in the command table.
   - Call the matched handler with `argc - 1` and `argv + 1` (shift arguments).
   - If not found, print `"Unknown command: <argv[1]>"` and list available commands.

---

## Expected Interaction (simulated in main with hardcoded calls)
```
$ ./tasks add "Buy groceries" --priority high
Added task [1]: "Buy groceries" (HIGH)

$ ./tasks add "Read a book"
Added task [2]: "Read a book" (MEDIUM)

$ ./tasks list
ID  TITLE              PRIORITY  STATUS
1   Buy groceries      HIGH      [ ]
2   Read a book        MEDIUM    [ ]

$ ./tasks done 1
Task [1] marked as done.

$ ./tasks list --filter high
1   Buy groceries      HIGH      [x]

$ ./tasks remove 2
Removed task [2].

$ ./tasks help add
Usage: tasks add <title> [--priority high|medium|low]
  Adds a new task. Default priority is medium.
```

---

## Hints
- The handler receives the remaining args after the sub-command: `handler(argc-1, argv+1)`, so `argv[0]` inside the handler is the sub-command name.
- Iterate the command table with a loop and `strcmp(argv[1], commands[i].name)`.
- Breaking the program into sub-command handlers keeps `main` clean.
