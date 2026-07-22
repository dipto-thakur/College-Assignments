# Assignment 10 — Calculator with Overloaded Methods

**Date:** 08.07.2025

## Problem

Build a `Calculator` class with three overloaded `add()` methods, one
for two integers, one for three integers, and one for two doubles. Prompt
the user for each type of input and call the matching method.

## How it works

All three methods are named `add`, and Java tells them apart purely by
their parameter lists: how many parameters there are, and what type each
one is. `add(int, int)` and `add(int, int, int)` differ by count,
`add(int, int)` and `add(double, double)` differ by type. The compiler
resolves which one to call based on the arguments passed at each call
site, so `calc.add(int1, int2)` can never accidentally hit the double
version.

### What changed from the original

This one was already tidy, no structural changes, just consistent
indentation throughout.

## Run it

```
javac Main.java
java Main
```

## Sample run

```
Enter two integers to add:
45
63
Result (int + int): 108

Enter three integers to add:
12
23
34
Result (int + int + int): 69

Enter two decimal numbers to add:
10.2
15.8
Result (double + double): 26.0
```