# Assignment 02 — Sum of Digits

**Date:** 02/06/25

## Problem

Write a shell script that takes a number and prints the sum of all its
digits.

## How it works

Pretty much the same digit extraction trick as assignment 1, minus the
factorial part. Every loop pulls off the last digit with `% 10`, adds it to
a running sum, then chops that digit off with `/ 10`. Loop ends when there's
nothing left of the number.

## Run it

```
sh digit_sum.sh
```

## Sample run

```
$ sh digit_sum.sh
Enter a Number :
846915
The sum of the digits of the number is 33
```