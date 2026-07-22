# Assignment 07 — Floyd's Algorithm for All-Pairs Shortest Paths

**Date:** 6/1/26

## Problem

Implement Floyd's Algorithm to find all-pairs shortest paths in a
weighted graph using an adjacency matrix representation.

## How it works

The graph is read straight into a distance matrix, `dist[i][j]` starts
out as the direct edge weight between `i` and `j` if one exists, or
"infinity" (a large stand-in value, `INF`) if there's no direct edge.
The diagonal is always 0, since the distance from any vertex to itself
is zero.

The algorithm then tries every vertex `k`, one at a time, as a possible
middle stop between every pair `(i, j)`. If routing through `k` (that is,
`i → k → j`) turns out shorter than the best route to `j` known so far,
`dist[i][j]` gets updated to that shorter total. By the time `k` has
cycled through all `V` vertices, every `dist[i][j]` reflects the true
shortest path between `i` and `j`, using any combination of intermediate
stops, not just direct edges or single stopovers.

This version only tracks distances, not the actual paths, that
extension (remembering *which* vertex to route through, and
reconstructing the path itself) is what the next assignment,
Floyd-Warshall with path reconstruction, adds on top of this same core
loop.

## Compile and run

```
g++ -o floyds_algorithm floyds_algorithm.cpp
./floyds_algorithm
```

## Sample run

```
Enter number of vertices: 4
Enter the adjacency matrix (4 x 4), use -1 for 'no direct edge', 0 only on the diagonal:
-1 3 -1 7
8 -1 2 -1
5 -1 -1 1
2 -1 -1 -1

All-pairs shortest distance matrix:

	0	1	2	3	
0	0	3	5	6	
1	5	0	2	3	
2	3	6	0	1	
3	2	5	7	0	
```

Read as: `dist[1][3] = 3` means the shortest way from vertex 1 to vertex
3 costs 3 total, even though there's no direct edge between them at all,
it actually routes through 2 (1 → 2 → 3, costing 2 + 1 = 3).
