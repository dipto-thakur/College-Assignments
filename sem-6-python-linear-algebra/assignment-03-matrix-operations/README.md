# Assignment 03 — Matrix Operations (Addition, Subtraction, Multiplication, Division)

**Date:** 05/05/26

## Problem

Write a menu-driven program that takes two matrices, A and B, and
performs addition, subtraction, multiplication, and division.

## How it works

Both matrices are read in with the same number of rows and columns
(needed for addition/subtraction to make sense), then a menu lets any of
the four operations run repeatedly.

- **Addition** and **subtraction** are direct elementwise NumPy
  operations (`np.add`, `np.subtract`), so both matrices need matching
  dimensions.
- **Multiplication** uses `np.matmul`, but only after checking that A's
  column count matches B's row count, the standard requirement for
  matrix multiplication to be defined at all.
- **Division** isn't actually a standard matrix operation the way it is
  for numbers, there's no direct "A / B" for matrices. The closest
  meaningful equivalent is `A × inverse(B)`, treating multiplication by
  B's inverse as "dividing by B". That only works if B is square and
  actually has an inverse (non-zero determinant), both checked before
  attempting it.

## Run it

```
pip install numpy
python matrix_operations.py
```

## Sample run

Using `A = [[4, 2], [1, 3]]` and `B = [[2, 1], [1, 2]]`:

```
Enter number of rows: 2
Enter number of columns: 2

Enter elements of Matrix A
A[0][0] = 4
A[0][1] = 2
A[1][0] = 1
A[1][1] = 3

Enter elements of Matrix B
B[0][0] = 2
B[0][1] = 1
B[1][0] = 1
B[1][1] = 2

========== MENU ==========
1. Addition
2. Subtraction
3. Multiplication
4. Division
5. Exit
Enter your choice: 1

Addition =
[[6. 3.]
 [2. 5.]]
Enter your choice: 2

Subtraction =
[[2. 1.]
 [0. 1.]]
Enter your choice: 3

Multiplication =
[[10.  8.]
 [ 5.  7.]]
Enter your choice: 4

Division =
[[ 2.          0.        ]
 [-0.33333333  1.66666667]]
Enter your choice: 5

Program Ended
```

### A note on the "Division" result

This README's Division output (`[[2, 0], [-0.333, 1.667]]`) was verified
by actually running the program against the exact A and B shown above,
and it also checks out by hand: `A @ inv(B)` with `inv(B) =
[[0.667, -0.333], [-0.333, 0.667]]` does multiply out to this. The
original assignment sheet this was transcribed from showed a different
Division result (`[[2.333, -0.167], [-0.333, 1.667]]`) for the same A
and B, which doesn't match either a fresh run or a manual calculation,
so that looks like a transcription slip in the original rather than a
real program output. Fixed here rather than reproduced.
