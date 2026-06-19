# Exercise 67 – File Handling: Serialise and Deserialise Linked List

## Topic
File I/O + Linked Lists + Structs + Binary I/O

## Objective
Persist a dynamically allocated linked list to a binary file and restore it completely — including all nodes and their connections.

---

## Instructions

1. Create `list_serialise.c`.

2. Define:
   ```c
   typedef struct Node {
       int          id;
       char         label[32];
       double       weight;
       struct Node *next;
   } Node;
   ```

3. Implement list utilities:
   - `Node* node_create(int id, const char *label, double weight);`
   - `Node* list_append(Node *head, Node *node);`
   - `void  list_print(const Node *head);`
   - `void  list_free(Node *head);`

4. **Serialise** (write to file):
   ```c
   int list_save(const char *filename, const Node *head);
   ```
   - Binary write mode (`"wb"`).
   - First: write the **node count** as a single `int`.
   - Then: for each node, write only the **data fields** (`id`, `label`, `weight`) — **not** the `next` pointer (it's meaningless when reloaded).
   - Return 0 on success.

5. **Deserialise** (read from file):
   ```c
   Node* list_load(const char *filename);
   ```
   - Binary read mode (`"rb"`).
   - Read the count.
   - Allocate and link `count` new nodes from the file data.
   - Return the head of the reconstructed list.

6. In `main`:
   - Build a list of 5 nodes.
   - Print it.
   - Save to `list.bin`.
   - Free the list.
   - Load from `list.bin`.
   - Print the reloaded list — must match the original.
   - Print the file size.

---

## Expected Output
```
Original list:
1 "Alpha"  w=1.10 -> 2 "Beta"   w=2.20 -> 3 "Gamma" w=3.30
-> 4 "Delta" w=4.40 -> 5 "Epsilon" w=5.50 -> NULL

Saved to list.bin (file size: 133 bytes)
Freed original list.

Loaded from list.bin:
1 "Alpha"  w=1.10 -> 2 "Beta"   w=2.20 -> 3 "Gamma" w=3.30
-> 4 "Delta" w=4.40 -> 5 "Epsilon" w=5.50 -> NULL
```

---

## Hints
- Write each data-only struct field-by-field or use a packed representation (without the pointer): `fwrite(&node->id, sizeof(int), 1, fp)` etc., or define a separate `NodeData` struct without the pointer.
- Never write a raw pointer to a file — the address is invalid in another run.
- After `list_load`, the list is fully heap-allocated; call `list_free` when done.
- The file size = `sizeof(int)` + `count * (sizeof(int) + 32 + sizeof(double))`.
