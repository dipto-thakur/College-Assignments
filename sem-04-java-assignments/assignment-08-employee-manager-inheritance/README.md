# Assignment 08 — Basic Inheritance: Employee and Manager

**Date:** 13.06.2025

## Problem

Create a base class `Employee` with `name` and `salary`, and a derived
class `Manager` that adds a `department` field. Read and display values
for both, to demonstrate single-level inheritance.

## How it works

`Manager extends Employee`, so it automatically gets the `name` and
`salary` fields (declared `protected` so the subclass can reach them
directly) along with the `readEmployeeDetails()` and
`displayEmployeeDetails()` methods, without redefining any of it.

`Manager`'s own `readManagerDetails()` and `displayManagerDetails()`
methods don't duplicate that logic either, they call the inherited
Employee methods first, then handle just the one extra field,
`department`, on top. That's the core idea inheritance is meant to show,
the child class builds on the parent instead of repeating it.

### What changed from the original

Nothing structural, the original was already a clean, textbook example of
single-level inheritance. Just tidied spacing and comments.

## Run it

```
javac Main.java
java Main
```

## Sample run

```
=== Enter Employee Details ===
Enter employee name: Roushan Reja
Enter employee salary: 30000

=== Enter Manager Details ===
Enter employee name: Dipto Sil
Enter employee salary: 30000
Enter manager department: Sales

=== Employee Information ===
Employee Name: Roushan Reja
Employee Salary: 30000.0

=== Manager Information ===
Employee Name: Dipto Sil
Employee Salary: 30000.0
Manager Department: Sales
```