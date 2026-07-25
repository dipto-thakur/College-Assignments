# Assignment 07 — Heap Sort

**Date:** 04/12/2024

## Problem

Write a program to implement Heap Sort.

## How it works

Heap sort leans on the **max-heap** property, every parent node in the
(implicit, array-based) binary tree is greater than or equal to both its
children. For a node at index `i`, its children live at `2i + 1` and
`2i + 2`, no actual pointers needed, the array itself is the tree.

There are two phases:

1. **Build the heap.** Starting from the last non-leaf node and working
   backward to the root, `heapify()` fixes each subtree so it satisfies
   the max-heap property. Going backward matters, by the time `heapify`
   reaches any given node, everything below it is already a valid heap,
   so it only ever has to worry about fixing that one node relative to
   its two (already-valid) children.
2. **Repeatedly extract the max.** Once the whole array is a valid
   max-heap, the largest element is always sitting at the root
   (index 0). Swap it with the last element of the current heap, shrink
   the heap by one (that last position is now considered "sorted" and
   outside the heap), and `heapify` the root again to restore the
   max-heap property on what's left. Repeating this drains the heap from
   largest to smallest, building the sorted array from the back
   forward.

Heap sort runs in O(n log n) in every case (best, average, and worst),
and unlike merge sort, it sorts in place without needing extra memory
for temporary arrays.

## Compile and run

```
gcc -o heap_sort heap_sort.c
./heap_sort
```

## Sample run

```
Enter number of elements: 7
Enter 7 elements: 38 27 43 3 9 82 10

Original array: 38 27 43 3 9 82 10 
Sorted array:   3 9 10 27 38 43 82 
```
