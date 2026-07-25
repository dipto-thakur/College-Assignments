# Assignment 02 — Matrix Properties

**Date:** 22/04/26

## Problem

Write a program that takes a square matrix of order N and computes its
determinant, inverse, transpose, scalar multiplication, adjoint, rank,
diagonal elements, trace, and eigenvalues/eigenvectors.

## How it works

The matrix is entered once, row by row, then a menu loop lets any of
these nine operations run repeatedly. Everything is a fairly direct
NumPy `linalg` call:

- **Determinant** (`np.linalg.det`), **inverse** (`np.linalg.inv`),
  **rank** (`np.linalg.matrix_rank`), and **eigenvalues/eigenvectors**
  (`np.linalg.eig`) all use NumPy's linear algebra module directly.
- **Inverse** and **adjoint** both check the determinant first, a matrix
  only has an inverse (and only has a meaningful adjoint by this method)
  if its determinant is non-zero. `np.isclose` is used rather than `== 0`
  since floating-point determinants of a genuinely singular matrix
  rarely come out as an exact zero.
- **Adjoint** is computed using the identity `adj(A) = det(A) * inv(A)`,
  rather than the more tedious cofactor-expansion definition, this is
  mathematically equivalent and much shorter to code. The result is
  rounded since floating-point rounding in `det` and `inv` can leave
  tiny fractional errors on what should be clean integer entries.
- **Transpose** (`A.T`), **diagonal elements** (`np.diag`), and **trace**
  (`np.trace`) are all one-line NumPy operations.

## Run it

```
pip install numpy
python matrix_properties.py
```

## Sample run

Using the 2x2 matrix `[[4, 2], [1, 3]]`:

```
Enter the order of square matrix: 2
Enter the elements of matrix row wise:
A[0][0] = 4
A[0][1] = 2
A[1][0] = 1
A[1][1] = 3

========== MENU ==========
1. Determinant
...
Enter your choice: 1

Determinant = 10.000000000000002
Enter your choice: 2

Inverse Matrix =
[[ 0.3 -0.2]
 [-0.1  0.4]]
Enter your choice: 3

Transpose Matrix =
[[4. 1.]
 [2. 3.]]
Enter your choice: 5

Adjoint Matrix =
[[ 3. -2.]
 [-1.  4.]]
Enter your choice: 6

Rank = 2
Enter your choice: 7

Diagonal Elements = [4. 3.]
Enter your choice: 8

Trace = 7.0
Enter your choice: 9

Eigen Values =
[5. 2.]

Eigen Vectors =
[[ 0.89442719 -0.70710678]
 [ 0.4472136   0.70710678]]
Enter your choice: 10

Program Ended
```

(the determinant prints as `10.000000000000002` instead of a clean `10`
purely because of how floating-point arithmetic works, that tiny error
is expected and not a bug)
