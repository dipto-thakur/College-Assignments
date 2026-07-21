# Assignment 04 — Fibonacci Series

**Date:** 16/06/25

## Problem

Write a shell script that prints the first N numbers of the Fibonacci
series.

## How it works

The first two terms, 0 and 1, are printed straight away since there's
nothing to compute for those. From there, every next term is just the sum
of the previous two, so the loop keeps sliding `fib1` and `fib2` forward
one step at a time until it's printed the requested count.

One thing worth flagging: the version of this script floating around in
the original notes uses a fancy `–` (en dash) instead of a plain `-` minus
sign inside the `expr` calls, which will fail in an actual shell. Fixed
that here so it runs as-is.

## Run it

```
sh fibonacci_series.sh
```

## Sample run

```
$ sh fibonacci_series.sh
Enter how many numbers to be printed of Fibonacci Series : 10

Fibonacci Series is :
0 1 1 2 3 5 8 13 21 34
```