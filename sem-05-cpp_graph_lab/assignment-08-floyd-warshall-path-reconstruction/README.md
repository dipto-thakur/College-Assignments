# Assignment 08 — Floyd-Warshall with Path Reconstruction

**Date:** 7/1/25 *(as written on the original sheet; given it's listed
right after the 6/1/26 assignment, this is almost certainly meant to be
7/1/26)*

## Problem

Demonstrate the Floyd-Warshall Algorithm with intermediate node storage.
Display the final distance matrix and the reconstructed paths.

## How it works

This builds directly on assignment 7's triple loop, same core idea:
for every pair `(i, j)`, check whether routing through some vertex `k`
beats the current best known distance. The one addition here is a second
matrix, `next[i][j]`, which is what "intermediate node storage" in the
problem statement is referring to.

`next[i][j]` doesn't store *every* intermediate vertex on the path from
`i` to `j`, just the very next vertex to step to after leaving `i` on
the current best known route to `j`. It starts out as simply `j` itself
wherever a direct edge `i -> j` exists (since with no better route
known yet, the "next step" from `i` is just `j`). Then, every time the
main loop finds a shorter route to `j` by going through `k`, it means
the best first step from `i` has changed to whatever the best first step
from `i` to `k` was, so `next[i][j] = next[i][k]`.

To rebuild an actual path afterward, `reconstructPath()` just follows
that trail: start at `u`, look up `next[u][v]` to get the next vertex,
jump there, and repeat until it lands on `v`. Every hop along the way
gets collected into the final path.

## Compile and run

```
g++ -o floyd_warshall_paths floyd_warshall_paths.cpp
./floyd_warshall_paths
```

## Sample run

Same graph as assignment 7, so the distance matrix should come out
identical, this time with full paths printed alongside it:

```
Enter number of vertices: 4
Enter the adjacency matrix (4 x 4), use -1 for 'no direct edge', 0 only on the diagonal:
-1 3 -1 7
8 -1 2 -1
5 -1 -1 1
2 -1 -1 -1

Final all-pairs shortest distance matrix:

	0	1	2	3	
0	0	3	5	6	
1	5	0	2	3	
2	3	6	0	1	
3	2	5	7	0	

Reconstructed shortest paths:
0 -> 1 : 0 -> 1  (distance 3)
0 -> 2 : 0 -> 1 -> 2  (distance 5)
0 -> 3 : 0 -> 1 -> 2 -> 3  (distance 6)
1 -> 0 : 1 -> 2 -> 3 -> 0  (distance 5)
1 -> 2 : 1 -> 2  (distance 2)
1 -> 3 : 1 -> 2 -> 3  (distance 3)
2 -> 0 : 2 -> 3 -> 0  (distance 3)
2 -> 1 : 2 -> 3 -> 0 -> 1  (distance 6)
2 -> 3 : 2 -> 3  (distance 1)
3 -> 0 : 3 -> 0  (distance 2)
3 -> 1 : 3 -> 0 -> 1  (distance 5)
3 -> 2 : 3 -> 0 -> 1 -> 2  (distance 7)
```

The distance matrix here matches assignment 7's exactly, which is a
useful sanity check, both programs are computing the same thing, this
one just also remembers enough to say *how* you get from one vertex to
another, not only how far it is.
