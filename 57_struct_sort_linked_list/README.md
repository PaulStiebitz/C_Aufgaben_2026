# Exercise 57 – Sorting a Linked List of Structs

## Topic
Linked Lists + Structs + Sorting

## Objective
Sort a singly linked list of structs **in-place** using insertion sort and merge sort, without converting to an array.

---

## Instructions

1. Create `list_sort_structs.c`.

2. Define:
   ```c
   typedef struct Product {
       int          id;
       char         name[40];
       float        price;
       int          stock;
       struct Product *next;
   } Product;
   ```

3. Implement basic list utilities:
   - `Product* product_new(int id, const char *name, float price, int stock);`
   - `Product* list_push_back(Product *head, Product *node);`
   - `void list_print(const Product *head);`
   - `void list_free(Product *head);`

4. **Sort A – Insertion Sort**:
   ```c
   Product* list_insertion_sort(Product *head, int (*cmp)(const Product*, const Product*));
   ```
   Builds a new sorted list by removing nodes one at a time from the source list and inserting them in the correct position in the result list.

5. **Sort B – Merge Sort** (more efficient, O(n log n)):
   ```c
   Product* list_merge_sort(Product *head, int (*cmp)(const Product*, const Product*));
   ```
   Split the list in half (slow/fast pointer), recursively sort both halves, merge.

6. Implement comparators:
   - `int cmp_by_price_asc(const Product *a, const Product *b);`
   - `int cmp_by_name_asc(const Product *a, const Product *b);`
   - `int cmp_by_stock_desc(const Product *a, const Product *b);`

7. In `main`:
   - Build a list of 6 products.
   - Sort by price (insertion sort), print.
   - Sort by name (merge sort), print.
   - Sort by stock descending (merge sort), print.

---

## Expected Output (example)
```
--- Original ---
[1] Widget     €5.99  stock:10
[2] Gadget    €12.49  stock: 3
[3] Doohickey  €2.99  stock:25
[4] Thingamajig €8.75 stock: 1
[5] Gizmo      €4.25  stock:15
[6] Knickknack €9.99  stock: 7

--- By Price ASC (insertion sort) ---
[3] Doohickey  €2.99  stock:25
[5] Gizmo      €4.25  stock:15
...

--- By Name ASC (merge sort) ---
[3] Doohickey  €2.99  stock:25
[2] Gadget    €12.49  stock: 3
...

--- By Stock DESC ---
[3] Doohickey  €2.99  stock:25
[5] Gizmo      €4.25  stock:15
...
```

---

## Hints
- For list merge sort, use the slow/fast pointer trick to find the midpoint: slow advances 1 step, fast advances 2 steps; when fast reaches the end, slow is at the midpoint.
- The function pointer `int (*cmp)(const Product*, const Product*)` lets you pass the comparator to the sort function.
- Merge sort on a linked list does **not** need extra memory (unlike array merge sort).
