# Assignment 07 — Student Details with Constructor Overloading

**Date:** 10.06.2025

## Problem

Define a `Student` class with two overloaded constructors: one taking just
name and roll number, another taking name, roll number, and grade. Create
objects with both and display the details, to show constructor
overloading in action.

## How it works

The 2-argument constructor doesn't duplicate any logic, it just calls the
3-argument constructor with `"Not Assigned"` as a default grade, using
`this(...)` to chain into it. That's the cleanest way to overload
constructors in Java, one does the real work and the others just fill in
sensible defaults before forwarding the call.

The program shows this two ways: first with a couple of hardcoded
students, then again by asking the user to type in details for two more
students using each constructor.

### What changed from the original

Made the `Student` fields `final`, since name, roll number, and grade
never change after a `Student` is constructed here, marking them `final`
makes that intent explicit and lets the compiler catch it if that
ever changes by mistake. No behavioral changes.

## Run it

```
javac Main.java
java Main
```

## Sample run

```
== Hardcoded Students ==
Name: Alice
Roll Number: 101
Grade: Not Assigned
--------------------------
Name: Bob
Roll Number: 102
Grade: A
--------------------------
== Create Student (2-arg constructor) ==
Enter name: Debjit Sil
Enter roll number: 103
== Create Student (3-arg constructor) ==
Enter name: Prajna Mandal
Enter roll number: 104
Enter grade: A
== Entered Students ==
Name: Debjit Sil
Roll Number: 103
Grade: Not Assigned
--------------------------
Name: Prajna Mandal
Roll Number: 104
Grade: A
--------------------------
```