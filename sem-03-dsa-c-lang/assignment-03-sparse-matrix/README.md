# Assignment 03 — Sparse Matrix Implementation

**Date:** 18/11/2024

## Problem

Write a program to implement a sparse matrix.

## What a sparse matrix is

A sparse matrix is one where most of the elements are zero. Storing the
whole grid, zeros included, wastes memory once a matrix gets large, so
instead it's common to store only the non-zero values, along with their
row and column position. That's the **triplet representation**: a list
of `(row, column, value)` entries, one per non-zero cell.

## How it works

The program reads a full matrix from the user first (that's just the
easiest way to provide test input), then scans it row by row and column
by column, and for every non-zero cell found, records a triplet. The
result is printed as a simple table, that table alone is the sparse
representation, the original full grid isn't needed once it exists.

It also demonstrates **fast transpose**, computing the transpose of the
sparse matrix directly from the triplet list, without ever rebuilding
the full grid. The trick is figuring out, ahead of time, exactly where
each triplet needs to land in the transposed list (grouped by column of
the original matrix, since that becomes the row of the transposed one)
using a running count per column. That one-pass placement is what makes
it "fast," a naive transpose would instead scan the whole triplet list
once for every column, which is much slower on a large sparse matrix.

## Compile and run

```
gcc -o sparse_matrix sparse_matrix.c
./sparse_matrix
```

## Sample run

```
Enter number of rows and columns: 4 5
Enter the matrix elements (4 x 5), use 0 for empty cells:
0 0 3 0 4
0 0 5 7 0
0 0 0 0 0
0 2 6 0 0

Original matrix has 20 cells, 6 are non-zero (70.0% sparse).

Sparse matrix representation (row, column, value):
Rows: 4	Columns: 5	Non-zero terms: 6
0	2	3
0	4	4
1	2	5
1	3	7
3	1	2
3	2	6

Transposed sparse matrix (row, column, value):
Rows: 5	Columns: 4	Non-zero terms: 6
1	3	2
2	0	3
2	1	5
2	3	6
3	1	7
4	0	4
```
