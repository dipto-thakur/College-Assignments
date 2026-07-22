# Assignment 06 — Area Calculator Using Method Overloading

**Date:** 10.06.2025

## Problem

Demonstrate method overloading with three `calculateArea()` methods, one
each for a circle, a rectangle, and a triangle, each taking different
parameters. Let the user pick a shape and enter its measurements, then
print the area.

## How it works

All three methods share the name `calculateArea` but differ in their
parameter lists, which is what overloading actually means in Java, the
compiler picks the right one based on what you pass in. The circle
version takes one `double`, the rectangle version takes two, and the
triangle version also takes two doubles but adds a `boolean` flag so it
has a distinct signature from the rectangle method (Java can't tell two
methods apart by parameter names alone, only by type and count).

A `switch` on the user's menu choice decides which shape to prompt for
and which overload gets called.

### What changed from the original

Swapped `\n` for `%n` in the `printf` calls, `%n` uses the correct line
separator for whatever system the program runs on instead of assuming
Unix-style newlines. Also added a short comment explaining why the
triangle method needs that extra boolean parameter, since that's the one
part of this file that isn't self-explanatory at a glance.

## Run it

```
javac AreaCalculator.java
java AreaCalculator
```

## Sample run

```
Choose a shape to calculate the area:
1. Circle
2. Rectangle
3. Triangle
Enter your choice (1/2/3): 2
Enter length of the rectangle: 5
Enter width of the rectangle: 3
Area of the Rectangle: 15.00
```