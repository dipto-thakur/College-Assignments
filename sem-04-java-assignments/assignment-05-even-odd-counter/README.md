# Assignment 05 — Even or Odd Counter in a Range

**Date:** 02.06.2025

## Problem

Take two numbers representing a range and count how many even numbers and
how many odd numbers fall within it, inclusive of both endpoints.

## How it works

If the user happens to type the larger number first, the two get swapped
so the loop always counts from low to high. From there it's just a
straight loop through the range, checking `% 2` on each number and
tallying it into one of two counters.

### What changed from the original

Nothing structural, this one was already clean. Tightened up spacing and
comments slightly for readability.

## Run it

```
javac EvenOddCounter.java
java EvenOddCounter
```

## Sample run

```
Enter the starting number of the range: 1
Enter the ending number of the range: 10

Counting numbers from 1 to 10:
Number of even numbers: 5
Number of odd numbers: 5

Enter the starting number of the range: 4
Enter the ending number of the range: 4

Counting numbers from 4 to 4:
Number of even numbers: 1
Number of odd numbers: 0

Enter the starting number of the range: 7
Enter the ending number of the range: 7

Counting numbers from 7 to 7:
Number of even numbers: 0
Number of odd numbers: 1
```