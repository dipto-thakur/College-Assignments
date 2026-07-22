# Assignment 01 — Prime Number Checker

**Date:** 28.05.2025

## Problem

Take an integer from the user and check whether it's a prime number. A
prime number is greater than 1 and has no positive divisors besides 1 and
itself.

## How it works

Numbers 1 and below are rejected immediately since primality isn't even
defined for them. For anything else, the program only needs to test
divisors up to the square root of the number, if nothing up to that point
divides evenly, nothing bigger will either, so there's no reason to check
further.

### What changed from the original

The original had the primality check written inline inside `main`. Pulled
it out into its own `isPrime()` method instead, it's the same logic, just
easier to read and to test on its own if you ever wanted to.

## Run it

```
javac PrimeNumberChecker.java
java PrimeNumberChecker
```

## Sample run

```
Enter an integer: 7
7 is a prime number.

Enter an integer: 1
1 is not a prime number.
```