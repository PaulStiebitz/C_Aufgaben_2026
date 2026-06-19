# Exercise 44 – Enum-Driven Menu System

## Topic
Enums + Structs + Functions + Control Flow

## Objective
Build an interactive command-line menu system using enums for menu options and a function dispatch table.

## Instructions

1. Create `menu_system.c`.

2. Define:
   ```c
   typedef enum {
       MENU_ADD = 1,
       MENU_REMOVE,
       MENU_SEARCH,
       MENU_PRINT_ALL,
       MENU_SORT,
       MENU_QUIT
   } MenuOption;

   typedef struct { int data[100]; int size; } IntArray;
   ```

3. Implement handler functions:
   - `void handle_add(IntArray *a);` – prompts for a value, appends it.
   - `void handle_remove(IntArray *a);` – prompts for a value, removes first occurrence.
   - `void handle_search(const IntArray *a);` – prompts for a value, prints index or "not found".
   - `void handle_print(const IntArray *a);` – prints all elements.
   - `void handle_sort(IntArray *a);` – sorts ascending in-place.

4. In `main`:
   - Print the menu in a loop until the user chooses `QUIT`.
   - Read the user's choice, cast to `MenuOption`, dispatch to the right handler.
   - Validate input (not < 1 or > 6).

## Example Interaction
```
=== Integer Array Manager ===
1) Add value
2) Remove value
3) Search
4) Print all
5) Sort
6) Quit
> 1
Enter value: 42
Added 42.
> 4
Array: [42]
> 6
Goodbye!
```

## Hints
- Use a `switch(option)` to dispatch.
- Use `scanf("%d", &choice)` for menu input — flush `stdin` with `while(getchar()!='\n')` after.
- Enums provide readable labels instead of magic numbers.
