# Assignment 03 — Spanning Tree Using DFS

**Date:** 3/12/25

## Problem

Write a C++ program to generate a spanning tree using Depth-First
Search. Trace and display the visited nodes.

(the original lab sheet says "BFS" in the parentheses for this one, that
looks like a copy-paste leftover from assignment 2, the title and the
rest of the description both clearly say DFS, so that's what's built
here)

## How it works

Same adjacency list setup as the BFS version, but the traversal itself is
recursive instead of queue-based. `dfsVisit()` marks the current node
visited, prints it, then immediately dives into the first unvisited
neighbor it finds, going as deep as possible before backing out and
trying the next branch.

Just like with BFS, every edge that leads to a node's *first* visit gets
recorded as a spanning tree edge. The difference in the tree shape
between BFS and DFS comes entirely from the order nodes get discovered
in, BFS spreads outward level by level, DFS commits to one path and only
backtracks when it hits a dead end.

## Compile and run

```
g++ -o dfs_spanning_tree dfs_spanning_tree.cpp
./dfs_spanning_tree
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
Enter the starting vertex for DFS: 0

DFS traversal order (nodes visited): 0 1 3 5 4 2

Spanning tree edges (in the order they were added):
0 -- 1
1 -- 3
3 -- 5
5 -- 4
4 -- 2
```

Notice the tree looks different from the BFS one on the same graph, DFS
followed the path 0 → 1 → 3 → 5 → 4 all the way down before it ever got
back to visiting 2 through the 0 -- 2 edge.
