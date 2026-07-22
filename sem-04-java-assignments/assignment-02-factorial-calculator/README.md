# Assignment 02 — Factorial Calculator

**Date:** 28.05.2025

## Problem

Take a non-negative integer from the user and print its factorial.
Negative input should be rejected with a clear message, since factorial
isn't defined for negative numbers.

## How it works

Straightforward loop from 1 up to the entered number, multiplying into a
running total each time. The result is stored as a `long` rather than an
`int` since factorials grow fast, 13! already overflows a 32-bit int.

### What changed from the original

Two small things:
- The problem description in the original lab record was copy-pasted
  from the prime checker assignment above it and didn't actually describe
  factorials. Rewrote it here to match what the code does.
- Pulled the multiplication loop into its own `calculateFactorial()`
  method and used an early `return` for the negative-number case instead
  of wrapping the whole rest of `main` in an `else` block. Same behavior,
  just a little flatter and easier to follow.

## Run it

```
javac FactorialCalculator.java
java FactorialCalculator
```

## Sample run

```
Enter a non-negative integer: 5
Factorial of 5 is: 120

Enter a non-negative integer: 0
Factorial of 0 is: 1

Enter a non-negative integer: -3
Invalid input! Factorial is not defined for negative numbers.
```