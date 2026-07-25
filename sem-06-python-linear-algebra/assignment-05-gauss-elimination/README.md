# Assignment 05 — Gauss Elimination

**Date:** 12/05/26

## Problem

Use Gauss Elimination to solve:

```
4x1 + 3x2 - 5x3 = 2
-2x1 - 4x2 + 5x3 = 5
8x1 + 8x2 + 0x3 = -3
```

and verify the solution against NumPy's built-in solver.

## How it works

The three equations become one augmented matrix (coefficients plus the
right-hand side values as a fourth column). Gauss elimination then
works through it step by step, transforming it into row echelon form,
upper triangular, with 1s down the diagonal:

1. Scale row 1 so its first entry becomes 1 (the first pivot).
2. Subtract the right multiple of row 1 from rows 2 and 3, so the first
   column becomes zero everywhere below the pivot.
3. Scale row 2 so its second entry becomes 1 (the second pivot).
4. Subtract the right multiple of row 2 from row 3, zeroing out the
   second column below that pivot.
5. Scale row 3 so its third entry becomes 1 (the third pivot).

Every intermediate matrix gets printed along the way, so you can watch
the elimination happen step by step rather than just seeing the final
answer appear.

Once the matrix is in this triangular form, **back substitution** solves
it from the bottom up: the last row directly gives `x3` (since it only
has one unknown left), which then plugs into the second row to get
`x2`, and both plug into the first row to get `x1`.

Finally, the same system gets solved again with `np.linalg.solve()` as
an independent check that the manual elimination landed on the right
answer.

## Run it

```
pip install numpy
python gauss_elimination.py
```

## Sample run

```
Augmented Matrix =

[[ 4.  3. -5.  2.]
 [-2. -4.  5.  5.]
 [ 8.  8.  0. -3.]]

After R1 = R1 / 4

[[ 1.    0.75 -1.25  0.5 ]
 [-2.   -4.    5.    5.  ]
 [ 8.    8.    0.   -3.  ]]

After making first column zero

[[ 1.    0.75 -1.25  0.5 ]
 [ 0.   -2.5   2.5   6.  ]
 [ 0.    2.   10.   -7.  ]]

After making second pivot 1

[[ 1.    0.75 -1.25  0.5 ]
 [-0.    1.   -1.   -2.4 ]
 [ 0.    2.   10.   -7.  ]]

After making second column zero

[[ 1.    0.75 -1.25  0.5 ]
 [-0.    1.   -1.   -2.4 ]
 [ 0.    0.   12.   -2.2 ]]

After making third pivot 1

[[ 1.          0.75       -1.25        0.5       ]
 [-0.          1.         -1.         -2.4       ]
 [ 0.          0.          1.         -0.18333333]]

Solution using Gauss Elimination
x1 = 2.2083333333333335
x2 = -2.583333333333333
x3 = -0.18333333333333335

Solution using np.linalg.solve()
[ 2.20833333 -2.58333333 -0.18333333]
```

Both methods agree, which is the whole point of the verification step.

### A note on x1

The original assignment sheet this was transcribed from listed
`x1 = 2.0708333333333333`, but running the exact same code (and
independently checking with `np.linalg.solve()`) both give
`x1 = 2.2083333333333335` instead. That looks like a digit transposition
in the original write-up (`2.07...` vs `2.20...`) rather than a real
difference in output, corrected here since it's independently verifiable
by anyone re-running the program.
