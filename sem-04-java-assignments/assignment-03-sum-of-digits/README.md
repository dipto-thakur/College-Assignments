# Assignment 03 — Sum of Digits

**Date:** 02.06.2025

## Problem

Take a positive integer and calculate the sum of its digits, then display
both the original number and the sum.

## How it works

Classic digit extraction: `% 10` gets the last digit, `/= 10` drops it,
repeat until nothing's left. Each digit gets added to a running total
along the way.

### What changed from the original

Moved the digit-summing loop into its own `sumDigits()` method and kept
`main` focused on reading input and printing the result. Also fixed a
stray line break that had split the original output message across two
lines in the source (`"...is: \n" + sum`), which would've printed an
awkward line break in the middle of the sentence.

## Run it

```
javac SumOfDigits.java
java SumOfDigits
```

## Sample run

```
Enter a positive integer: 123
The sum of digits of 123 is: 6

Enter a positive integer: 9876
The sum of digits of 9876 is: 30

Enter a positive integer: -45
Invalid input! Please enter a positive integer.
```