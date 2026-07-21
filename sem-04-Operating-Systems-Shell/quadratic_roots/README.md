# Assignment 10 — Roots of a Quadratic Equation

**Date:** 28/07/25

## Problem

Write a shell script that calculates the roots of a quadratic equation
ax² + bx + c = 0, given the three coefficients a, b, and c.

## How it works

The script asks for a, b, and c, then works out the discriminant
`d = b² - 4ac` using `bc` since plain shell arithmetic can't do
multiplication of this sort cleanly with negative intermediate values.
Depending on the sign of `d`:

- if `d = 0`, there's one repeated real root
- if `d < 0`, the roots are complex, so it prints them in the `a + ib`
  form using the square root of `-d`
- if `d > 0`, there are two distinct real roots, calculated the normal
  way with the quadratic formula

All the actual division and square root work is handed off to `bc -l`,
with `scale=2` so the answers come out rounded to two decimal places
instead of a long string of digits.

There was a stray typo at the very top of the original script (`e echo -n
...` instead of just `echo -n ...`) which would have thrown an error
immediately, that's fixed here.

## Run it

```
sh quadratic_roots.sh
```

## Sample run

```
$ sh quadratic_roots.sh
Enter the value of X^2 : 1
Enter the value of X : -3
Enter the constant term : 2
Root1 = 2.00
Root2 = 1.00
```