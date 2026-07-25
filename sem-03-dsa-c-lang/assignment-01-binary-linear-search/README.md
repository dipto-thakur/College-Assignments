# Assignment 01 — Linear Search and Binary Search

**Date:** 11/11/2024

## Problem

Write a program to search for an element in a list using either linear
search or binary search, whichever the user chooses.

## How it works

**Linear search** is the brute-force approach, it just walks through the
array from the start, checking each element against the key one at a
time. Works on any array, sorted or not, but in the worst case has to
check every single element.

**Binary search** is much faster, but it only works correctly on a
**sorted** array. It repeatedly checks the middle element and, based on
whether the key is smaller or larger, throws away the half of the array
it can't possibly be in. That's why, when the user picks binary search
here, the program sorts the array first (with a simple bubble sort) and
shows the sorted version before searching, otherwise binary search could
silently give a wrong answer on unsorted input.

## Compile and run

```
gcc -o search search.c
./search
```

## Sample run

```
Enter number of elements: 6
Enter 6 elements: 34 12 89 45 2 67
Enter element to search: 45

Choose search method:
1. Linear Search
2. Binary Search
Enter choice: 1
45 found at index 3 (position 4).
```

```
Enter number of elements: 6
Enter 6 elements: 34 12 89 45 2 67
Enter element to search: 45

Choose search method:
1. Linear Search
2. Binary Search
Enter choice: 2
(array sorted for binary search): 2 12 34 45 67 89 
45 found at index 3 (position 4).
```
