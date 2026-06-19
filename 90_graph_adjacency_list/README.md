# Exercise 90 – Graph as Adjacency List

## Topic
Structs + Linked Lists + Pointers + Algorithms

## Objective
Represent an undirected weighted graph using an adjacency list (array of linked lists) and implement BFS and DFS traversal.

---

## Instructions

1. Create `graph.c`.

2. Define:
   ```c
   #define MAX_VERTICES 10

   typedef struct Edge {
       int          dest;
       int          weight;
       struct Edge *next;
   } Edge;

   typedef struct {
       int   vertex_count;
       Edge *adj[MAX_VERTICES];  /* adj[i] = head of linked list of edges from i */
       char  labels[MAX_VERTICES][20];
   } Graph;
   ```

3. Implement:
   ```c
   void graph_init(Graph *g, int vertex_count, char labels[][20]);
   void graph_add_edge(Graph *g, int src, int dst, int weight); /* undirected */
   void graph_print(const Graph *g);   /* print adjacency list */
   void graph_free(Graph *g);

   void graph_bfs(const Graph *g, int start); /* Breadth-First Search */
   void graph_dfs(const Graph *g, int start); /* Depth-First Search (recursive) */

   int  graph_has_path(const Graph *g, int src, int dst); /* 1 if reachable */
   ```

4. `graph_bfs`: use a simple integer queue (array-based).
   `graph_dfs`: use a `visited[MAX_VERTICES]` array to avoid revisiting.

5. In `main`:
   - Create a graph with 6 vertices: A B C D E F.
   - Add edges: A-B(4), A-C(2), B-D(5), C-D(1), C-E(7), D-F(3), E-F(6).
   - Print adjacency list.
   - BFS from A.
   - DFS from A.
   - Check: path A→F (yes), path B→E (yes), path isolated vertex.

---

## Expected Output
```
Adjacency list:
A: B(4) C(2)
B: A(4) D(5)
C: A(2) D(1) E(7)
D: B(5) C(1) F(3)
E: C(7) F(6)
F: D(3) E(6)

BFS from A: A B C D E F
DFS from A: A B D C E F (or similar valid DFS order)

Path A->F: YES
Path B->E: YES
```

---

## Hints
- BFS queue: `int queue[MAX_VERTICES]; int front=0, back=0;` — push with `queue[back++]`, pop with `queue[front++]`.
- DFS: `void dfs_helper(const Graph *g, int v, int *visited)` is the recursive helper.
- `graph_add_edge` adds an `Edge` node to both `adj[src]` and `adj[dst]` (undirected).
- For `graph_has_path`, run BFS/DFS and check if `dst` ends up in the visited set.
