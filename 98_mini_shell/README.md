# Exercise 98 – All-Topics: Mini Shell

## Topic
All Topics – Applied Capstone

## Objective
Build a minimal interactive shell that executes built-in commands using a dispatcher, maintains command history in a linked list, and logs all activity to a file.

---

## Instructions

1. Create `minishell.c`.

2. **Built-in commands**:
   | Command | Description |
   |---------|-------------|
   | `echo <text>` | Print text |
   | `upper <text>` | Print uppercase |
   | `lower <text>` | Print lowercase |
   | `len <text>` | Print string length |
   | `rev <text>` | Print reversed string |
   | `calc <a> <op> <b>` | Evaluate arithmetic expression |
   | `sort <n> <v1> ... <vn>` | Sort n integers |
   | `history` | Print command history |
   | `history clear` | Clear command history |
   | `save <file>` | Save command history to file |
   | `load <file>` | Load and replay commands from file |
   | `help` | List all commands |
   | `exit` / `quit` | Exit the shell |

3. **Requirements**:
   - Command history: singly linked list of `char*` entries.
   - Log every command to `shell.log` with a counter: `[042] echo hello`.
   - Dispatcher: function pointer table (from exercise 89 pattern).
   - Argument splitting: `strtok` on the input line.
   - `load <file>`: open the file, read each line, re-run through the dispatcher (no logging/history for loaded commands).

4. **Structure**:
   ```c
   typedef struct HistNode { char cmd[256]; struct HistNode *next; } HistNode;
   typedef struct { HistNode *head; int count; } History;
   typedef int (*CmdHandler)(int argc, char **argv);
   typedef struct { const char *name; CmdHandler fn; const char *desc; } CmdEntry;
   ```

---

## Example Session
```
minishell> echo Hello, World!
Hello, World!

minishell> calc 7 * 6
7 * 6 = 42

minishell> sort 5 9 3 7 1 5
Sorted: 1 3 5 5 7 9

minishell> history
[1] echo Hello, World!
[2] calc 7 * 6
[3] sort 5 9 3 7 1 5

minishell> save session.txt
Saved 3 commands to session.txt.

minishell> exit
Goodbye. Logged 4 commands to shell.log.
```

---

## Hints
- `fgets(line, sizeof(line), stdin)` for input; handle EOF (Ctrl+D) as exit.
- Strip `\n` from the line before processing.
- Log format: open `shell.log` in append mode once at startup; write each command as it's entered.
- `load` opens the file, reads lines with `fgets`, calls `process_command` (same function as REPL) but skips adding to history/log.
