# Assignment 05 — Primes in a Range Using `factor`

**Date:** 07/07/25

## Problem

Write a shell script that prints all prime numbers between two given
values, using the Linux `factor` command instead of writing your own
divisibility check.

## How it works

`factor` prints a number along with its prime factors, something like
`53: 53`. For a prime number, the only factor listed is the number itself.
The script runs `factor` on each number in the range, then uses `cut`
twice to pull out just that second value after the colon. If that value
matches the number we started with, it means the number has no factors
besides itself, so it's prime.

This one takes the range as command line arguments instead of asking with
`read`.

## Run it

```
sh prime_range_factor.sh 50 70
```

## Sample run

```
$ sh prime_range_factor.sh 50 70
Find prime numbers in the range of 50 to 70
53
59
61
67
```