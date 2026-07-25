# Assignment 06 — Quick Sort

**Date:** 02/12/2024

## Problem

Write a program to implement Quick Sort.

## How it works

Quick sort is also divide-and-conquer, like merge sort, but it splits the
work differently: instead of splitting the array down the middle and
merging afterward, it picks a **pivot** element and rearranges
(partitions) the array so everything smaller than the pivot ends up to
its left and everything larger ends up to its right. The pivot itself is
now sitting exactly where it belongs in the final sorted array.

This implementation uses the **Lomuto partition scheme**, which always
picks the last element of the current range as the pivot. It walks
through the range with index `j`, and keeps a second index `i` marking
the boundary of everything confirmed to be `<= pivot` so far. Whenever
`arr[j]` turns out to belong on the small side, it gets swapped into
place just past that boundary. After the scan, one last swap puts the
pivot itself into its correct final position, right between the small
and large sides.

Once partitioned, `quickSort` calls itself on the left side and the
right side independently, neither side needs to know anything about the
other anymore, since the pivot placement already guarantees everything
on the left is smaller than everything on the right.

Average case is O(n log n), though worst case (already sorted input,
with this particular pivot choice) degrades to O(n²), that's a known
tradeoff of the simple last-element pivot strategy used here.

## Compile and run

```
gcc -o quick_sort quick_sort.c
./quick_sort
```

## Sample run

```
Enter number of elements: 7
Enter 7 elements: 38 27 43 3 9 82 10

Original array: 38 27 43 3 9 82 10 
Sorted array:   3 9 10 27 38 43 82 
```
