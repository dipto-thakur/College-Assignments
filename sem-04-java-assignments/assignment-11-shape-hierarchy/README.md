# Assignment 11 — Shape Hierarchy with Inheritance and Overriding

**Date:** 15.07.2025

## Problem

Create an abstract `Shape` class with a `displayArea()` method. Derive
`Rectangle`, `Square`, and `Circle` from it, each implementing their own
area calculation. Store different shape objects in a `Shape[]` array and
call `displayArea()` on each through a loop, showing inheritance and
overriding together.

## How it works

`Shape` is marked `abstract` and its `displayArea()` method has no body,
just a signature, which forces every subclass to provide its own
implementation. That's the difference between this and the plain
overriding shown in the Animal Sound assignment: here the base class
can't even be instantiated on its own, it only exists to define the
contract that `Rectangle`, `Square`, and `Circle` all have to follow.

The array `shapes` is typed as `Shape[]`, but each slot actually holds a
different concrete subclass. When the loop calls `shape.displayArea()`,
Java looks at the real object in memory, not the array's declared type,
to decide which version to run. That's runtime polymorphism doing the
work.

### What changed from the original

Made the `length`, `width`, `side`, and `radius` fields `final` in each
shape class, since they're set once in the constructor and never meant to
change. Also swapped the three separate `shapes[0] = ...` assignment
lines for an array initializer, `Shape[] shapes = { ... }`, which is
slightly more idiomatic for building a fixed-size array you already know
the contents of upfront.

## Run it

```
javac Main.java
java Main
```

## Sample run

```
Enter length and width of rectangle: 2.5
3.5
Enter side of square: 6.5
Enter radius of circle: 6.6

Displaying areas polymorphically:
Rectangle area: 8.75
Square area: 42.25
Circle area: 136.8477759903714
```