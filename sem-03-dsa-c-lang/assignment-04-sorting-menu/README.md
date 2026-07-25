# Assignment 04 — Sorting: Insertion, Bubble, or Selection

**Date:** 20/11/2024

## Problem

Write a program to sort a list of elements. Give the user the option to
sort using insertion sort, bubble sort, or selection sort.

## How the three compare

- **Bubble sort** repeatedly walks through the array, swapping any pair
  of adjacent elements that are out of order. After each full pass, the
  largest remaining unsorted element has "bubbled up" to its correct
  spot at the end.
- **Insertion sort** builds up a sorted section at the front of the
  array one element at a time. For each new element, it shifts every
  larger element in the sorted section one step to the right to make
  room, then drops the new element into the gap. It's the same motion
  you'd use sorting playing cards in your hand.
- **Selection sort** does the opposite of insertion sort's shifting, it
  scans the unsorted portion for the smallest value and swaps it
  directly into place at the front, one swap per pass, no shifting.

All three run in O(n²) in the worst case, the difference between them is
mostly in how many swaps vs. comparisons they do, not big-picture speed.

The program reads the list once, then asks which algorithm to sort it
with and calls the matching function.

## Compile and run

```
gcc -o sorting_menu sorting_menu.c
./sorting_menu
```

## Sample run

```
Enter number of elements: 6
Enter 6 elements: 45 12 89 3 67 23

Choose a sorting method:
1. Insertion Sort
2. Bubble Sort
3. Selection Sort
Enter choice: 2

Sorted using Bubble Sort: 3 12 23 45 67 89 
```
