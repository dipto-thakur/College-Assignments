# Assignment 04 — Prim's Algorithm

**Date:** 9/12/25

## Problem

Design and implement Prim's Algorithm in C++. Display the edges included
in the Minimum Spanning Tree and their weights.

## How it works

The graph is read in as a weighted adjacency matrix (0 meaning "no
edge"). Prim's algorithm grows the MST one vertex at a time, starting
from vertex 0:

- `key[i]` tracks the cheapest edge weight found so far connecting
  vertex `i` to the tree being built, and `parent[i]` remembers which
  tree vertex that cheapest edge comes from.
- At each step, the algorithm picks the vertex outside the tree with the
  smallest `key` value, that's the cheapest way to extend the tree right
  now, and adds it in.
- Once a vertex joins the tree, its neighbors' `key` values get "relaxed",
  if going through this newly added vertex is cheaper than whatever
  route was known before, `key` and `parent` get updated.

After V-1 vertices have joined, `parent[]` and `key[]` together describe
every edge in the MST, which is what gets printed at the end along with
the running total weight.

This is the straightforward O(V²) version (no priority queue), which
fits fine for small dense graphs typically used in a lab exercise.

## Compile and run

```
g++ -o prims_algorithm prims_algorithm.cpp
./prims_algorithm
```

## Sample run

Using this weighted graph (5 vertices):

```
    0 --2-- 1
    |      /|\
    6     3 8 5
    |    /  |  \
    3---+   4---+
       (1-2=3, 1-3=8, 1-4=5, 2-4=7, 3-4=9)
```

```
Enter number of vertices: 5
Enter the adjacency matrix (5 x 5), use 0 for 'no edge':
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0

Edges included in the Minimum Spanning Tree:
Edge 	Weight
0 -- 1	2
1 -- 2	3
0 -- 3	6
1 -- 4	5

Total weight of MST: 16
```
