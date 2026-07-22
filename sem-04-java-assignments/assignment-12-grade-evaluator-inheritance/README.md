# Assignment 12 — Grade Evaluator Using Inheritance

**Date:** 16.07.2025

## Problem

Define a base class `Student` with `name`, `rollNumber`, and `marks`.
Derive `GradeCalculator` from it, adding a `calculateGrade()` method that
assigns a letter grade based on marks:

- 90 and above: A
- 75 to 89: B
- 60 to 74: C
- below 60: D

Prompt the user for their details, then display everything along with
the calculated grade.

## How it works

`GradeCalculator extends Student`, so it inherits `name`, `rollNumber`,
and `marks` (declared `protected` so the subclass can read them directly)
along with `readDetails()` and `displayDetails()`. It doesn't need to
redeclare any of those, it just adds one new method, `calculateGrade()`,
which is a plain if-else ladder checking `marks` against each cutoff from
the top down.

`main` only ever creates a `GradeCalculator`, never a plain `Student`,
since the assignment's whole point is showing the derived class working
with both what it inherited and what it adds.

## Run it

```
javac Main.java
java Main
```

## Sample run

```
Enter student name: Ananya Roy
Enter roll number: 21
Enter marks (out of 100): 82

=== Student Report ===
Name: Ananya Roy
Roll Number: 21
Marks: 82.0
Grade: B
```