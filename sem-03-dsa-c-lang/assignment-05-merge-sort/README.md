# Assignment 05 — Merge Sort

**Date:** 27/11/2024

## Problem

Write a program to implement Merge Sort.

## How it works

Merge sort is a classic divide-and-conquer algorithm, built from two
pieces:

1. **Divide (`mergeSort`)** — split the array in half, recursively, until
   each piece is down to a single element. A one-element list is
   trivially already sorted, that's the base case.
2. **Conquer (`merge`)** — combine two already-sorted halves back into
   one sorted whole, by repeatedly comparing the front of each half and
   taking whichever is smaller. Since both halves came in already
   sorted, this merge step only ever needs a single left-to-right pass
   over each, no backtracking.

The recursion handles splitting all the way down, and every `merge` call
on the way back up combines progressively bigger sorted chunks, until
the very last merge produces the fully sorted array.

Unlike bubble, insertion, or selection sort, merge sort guarantees
O(n log n) performance regardless of the input's starting order, the
tradeoff is that it needs extra memory for the temporary arrays used
during merging.

## Compile and run

```
gcc -o merge_sort merge_sort.c
./merge_sort
```

## Sample run

```
Enter number of elements: 7
Enter 7 elements: 38 27 43 3 9 82 10

Original array: 38 27 43 3 9 82 10 
Sorted array:   3 9 10 27 38 43 82 
```
