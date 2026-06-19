# C Exam Preparation – 100 Exercises

A structured set of **100 hands-on exercises** designed to prepare you for a C programming exam.
All exercises are in English, contain **no solutions**, and progress from beginner to intermediate–advanced difficulty.

---

## Topic Overview

| Range | Topic |
|-------|-------|
| 01–05 | Custom Libraries (`.h` / `.c`, include guards) |
| 06–10 | Sorting Algorithms (Bubble, Selection, Insertion, Merge, Quick, Heap) |
| 11–15 | Arrays, Strings, Pointers, Dynamic Memory |
| 16–17 | Double Pointers, Function Pointers |
| 18–24 | Structs, Nested Structs, Bit Fields, Unions, Enums |
| 25–32 | Singly & Doubly Linked Lists, Stack, Queue, Deque |
| 33–36 | String Library (`<string.h>` + custom reimplementation) |
| 37–40 | BST, `qsort`, File I/O, Preprocessor Macros |
| 41–53 | Mixed Applied (databases, recursion, menus, split/join, hashmap, bitwise, CLI) |
| **51** | **File Handling** – text, binary, `fseek`/`ftell` |
| **52** | **`argc`/`argv`** – inspection, typed parsing, flags, `wordcount` |
| **53** | **Variadic Functions** – `va_list`, mini-printf, sentinel, `va_copy` |
| **54–60** | **Struct Sorting** – single/multi-field, pointer arrays, linked list, stable, date/time, generic |
| **61–67** | **File Handling (Advanced)** – `errno`, copy/rename/remove, CSV, config parser, binary index, text tools, serialise |
| **68–74** | **`argc`/`argv` (Advanced)** – type validation, getopt-style, sub-commands, pipeline tool, calculator, env config, batch processor |
| **75–80** | **Variadic Functions (Advanced)** – type-tagged args, logger, table printer, string builder, generics, event system |
| **81–90** | **Data Structures & Algorithms** – memory pool, ring buffer, priority queue, runtime table, lexer, JSON writer, sparse matrix, generic stack, dispatcher, graph |
| **91–100** | **Capstone Projects** – LRU cache, grade book, expression evaluator, matrix library, data pipeline, string array lib, structured log, mini shell, KV store, DB engine |

---

## Full Exercise Index

| # | Folder | Title | Topic |
|---|--------|-------|-------|
| 01 | [`01_custom_library_math`](01_custom_library_math/) | Custom Math Library | Libraries |
| 02 | [`02_custom_library_string`](02_custom_library_string/) | Custom String Utility Library | Libraries |
| 03 | [`03_custom_library_geometry`](03_custom_library_geometry/) | Geometry Library | Libraries |
| 04 | [`04_custom_library_statistics`](04_custom_library_statistics/) | Statistics Library | Libraries |
| 05 | [`05_custom_library_linkedlist`](05_custom_library_linkedlist/) | Linked-List Library | Libraries |
| 06 | [`06_sorting_bubblesort`](06_sorting_bubblesort/) | Bubble Sort | Sorting |
| 07 | [`07_sorting_selectionsort`](07_sorting_selectionsort/) | Selection Sort | Sorting |
| 08 | [`08_sorting_insertionsort`](08_sorting_insertionsort/) | Insertion Sort | Sorting |
| 09 | [`09_sorting_mergesort`](09_sorting_mergesort/) | Merge Sort | Sorting |
| 10 | [`10_sorting_quicksort_heapsort`](10_sorting_quicksort_heapsort/) | Quick Sort + Heap Sort | Sorting |
| 11 | [`11_arrays_basics`](11_arrays_basics/) | Array Basics | Arrays |
| 12 | [`12_arrays_2d_matrix`](12_arrays_2d_matrix/) | 2D Arrays & Matrix | Arrays |
| 13 | [`13_strings_basics`](13_strings_basics/) | String Basics | Strings |
| 14 | [`14_pointer_arithmetic`](14_pointer_arithmetic/) | Pointer Arithmetic | Pointers |
| 15 | [`15_dynamic_memory`](15_dynamic_memory/) | Dynamic Memory | Pointers |
| 16 | [`16_pointers_double`](16_pointers_double/) | Double Pointers | Pointers |
| 17 | [`17_function_pointers`](17_function_pointers/) | Function Pointers | Pointers |
| 18 | [`18_structs_basics`](18_structs_basics/) | Struct Basics | Structs |
| 19 | [`19_structs_nested`](19_structs_nested/) | Nested Structs & Arrays | Structs |
| 20 | [`20_enums_unions`](20_enums_unions/) | Enums + Unions | Enums/Unions |
| 21 | [`21_struct_dynamic_array`](21_struct_dynamic_array/) | Struct + Resizable Array | Structs |
| 22 | [`22_struct_bitfields`](22_struct_bitfields/) | Bit Fields | Structs |
| 23 | [`23_unions_tagged`](23_unions_tagged/) | Tagged Unions | Unions |
| 24 | [`24_enums_state_machine`](24_enums_state_machine/) | FSM with Enum | Enums |
| 25 | [`25_linked_list_basic`](25_linked_list_basic/) | Singly Linked List | Linked Lists |
| 26 | [`26_linked_list_ops`](26_linked_list_ops/) | Search, Insert, Delete | Linked Lists |
| 27 | [`27_linked_list_reverse_cycle`](27_linked_list_reverse_cycle/) | Reverse + Cycle Detection | Linked Lists |
| 28 | [`28_stack_linked_list`](28_stack_linked_list/) | Stack (Linked List) | Linked Lists |
| 29 | [`29_queue_linked_list`](29_queue_linked_list/) | Queue (Linked List) | Linked Lists |
| 30 | [`30_dlinked_list_basic`](30_dlinked_list_basic/) | Doubly Linked List Basics | DLL |
| 31 | [`31_dlinked_list_ops`](31_dlinked_list_ops/) | DLL Insert/Delete/Sorted | DLL |
| 32 | [`32_deque_dlinked_list`](32_deque_dlinked_list/) | Deque | DLL |
| 33 | [`33_string_library`](33_string_library/) | `<string.h>` Tour | Strings |
| 34 | [`34_string_parsing`](34_string_parsing/) | String Parsing & Conversion | Strings |
| 35 | [`35_custom_string_lib_part1`](35_custom_string_lib_part1/) | Custom `<string.h>` Part 1 | Strings |
| 36 | [`36_custom_string_lib_part2`](36_custom_string_lib_part2/) | Custom `<string.h>` Part 2 | Strings |
| 37 | [`37_binary_search_tree`](37_binary_search_tree/) | Binary Search Tree | Pointers+Structs |
| 38 | [`38_generic_sort_qsort`](38_generic_sort_qsort/) | Generic `qsort` | Function Pointers |
| 39 | [`39_file_io_structs`](39_file_io_structs/) | File I/O with Structs | File I/O |
| 40 | [`40_preprocessor_macros`](40_preprocessor_macros/) | Macros + `#ifdef` | Preprocessor |
| 41 | [`41_student_database`](41_student_database/) | Student Database | Mixed |
| 42 | [`42_linked_list_contacts`](42_linked_list_contacts/) | Contact Book | Mixed |
| 43 | [`43_recursion_pointers`](43_recursion_pointers/) | Recursion + Pointers | Mixed |
| 44 | [`44_enum_menu_system`](44_enum_menu_system/) | Enum-Driven Menu | Mixed |
| 45 | [`45_string_split_join`](45_string_split_join/) | Split & Join | Mixed |
| 46 | [`46_dlist_sort_merge`](46_dlist_sort_merge/) | DLL Sort & Merge | DLL |
| 47 | [`47_hashmap`](47_hashmap/) | Hash Map | Mixed |
| 48 | [`48_bitwise_flags`](48_bitwise_flags/) | Bitwise + Flags | Bitwise |
| 49 | [`49_cli_arguments`](49_cli_arguments/) | CLI Arguments | argc/argv |
| 50 | [`50_capstone_inventory`](50_capstone_inventory/) | **Capstone – Inventory** | Mixed |
| 51 | [`51_file_handling`](51_file_handling/) | File Handling (Text + Binary) | **File I/O** |
| 52 | [`52_argc_argv`](52_argc_argv/) | `argc`/`argv` Fundamentals | **argc/argv** |
| 53 | [`53_variadic_functions`](53_variadic_functions/) | Variadic Fundamentals | **Variadic** |
| 54 | [`54_struct_sort_single_field`](54_struct_sort_single_field/) | Sort Struct by 1 Field | **Struct Sort** |
| 55 | [`55_struct_sort_multi_field`](55_struct_sort_multi_field/) | Multi-Key Sort | **Struct Sort** |
| 56 | [`56_struct_sort_pointers`](56_struct_sort_pointers/) | Sort Pointer Array | **Struct Sort** |
| 57 | [`57_struct_sort_linked_list`](57_struct_sort_linked_list/) | Sort Linked List of Structs | **Struct Sort** |
| 58 | [`58_struct_sort_stable`](58_struct_sort_stable/) | Stable Sort + Index Sort | **Struct Sort** |
| 59 | [`59_struct_sort_custom_types`](59_struct_sort_custom_types/) | Sort by Date/Time | **Struct Sort** |
| 60 | [`60_struct_sort_generic`](60_struct_sort_generic/) | Generic Sort Table | **Struct Sort** |
| 61 | [`61_file_error_handling`](61_file_error_handling/) | `errno` + `perror` | **File I/O** |
| 62 | [`62_file_copy_rename_remove`](62_file_copy_rename_remove/) | Copy, Rename, Remove, tmpfile | **File I/O** |
| 63 | [`63_file_csv`](63_file_csv/) | CSV Parser & Writer | **File I/O** |
| 64 | [`64_file_config_parser`](64_file_config_parser/) | Config File Parser | **File I/O** |
| 65 | [`65_file_binary_index`](65_file_binary_index/) | Binary Index File | **File I/O** |
| 66 | [`66_file_text_processing`](66_file_text_processing/) | grep, head, tail, replace | **File I/O** |
| 67 | [`67_file_linked_list_serialise`](67_file_linked_list_serialise/) | Serialise Linked List | **File I/O** |
| 68 | [`68_argv_type_validation`](68_argv_type_validation/) | Type Validation | **argc/argv** |
| 69 | [`69_argv_optparser`](69_argv_optparser/) | getopt-style Parser | **argc/argv** |
| 70 | [`70_argv_subcommands`](70_argv_subcommands/) | Sub-Commands (git-style) | **argc/argv** |
| 71 | [`71_argv_file_pipeline`](71_argv_file_pipeline/) | File Pipeline Tool | **argc/argv** |
| 72 | [`72_argv_calculator`](72_argv_calculator/) | CLI Calculator | **argc/argv** |
| 73 | [`73_argv_env_config`](73_argv_env_config/) | Env Vars + Priority Config | **argc/argv** |
| 74 | [`74_argv_batch_processor`](74_argv_batch_processor/) | Batch File Processor | **argc/argv** |
| 75 | [`75_variadic_type_tagged`](75_variadic_type_tagged/) | Type-Tagged Args | **Variadic** |
| 76 | [`76_variadic_logger`](76_variadic_logger/) | Flexible Logger | **Variadic** |
| 77 | [`77_variadic_table_printer`](77_variadic_table_printer/) | Table Printer | **Variadic** |
| 78 | [`78_variadic_string_builder`](78_variadic_string_builder/) | String Builder | **Variadic** |
| 79 | [`79_variadic_macros_generic`](79_variadic_macros_generic/) | Generic Macros + `_Generic` | **Variadic** |
| 80 | [`80_variadic_event_system`](80_variadic_event_system/) | Event System | **Variadic** |
| 81 | [`81_memory_pool`](81_memory_pool/) | Memory Pool Allocator | Memory |
| 82 | [`82_ring_buffer`](82_ring_buffer/) | Circular Ring Buffer | Data Structures |
| 83 | [`83_priority_queue`](83_priority_queue/) | Priority Queue (Min-Heap) | Data Structures |
| 84 | [`84_runtime_table`](84_runtime_table/) | Runtime-Schema Table | Mixed |
| 85 | [`85_string_lexer`](85_string_lexer/) | String Tokenizer / Lexer | Strings |
| 86 | [`86_json_writer`](86_json_writer/) | JSON Struct Serialiser | Strings+Files |
| 87 | [`87_sparse_matrix`](87_sparse_matrix/) | Sparse Matrix | Linked Lists |
| 88 | [`88_generic_stack`](88_generic_stack/) | Generic `void*` Stack | Pointers |
| 89 | [`89_command_dispatcher`](89_command_dispatcher/) | Command Dispatcher (REPL) | Function Pointers |
| 90 | [`90_graph_adjacency_list`](90_graph_adjacency_list/) | Graph (BFS, DFS) | Linked Lists |
| 91 | [`91_lru_cache`](91_lru_cache/) | LRU Cache | DLL + Hash Map |
| 92 | [`92_gradebook`](92_gradebook/) | Grade Book Full Pipeline | Mixed |
| 93 | [`93_expression_evaluator`](93_expression_evaluator/) | RPN + Shunting-Yard | Stacks |
| 94 | [`94_matrix_library`](94_matrix_library/) | Full Matrix Library | Libraries |
| 95 | [`95_data_pipeline_tool`](95_data_pipeline_tool/) | argv + File + Sort Pipeline | Mixed |
| 96 | [`96_strarray_library`](96_strarray_library/) | Dynamic String Array Library | Libraries |
| 97 | [`97_structured_log`](97_structured_log/) | Structured Log File | Variadic+Files |
| 98 | [`98_mini_shell`](98_mini_shell/) | Mini Shell | Capstone |
| 99 | [`99_kvstore`](99_kvstore/) | In-Memory Key-Value Store | Capstone |
| 100 | [`100_grand_capstone_db_engine`](100_grand_capstone_db_engine/) | **Grand Capstone: DB Engine** | **ALL TOPICS** |

---

## Recommended Study Path

```
Week 1 – Core Foundations
  01-05   Custom libraries (.h/.c, include guards)
  06-10   Sorting algorithms
  11-17   Arrays, strings, pointers, memory

Week 2 – Structs & Data Structures
  18-24   Structs, bit fields, unions, enums
  25-32   Linked lists (singly, doubly), stack, queue, deque
  33-36   String library

Week 3 – File I/O & argc/argv
  39, 51  File I/O basics + full coverage
  61-67   File handling advanced (errno, CSV, config, binary index)
  49, 52  argc/argv basics
  68-74   argc/argv advanced (optparser, sub-commands, pipeline)

Week 4 – Variadic & Struct Sorting
  53      Variadic basics
  75-80   Variadic advanced (logger, table, string builder, events)
  54-60   Struct sorting (qsort, multi-key, stable, pointers, linked list)

Week 5 – Advanced Topics
  37-38   BST, qsort
  40      Preprocessor macros
  81-90   Data structures & algorithms (pool, ring, heap, graph...)

Week 6 – Capstone Projects (Mock Exams)
  91-97   Applied capstone exercises
  98      Mini Shell
  99      Key-Value Store
  100     Grand Capstone: DB Engine
```

---

## How to Compile

```bash
# Single file
gcc -Wall -Wextra -o program main.c

# Separate compilation + link
gcc -Wall -c mylib.c  -o mylib.o
gcc -Wall -c main.c   -o main.o
gcc mylib.o main.o    -o program

# With math library
gcc main.c -o program -lm

# With debug macro
gcc main.c -DDEBUG -o program_debug

# C11 features (_Generic etc.)
gcc -std=c11 -Wall main.c -o program
```

---

## Quick Tips for the Exam

| Tip | Detail |
|-----|--------|
| **Include guards** | Every `.h` file must have `#ifndef HEADER_H / #define HEADER_H / #endif` |
| **Pass structs by pointer** | `void f(Student *s)` not `void f(Student s)` for non-trivial structs |
| **NULL check after malloc** | `if (!ptr) { perror("malloc"); exit(1); }` |
| **Free everything** | Every `malloc` needs a `free`; free children before parents |
| **Pointer vs value** | `s->field` (pointer), `s.field` (value) |
| **String comparison** | `strcmp(a, b)` not `a == b` |
| **fopen error check** | `FILE *f = fopen(...); if (!f) { perror("fopen"); return; }` |
| **strtol vs atoi** | Prefer `strtol` with endptr for robust parsing |
| **va_end is mandatory** | Always call `va_end(args)` before returning from a variadic function |
| **va_copy for 2nd pass** | Use `va_copy(copy, args)` when you need to iterate the arg list twice |
