# Exercise 89 – Command Dispatcher (Jump Table)

## Topic
Function Pointers + Structs + Arrays + Strings

## Objective
Build a command dispatcher using a table of function pointers — replacing a long `if/else if` or `switch` chain with a data-driven lookup.

---

## Instructions

1. Create `dispatcher.c`.

2. Define:
   ```c
   typedef int (*CommandFn)(int argc, char *argv[]);

   typedef struct {
       const char *name;
       const char *usage;
       const char *description;
       CommandFn   handler;
   } Command;
   ```

3. Implement **6 command handlers**:

   | Command | Args | Effect |
   |---------|------|--------|
   | `echo`     | `<text>` | Print text |
   | `count`    | `<text>` | Print word count of text |
   | `upper`    | `<text>` | Print uppercase version |
   | `repeat`   | `<n> <text>` | Print text n times |
   | `add`      | `<a> <b>` | Print sum of two floats |
   | `help`     | `[cmd]`  | Print help for all or one command |

4. Register all commands in a `Command dispatch_table[]` array.

5. Implement:
   ```c
   int dispatch(const Command *table, int count, const char *cmd_name,
                int argc, char *argv[]);
   /* Finds cmd_name in table, calls its handler. Returns -1 if not found. */
   ```

6. In `main`, simulate a **REPL loop** (Read-Eval-Print Loop):
   - Prompt `"> "`.
   - Read a line with `fgets`.
   - Split into tokens (command + args) using `strtok`.
   - Call `dispatch` with the first token as `cmd_name`.
   - Loop until `quit` or EOF.

---

## Example Session
```
> help
Available commands:
  echo    <text>    Print text to stdout
  count   <text>    Count words in text
  upper   <text>    Convert to uppercase
  repeat  <n> <t>   Repeat text n times
  add     <a> <b>   Add two numbers
  help    [cmd]     Show help

> echo Hello World
Hello World

> count one two three four
4

> upper hello
HELLO

> repeat 3 hi
hi
hi
hi

> add 3.5 1.5
5.00

> unknown
Unknown command: "unknown". Type "help" to list commands.

> quit
Goodbye.
```

---

## Hints
- Split the input line: `char *args[16]; int argc=0; char *tok = strtok(line," \n"); while(tok){args[argc++]=tok; tok=strtok(NULL," \n");}`
- `dispatch_table` must be terminated with a sentinel: `{NULL, NULL, NULL, NULL}`.
- Each handler receives `argc` and `argv` starting from the **command name** (like a real `main`).
