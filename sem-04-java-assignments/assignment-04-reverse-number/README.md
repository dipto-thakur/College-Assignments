# Assignment 04 — Reverse a Number

**Date:** 02.06.2025

## Problem

Take an integer from the user and print it reversed. 1234 should come
back as 4321.

## How it works

Same digit-by-digit approach as the sum-of-digits assignment, but instead
of adding digits together, each one gets shifted into a new number:
`reversed = reversed * 10 + digit`. That multiply-by-10 step is what
pushes the previously placed digits one position to the left to make room
for the new one.

Worth noting, numbers ending in zero lose those trailing zeros when
reversed, since leading zeros aren't stored in an int, that's why 1000
reverses to 1, not 0001. That's expected behavior, not a bug.

### What changed from the original

Split the reversing loop into its own `reverse()` method rather than
doing it directly inside `main`. No behavior changes otherwise.

## Run it

```
javac ReverseInteger.java
java ReverseInteger
```

## Sample run

```
Enter an integer to reverse: 1234
Original number: 1234
Reversed number: 4321

Enter an integer to reverse: 5050
Original number: 5050
Reversed number: 505

Enter an integer to reverse: 1000
Original number: 1000
Reversed number: 1
```