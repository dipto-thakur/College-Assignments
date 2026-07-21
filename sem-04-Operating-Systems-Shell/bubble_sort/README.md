# Assignment 06 — Bubble Sort on an Array

**Date:** 07/07/25

## Problem

Write a shell script that takes a set of numbers into an array and sorts
them using the Bubble Sort method.

## How it works

Standard bubble sort, nothing fancy. The outer loop walks through each
index `i`, the inner loop compares `arr[i]` against every element after it,
and whenever a later element is smaller, the two get swapped. By the time
the outer loop finishes, the smallest values have "bubbled" to the front.

Note: this one needs bash, not the plain POSIX `sh`, since it relies on
bash-style arrays (`arr[$i]`). Running it with `sh script.sh` on some
systems will throw errors, use `bash script.sh` instead.

## Run it

```
bash bubble_sort.sh
```

Enter how many numbers you want to sort, then enter them one per line.

## Sample run

```
$ bash bubble_sort.sh
Enter how many numbers to be sorted : 5
Enter numbers :
4 8 6 7 2

The entered numbers are :
4 8 6 7 2

Numbers after sorting :
2 4 6 7 8
```