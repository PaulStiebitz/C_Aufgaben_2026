# Exercise 50 – Capstone: Mini In-Memory Database

## Topic
All Topics Combined

## Objective
Combine everything you've learned — structs, dynamic memory, linked lists, sorting, file I/O, enums, string operations — in one cohesive application.

## Instructions

Build a simple command-line **product inventory** system stored in a doubly linked list.

### Data Model
```c
typedef enum { CATEGORY_FOOD, CATEGORY_ELECTRONICS, CATEGORY_CLOTHING, CATEGORY_OTHER } Category;

typedef struct Product {
    int             id;
    char            name[60];
    Category        category;
    float           price;
    int             stock;
    struct Product *next;
    struct Product *prev;
} Product;
```

### Required Operations (implement all as functions)

| Function | Description |
|----------|-------------|
| `product_add` | Insert maintaining sorted order by `id` |
| `product_remove` | Remove by `id` |
| `product_find_by_id` | Returns pointer or NULL |
| `product_find_by_name` | Case-insensitive partial match |
| `product_print` | Print one product (all fields) |
| `product_print_all` | Print whole inventory |
| `product_sort_by_price` | Re-sort the DList by price ascending |
| `product_filter_by_category` | Print only products of given category |
| `product_save_to_file` | Write all products to `inventory.txt` |
| `product_load_from_file` | Load products from `inventory.txt` |
| `product_total_value` | Return `sum(price * stock)` |

### Main Program
Build an **interactive menu** with these options:
```
1) Add product
2) Remove product
3) Find by ID
4) Find by name
5) Print all
6) Filter by category
7) Sort by price
8) Save to file
9) Load from file
0) Quit
```

### Example Session
```
=== Product Inventory ===
> 1
ID: 101  Name: Laptop  Category (0=Food,1=Elec,2=Clothing,3=Other): 1
Price: 999.99  Stock: 5
Added: [101] Laptop  ELECTRONICS  €999.99  (5 in stock)

> 5
[101] Laptop       ELECTRONICS  €999.99   qty:5
[102] T-Shirt      CLOTHING     €19.99    qty:20
[103] Apple Juice  FOOD         €1.49     qty:100

> 7 (sort by price)
[103] Apple Juice  FOOD         €1.49     qty:100
[102] T-Shirt      CLOTHING     €19.99    qty:20
[101] Laptop       ELECTRONICS  €999.99   qty:5

Total inventory value: €5419.55
```

## Hints
- Split into multiple `.c`/`.h` files as a library if you have time.
- For case-insensitive search, convert both strings to lowercase before comparing.
- `product_sort_by_price` can detach all nodes and reinsert them in sorted order.
- This exercise intentionally covers the full exam topic range — treat it as a mock exam.

## Checklist
- [ ] All 11 functions implemented
- [ ] Interactive menu loop with input validation
- [ ] File save/load round-trip works correctly
- [ ] No memory leaks (every `malloc` has a matching `free`)
- [ ] Compiles cleanly with `gcc -Wall -Wextra`
