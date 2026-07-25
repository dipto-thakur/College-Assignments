# Assignment 01 — Vector Operations

**Date:** 10/04/26

## Problem

Write a menu-driven program that takes two 3-dimensional vectors, `u`
and `v`, and performs: Vector addition, Scalar multiplication, Dot
product, Cross product, Orthogonality check, Parallelism check.

## How it works

Both vectors are read in once at the start as NumPy arrays, then a menu
loop lets you run any of the six operations repeatedly without
re-entering the vectors each time.

- **Addition** and **scalar multiplication** use NumPy's built-in
  elementwise operators (`+`, `*`), no manual looping needed.
- **Dot product** (`np.dot`) and **cross product** (`np.cross`) are both
  direct NumPy calls.
- **Orthogonality** relies on a basic vector fact: two vectors are
  perpendicular exactly when their dot product is zero. `np.isclose` is
  used instead of a plain `== 0` check, since floating-point arithmetic
  rarely lands on an exact zero even when the true mathematical answer
  is zero.
- **Parallelism** uses a similar fact about the cross product: two
  vectors are parallel exactly when their cross product is the zero
  vector, checked here via its norm (magnitude) being close to zero.

## Run it

```
pip install numpy
python vector_operations.py
```

## Sample run

```
Enter 3 values for Vector u
u1 = 2
u2 = 3
u3 = 4

Enter 3 values for Vector v
v1 = 1
v2 = 5
v3 = 2

========== MENU ==========
1. Vector Addition
2. Scalar Multiplication
3. Dot Product
4. Cross Product
5. Orthogonality Check
6. Parallelism Check
7. Exit
Enter your choice: 1

Vector Addition = [3. 8. 6.]
Enter your choice: 2
Enter scalar value: 3

Scalar Multiplication of u = [ 6.  9. 12.]
Scalar Multiplication of v = [ 3. 15.  6.]
Enter your choice: 3

Dot Product = 25.0
Enter your choice: 4

Cross Product = [-14.   0.   7.]
Enter your choice: 5

Vectors are Not Orthogonal
Enter your choice: 6

Vectors are Not Parallel
Enter your choice: 7

Program Ended
```
