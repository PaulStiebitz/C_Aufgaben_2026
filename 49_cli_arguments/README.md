# Exercise 49 – Command-Line Arguments & Program Options

## Topic
Arrays + Strings + `argc`/`argv`

## Objective
Parse and validate command-line arguments to build a simple CLI utility.

## Instructions

1. Create `cli_tool.c`.

2. The program should accept the following command-line options:
   ```
   ./cli_tool --upper  <string>   -> converts string to uppercase
   ./cli_tool --lower  <string>   -> converts string to lowercase
   ./cli_tool --rev    <string>   -> reverses the string
   ./cli_tool --len    <string>   -> prints the length
   ./cli_tool --count  <char> <string> -> counts occurrences of char in string
   ./cli_tool --help              -> prints usage instructions
   ```

3. Parse `argv` manually using `strcmp` for option matching.

4. If no arguments are given or the option is invalid, print an error and the usage help, then exit with code 1.

5. Implement the string operations yourself (no `<string.h>` needed except `strcmp` for argument parsing).

## Example Usage
```
$ ./cli_tool --upper "Hello World"
HELLO WORLD

$ ./cli_tool --rev "abcdef"
fedcba

$ ./cli_tool --count o "Hello World"
Occurrences of 'o' in "Hello World": 2

$ ./cli_tool --len "C programming"
Length: 13

$ ./cli_tool --help
Usage: ./cli_tool [option] [args]
Options:
  --upper  <string>
  --lower  <string>
  --rev    <string>
  --len    <string>
  --count  <char> <string>
  --help
```

## Hints
- `argc` is the argument count (including the program name), `argv[0]` is the program name.
- `argv[1]` is the first real argument (the option), `argv[2]` is the first value.
- Always check `argc >= required` before accessing `argv[n]`.
- `return 1;` from `main` signals an error exit code.
