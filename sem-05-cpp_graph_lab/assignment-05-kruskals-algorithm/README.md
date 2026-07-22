# Assignment 05 — Kruskal's Algorithm Using Disjoint Set Union

**Date:** 17/12/25

## Problem

Construct Kruskal's Algorithm using disjoint set union in C++. Identify
the cycle prevention strategy and display the final edge set of the MST.

## How it works

Kruskal's algorithm works completely differently from Prim's, instead of
growing outward from one vertex, it looks at *all* the edges up front,
sorted from cheapest to most expensive, and greedily takes each one as
long as it doesn't create a cycle.

### Cycle prevention: Disjoint Set Union

The question this program has to answer constantly is: "are these two
vertices already connected through edges I've already picked?" Walking
the tree to check that every time would be slow. That's exactly what a
Disjoint Set Union (DSU / Union-Find) structure is built for:

- Every vertex starts in its own separate set.
- `find(x)` walks up to the "representative" of whatever set `x`
  currently belongs to, with **path compression**, every node it passes
  along the way gets pointed straight at that representative, so future
  calls are faster.
- `unite(a, b)` merges two sets together, using **union by rank** to
  always attach the smaller tree under the bigger one, which keeps the
  whole structure shallow instead of turning into a long chain.

For each edge `(u, v)` in sorted order: if `find(u) == find(v)`, `u` and
`v` are already connected through some earlier edge, so adding this one
would close a cycle, it gets skipped. Otherwise, the edge is safe to add,
and `unite(u, v)` merges their two sets into one.

## Compile and run

```
g++ -o kruskals_algorithm kruskals_algorithm.cpp
./kruskals_algorithm
```

## Sample run

Using the same weighted graph as the Prim's assignment, so you can
compare, both algorithms should land on the same total weight even
though they build the tree in a completely different order:

```
Enter number of vertices: 5
Enter number of edges: 7
Enter each edge as: u v weight  (0-indexed vertices)
0 1 2
0 3 6
1 2 3
1 3 8
1 4 5
2 4 7
3 4 9

Processing edges in increasing order of weight:
0 -- 1 (weight 2)  -> added to MST
1 -- 2 (weight 3)  -> added to MST
1 -- 4 (weight 5)  -> added to MST
0 -- 3 (weight 6)  -> added to MST
2 -- 4 (weight 7)  -> skipped, would form a cycle
1 -- 3 (weight 8)  -> skipped, would form a cycle
3 -- 4 (weight 9)  -> skipped, would form a cycle

Final MST edge set:
Edge 	Weight
0 -- 1	2
1 -- 2	3
1 -- 4	5
0 -- 3	6

Total weight of MST: 16
```
