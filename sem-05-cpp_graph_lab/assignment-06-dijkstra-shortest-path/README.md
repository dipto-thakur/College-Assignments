# Assignment 06 — Dijkstra's Single-Source Shortest Path

**Date:** 24/12/25

## Problem

Write a C++ program to compute the shortest paths from a single source
to every other vertex, using Dijkstra's Algorithm.

## How it works

Dijkstra's is greedy: it always finalizes the closest not-yet-finalized
vertex next, on the reasoning that once a vertex has the smallest
tentative distance in the whole frontier, nothing can ever find a
cheaper way to reach it later (this only holds because all the edge
weights here are non-negative, Dijkstra's breaks down if negative
weights are allowed).

A min-heap (`priority_queue` with `greater<>`) keeps track of which
vertex to expand next, always popping the one with the smallest known
distance. For each neighbor of the vertex being expanded, the program
checks if going through the current vertex beats whatever distance was
known before, that's the "relaxation" step, and if so, updates the
distance and pushes the neighbor back into the heap.

One detail worth pointing out: a vertex can end up in the heap more than
once, if a shorter path to it gets discovered after it was already
queued once. The check `if (d > dist[u]) continue;` at the top of the
loop is what skips over these stale, outdated heap entries instead of
processing them again.

The graph here is read in as **directed**, since that's the more general
case, if you want an undirected graph instead, there's a commented-out
line in the edge-reading loop that adds the reverse edge too.

## Compile and run

```
g++ -o dijkstra dijkstra.cpp
./dijkstra
```

## Sample run

```
Enter number of vertices: 5
Enter number of edges: 6
Enter each edge as: u v weight  (0-indexed vertices, directed)
0 1 4
0 2 1
2 1 2
1 3 1
2 3 5
3 4 3
Enter the source vertex: 0

Shortest distances from source vertex 0:
Vertex 	Distance
0	0
1	3
2	1
3	4
4	7
```

Notice vertex 1's shortest distance is 3, not the direct edge weight of
4, going 0 → 2 → 1 (1 + 2 = 3) beats the direct 0 → 1 edge. That's
Dijkstra's actually finding the genuinely shortest route rather than just
taking the first path it sees.
