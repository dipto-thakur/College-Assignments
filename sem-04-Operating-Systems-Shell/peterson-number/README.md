# Assignment 01 — Peterson Number Checker

**Date:** 26/05/25

## Problem

Write a shell script to check whether a given number is a Peterson number
(also called a Krishnamurthy number). A number qualifies if the sum of the
factorials of its individual digits adds up to the number itself.

145 is the go-to example: 1! + 4! + 5! = 1 + 24 + 120 = 145.

## How it works

The script peels off digits from the number one at a time using `% 10` and
`/ 10`. For every digit it removed, it works out that digit's factorial in a
small inner loop and keeps adding it to a running total. Once there are no
digits left, it just checks if that total matches the original number.

## Run it

```
sh peterson_number.sh
```

You'll be asked to enter a number, and it'll tell you whether it's a
Peterson number or not.

## Sample run

```
$ sh peterson_number.sh
Enter a number :
145

145 is a Peterson or Krishnamurthi Number
```