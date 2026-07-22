# Assignment 01 — Perfect Number Checker

**Date:** 11/11/25

## Problem

Write a C++ program to check whether an entered number is a perfect
number or not.

## What a perfect number is

A number is perfect if it equals the sum of its own proper divisors
(every divisor except the number itself). 6 is the smallest example:
its divisors are 1, 2, and 3, and 1 + 2 + 3 = 6. The next one is 28
(1 + 2 + 4 + 7 + 14 = 28).

## How it works

The function loops from 1 up to `num / 2` (nothing bigger than half the
number, besides the number itself, can ever divide it evenly), adding
every divisor it finds along the way. At the end it just compares that
running sum against the original number.

## Compile and run

```
g++ -o perfect_number perfect_number.cpp
./perfect_number
```

## Sample runs

```
Enter a number: 28
28 is a perfect number.

Enter a number: 15
15 is not a perfect number.
```
