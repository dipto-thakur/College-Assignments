# Assignment 02 — Matrix Multiplication

**Date:** 13/11/2024

## Problem

Write a program to perform matrix multiplication.

## How it works

Two matrices can only be multiplied if the number of columns in the
first matches the number of rows in the second, that's checked right up
front before asking for any elements, no point collecting input for a
multiplication that can't happen.

Each cell `result[i][j]` in the output is the dot product of row `i` from
the first matrix and column `j` from the second, multiply matching
elements together and sum them up. The triple nested loop is just that:
outer two loops walk over every cell of the result, the innermost loop
computes that one dot product.

## Compile and run

```
gcc -o matrix_multiplication matrix_multiplication.c
./matrix_multiplication
```

## Sample run

```
Enter rows and columns of first matrix: 2 3
Enter rows and columns of second matrix: 3 2
Enter elements of first matrix (2x3):
1 2 3
4 5 6
Enter elements of second matrix (3x2):
7 8
9 10
11 12

Resultant matrix (2x2):
58 64 
139 154 
```
