# Exercise 37 – Pointer to Struct: Linked Struct Chain

## Topic
Pointers + Structs

## Objective
Work with pointers to structs, struct self-reference, and building chains of structs on the heap.

## Instructions

1. Create `struct_chain.c`.

2. Define a `TreeNode` struct for a **binary tree**:
   ```c
   typedef struct TreeNode {
       int               value;
       struct TreeNode  *left;
       struct TreeNode  *right;
   } TreeNode;
   ```

3. Implement:
   - `TreeNode* tree_create_node(int value);` – allocates and returns a leaf node.
   - `TreeNode* tree_insert(TreeNode *root, int value);`
     Inserts into a **Binary Search Tree** (BST): values less than root go left, greater go right.
   - `void tree_print_inorder(const TreeNode *root);`
     Prints nodes in ascending order (left → root → right).
   - `int tree_search(const TreeNode *root, int value);`
     Returns 1 if found, 0 otherwise.
   - `void tree_free(TreeNode *root);`
     Recursively frees all nodes (post-order: free children before parent).

4. In `main`:
   - Insert: 5, 3, 7, 1, 4, 6, 8.
   - Print in-order.
   - Search for 4 (found) and 9 (not found).
   - Free.

## Expected Output
```
In-order: 1 3 4 5 6 7 8
Search 4: found
Search 9: not found
```

## Hints
- `tree_insert` returns the root — use: `root = tree_insert(root, val);`
- The recursive base case for `tree_insert`: if `root == NULL`, create and return a new node.
- In-order traversal: recurse left, visit, recurse right.
