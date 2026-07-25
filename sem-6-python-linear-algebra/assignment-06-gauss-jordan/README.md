# Assignment 06 — Gaussian Elimination and Gauss-Jordan Method

**Date:** 30/05/26

## Problem

Solve the following system using both Gaussian elimination and the
Gauss-Jordan method, and determine whether the system is consistent or
inconsistent:

```
x + y + z = 6
2x + 3y + z = 10
x + 2y + 2z = 9
```

## How it works

Both methods start from the same augmented matrix, but stop at
different points.

**Gaussian elimination** only eliminates entries *below* the diagonal,
turning the matrix into upper triangular (row echelon) form:
- Subtract multiples of row 1 from rows 2 and 3 to zero out the first
  column below the top.
- Subtract a multiple of row 2 from row 3 to zero out the second column
  below that.

From there, **back substitution** solves bottom-up: the last row gives
`z` directly, that plugs into the second row to get `y`, and both plug
into the first row to get `x`.

**Gauss-Jordan** goes a step further than plain Gaussian elimination, it
continues eliminating *above* the diagonal too (via `.rref()`, Reduced
Row Echelon Form), until the coefficient side becomes the identity
matrix. At that point, the answer for each variable can just be read
straight off the last column, no back substitution needed.

**Consistency check:** a system is inconsistent if its RREF has any row
that's entirely zero on the coefficient side but non-zero on the
right-hand side, that would represent the equation `0 = <something
nonzero>`, which is impossible to satisfy. Here, no such row appears, so
the system is consistent, meaning it has a genuine solution.

### What changed from the original

The version of this code in the original assignment sheet had the same
missing-indentation problem as assignment 4 (every `if`/`for` block
unindented), which wouldn't run in real Python. Restored here with
correct indentation, no logic changes otherwise.

The original sheet's *printed output* also showed `x = 1/2`, but running
this exact code gives `x = 3` (double-checked by hand: `3 + 0.5 + 2.5 =
6`, `2(3) + 3(0.5) + 2.5 = 10`, `3 + 2(0.5) + 2(2.5) = 9`, all three
check out against the original equations). `x = 1/2` looks like it was
accidentally copied from `y`'s value in the original write-up rather
than being a real difference in program output, corrected here.

## Run it

```
pip install sympy
python gauss_jordan.py
```

## Sample run

```
Original Augmented Matrix =

Matrix([[1, 1, 1, 6], [2, 3, 1, 10], [1, 2, 2, 9]])

After First Elimination =

Matrix([[1, 1, 1, 6], [0, 1, -1, -2], [0, 1, 1, 3]])

After Second Elimination =

Matrix([[1, 1, 1, 6], [0, 1, -1, -2], [0, 0, 2, 5]])

Solution using Gaussian Elimination
x = 3
y = 1/2
z = 5/2

Reduced Row Echelon Form =

Matrix([[1, 0, 0, 3], [0, 1, 0, 1/2], [0, 0, 1, 5/2]])

System is Consistent

Solution using Gauss-Jordan Method
x = 3
y = 1/2
z = 5/2
```
