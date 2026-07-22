# Assignment 02 — Spanning Tree Using BFS

**Date:** 17/11/25

## Problem

Write a C++ program to generate a spanning tree using Breadth-First
Search. Trace and display the visited nodes.

## How it works

The graph is stored as an adjacency list, built from user-entered edges,
and treated as undirected (each edge gets added both ways).

BFS starts at a chosen source, marks it visited, and pushes it into a
queue. From there it keeps popping a node, printing it (that's the trace
of visited nodes), and looking at its neighbors. Any neighbor that hasn't
been visited yet gets marked visited, queued up, and, importantly, the
edge that led to it gets recorded as part of the spanning tree.

That last part is really the whole idea behind "BFS gives you a spanning
tree for free": every node except the source gets discovered through
exactly one edge, and that specific set of discovery edges, taken
together, forms a tree that touches every reachable node with no cycles.

If the graph isn't fully connected from the chosen source, some nodes
never get visited, the program flags that at the end rather than
pretending a full spanning tree was built.

## Compile and run

```
g++ -o bfs_spanning_tree bfs_spanning_tree.cpp
./bfs_spanning_tree
```

## Sample run

```
Enter number of vertices: 6
Enter number of edges: 6
Enter each edge as: u v  (0-indexed vertices)
0 1
0 2
1 3
2 4
3 5
4 5
Enter the starting vertex for BFS: 0

BFS traversal order (nodes visited): 0 1 2 3 4 5

Spanning tree edges (in the order they were added):
0 -- 1
0 -- 2
1 -- 3
2 -- 4
3 -- 5
```

Note that the edge 4 -- 5 exists in the original graph but doesn't show
up in the spanning tree, node 5 was already reached via 3 -- 5 by the
time BFS got around to checking 4's neighbors. That's expected, a
spanning tree over 6 nodes only ever needs 5 edges.
