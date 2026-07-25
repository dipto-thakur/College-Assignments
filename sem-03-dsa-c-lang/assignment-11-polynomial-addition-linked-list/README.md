# Assignment 11 — Addition of Two Polynomials Using Linked List

**Date:** 13/1/2025

## Problem

Write a program to add two polynomials, representing each as a linked
list.

## How it works

Each term of a polynomial (a coefficient and an exponent, like `5x^2`)
becomes one node in a linked list. Terms are kept **sorted by exponent,
in descending order**, `insertTerm()` walks the list to find the right
spot for each new term as it's read in, rather than just appending to
the end.

That sorted ordering is what makes addition simple. `addPolynomials()`
walks both polynomials' lists at the same time, comparing the front
term of each:

- **Same exponent** on both sides → add the two coefficients together
  into one term (and skip it entirely if they cancel out to zero).
- **Different exponents** → whichever term has the higher exponent gets
  copied into the result as-is, and only that list advances, since the
  other polynomial doesn't have a matching term to combine with yet.

This is exactly the same "two sorted lists" merge pattern used in merge
sort, just merging on exponent instead of merging on value, and adding
instead of just picking the smaller one.

Once one list runs out, whatever's left in the other gets copied over
directly, there's nothing left to compare it against.

## Compile and run

```
gcc -o polynomial_addition polynomial_addition.c
./polynomial_addition
```

## Sample run

```
=== First Polynomial ===
Enter number of terms: 3
Enter coefficient and exponent for term 1: 5 2
Enter coefficient and exponent for term 2: 4 1
Enter coefficient and exponent for term 3: 2 0

=== Second Polynomial ===
Enter number of terms: 2
Enter coefficient and exponent for term 1: -5 1
Enter coefficient and exponent for term 2: 8 0

First polynomial:  5x^2+4x+2
Second polynomial: -5x+8
Sum:               5x^2-1x+10
```

Worked out by hand: the `x^2` term (5) only exists in the first
polynomial, so it carries over unchanged. The `x^1` terms combine,
`4 + (-5) = -1`. The constant terms combine, `2 + 8 = 10`.
