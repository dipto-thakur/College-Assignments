# Graph Algorithms Lab — C++

Eight lab exercises covering basic number theory, graph traversal,
minimum spanning trees, and shortest path algorithms in C++. Each folder
is self contained: one `.cpp` file plus a README explaining the problem
and the approach.

## Assignments

| Folder | Topic |
|---|---|
| assignment-01-perfect-number | Checks whether a number is a perfect number |
| assignment-02-bfs-spanning-tree | Spanning tree via BFS, with a visited-node trace |
| assignment-03-dfs-spanning-tree | Spanning tree via DFS, with a visited-node trace |
| assignment-04-prims-algorithm | Prim's Algorithm (adjacency matrix, O(V²)) for MST |
| assignment-05-kruskals-algorithm | Kruskal's Algorithm using Disjoint Set Union for MST |
| assignment-06-dijkstra-shortest-path | Dijkstra's single-source shortest path (min-heap) |
| assignment-07-floyds-algorithm | All-pairs shortest paths, distance matrix only |
| assignment-08-floyd-warshall-path-reconstruction | Floyd-Warshall with a `next[]` matrix for full path reconstruction |

## Compiling and running

Every folder works the same way:

```
cd assignment-01-perfect-number
g++ -o perfect_number perfect_number.cpp
./perfect_number
```

Just swap in the folder and filename you're working with. Any standard
C++ compiler works, these don't use anything beyond the STL
(`vector`, `queue`, `priority_queue`, `algorithm`).

## How assignments 2-8 fit together

These build on each other more than they might look at first glance:

- **2 and 3** both build a spanning tree from an unweighted graph, just
  by walking it two different ways (level by level vs. as deep as
  possible first). Same input format, run them both on the same graph to
  see how the resulting trees differ.
- **4 and 5** both compute a Minimum Spanning Tree from a *weighted*
  graph, but from opposite ends: Prim's grows one tree outward vertex by
  vertex, Kruskal's looks at all edges at once and greedily picks the
  cheapest ones that don't form a cycle. They're set up with the same
  example graph in their READMEs so you can check both land on the same
  total weight (16, in that example) despite building it completely
  differently.
- **6, 7, and 8** are all shortest-path algorithms, but answering
  different questions: Dijkstra's (6) finds shortest paths from *one*
  source to everywhere else. Floyd's (7) and Floyd-Warshall (8) both find
  shortest paths between *every* pair of vertices at once, 8 is really
  just 7 with one extra matrix bolted on (`next[]`) so it can reconstruct
  the actual path, not just its length. 7 and 8 use the same example
  graph in their READMEs, so their distance matrices should come out
  identical.

## A note on two small issues in the original assignment sheet

- Assignment 3's title says DFS but the bracketed note next to it says
  "(BFS)", almost certainly a copy-paste leftover from assignment 2
  right above it. Built as DFS, since that's what the rest of the
  description and the whole point of the assignment says.
- Assignment 8's date reads 7/1/25, but given it's listed right after
  assignment 7's 6/1/26, that's very likely meant to be 7/1/26. Left a
  note about it in that folder's README rather than silently changing
  it.
