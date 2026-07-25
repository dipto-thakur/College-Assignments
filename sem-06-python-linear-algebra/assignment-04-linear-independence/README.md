# Assignment 04 — Linear Independence and Basis of a Subspace

**Date:** 08/05/26

## Problem

Consider the vectors `v1 = (1,1,0)`, `v2 = (0,1,1)`, and `v3 = (1,2,1)`
in R³. Check whether they're linearly independent, find a basis for the
subspace they span, and determine its dimension.

## How it works

The three vectors become the columns of a 3x3 matrix `A`. From there,
everything comes down to the matrix's **rank**:

- **Linear independence check:** 3 vectors in R³ are linearly
  independent only if the matrix formed from them has full rank, which
  is 3 here. If the rank comes out lower, at least one vector can be
  written as a combination of the other two, meaning they're linearly
  **dependent**.
- **Basis and dimension:** the program computes the Reduced Row Echelon
  Form (RREF) of `A`, which reveals the **pivot columns**, the columns
  that contain a leading 1 in the RREF. The *original* columns of `A` at
  those same positions (not the RREF's rows) form a basis for the
  subspace spanned by all three vectors. The number of those pivot
  columns is the subspace's dimension, since a basis's size is what
  "dimension" means.

For this particular set of vectors, `v3 = v1 + v2` (check: `(1,1,0) +
(0,1,1) = (1,2,1)`), so the three vectors don't actually span a full 3D
space, they only span a 2D plane within R³, which is exactly what the
rank of 2 and the dimension of 2 both confirm.

### A note on the source code

The version of this code in the original assignment sheet had its
indentation stripped out somewhere along the way (a common issue with
copy-pasting Python out of a PDF or scanned document), every `if`,
`for`, and `else` block was missing its indentation, which would fail
to run at all in real Python, indentation isn't cosmetic here, it's how
Python knows where a block starts and ends. Restored here with proper
indentation, logic is otherwise unchanged.

## Run it

```
pip install sympy
python linear_independence.py
```

## Sample run

```
v1 = [1, 1, 0]
v2 = [0, 1, 1]
v3 = [1, 2, 1]

Matrix A =
Matrix([[1, 0, 1], [1, 1, 2], [0, 1, 1]])

Rank of Matrix = 2

Vectors are Linearly Dependent

RREF of Matrix =
Matrix([[1, 0, 1], [0, 1, 1], [0, 0, 0]])

Pivot Columns = (0, 1)

Basis for the Subspace =
Matrix([[1], [1], [0]])
Matrix([[0], [1], [1]])

Dimension of the Subspace = 2
```
