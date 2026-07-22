# Assignment 14 — Employee Role Manager with Packages and Enums

**Date:** 24.07.2025

## Problem

Organize the program into custom packages, `company.employees` and
`company.utils`. Define an enum `Role` with values like `DEVELOPER`,
`MANAGER`, and `TESTER`. Create an `Employee` class storing a name and a
role. Show how an enum from one package gets used in another, and use
`java.util.*` to sort and display employees by role.

## Folder layout

Unlike the other assignments, this one is a real multi-file, multi-package
project, so the folder structure actually matters for compiling it:

```
assignment-14-employee-role-manager/
├── Main.java                          (default package)
└── company/
    ├── employees/
    │   ├── Role.java                  (package company.employees)
    │   └── Employee.java              (package company.employees)
    └── utils/
        └── EmployeeUtils.java         (package company.utils)
```

In Java, a class's package has to match the folder it sits in relative to
your source root, `company.employees.Role` has to live at
`company/employees/Role.java`. That's not optional, the compiler enforces
it.

## How it works

- **`Role`** is a plain enum with three constants. It's declared `public`
  so classes outside `company.employees` (namely `EmployeeUtils` and
  `Main`) are allowed to see and use it. Package-private (the default,
  no modifier) would have hidden it from everything outside its own
  package.
- **`Employee`** stores a name and a `Role`, also `public` for the same
  reason. It overrides `toString()` so printing an `Employee` directly
  gives a readable line instead of a hash code.
- **`EmployeeUtils`**, in the separate `company.utils` package,
  demonstrates the "using an enum from one package in another" part of
  the assignment: it has to `import company.employees.Employee` just to
  reference the type at all, and it never needs to import `Role`
  directly since it only ever touches roles through `Employee.getRole()`.
  It uses `java.util.Comparator` to sort a `List<Employee>` first by role
  name, then by employee name within the same role.
- **`Main`** stays in the default (unnamed) package and pulls everything
  together, it reads employees from the user, prints them in entry
  order, sorts them with `EmployeeUtils.sortByRole()`, then prints them
  again to show the difference.

Role input is validated with `Role.valueOf()` wrapped in a loop, so
typing something that isn't one of the three roles just asks again
instead of crashing the program with an exception.

## Compile and run it

Since this spans multiple packages, you compile it from the top level of
this folder, pointing at all three `.java` files together:

```
javac Main.java company/employees/*.java company/utils/*.java
java Main
```

## Sample run

```
How many employees do you want to enter? 3

Employee 1:
  Name: Aditi Kapoor
  Role (DEVELOPER / MANAGER / TESTER): developer

Employee 2:
  Name: Rohan Mehta
  Role (DEVELOPER / MANAGER / TESTER): manager

Employee 3:
  Name: Sana Iqbal
  Role (DEVELOPER / MANAGER / TESTER): tester

=== Employees, entry order ===
Aditi Kapoor (DEVELOPER)
Rohan Mehta (MANAGER)
Sana Iqbal (TESTER)

=== Employees, sorted by role ===
Aditi Kapoor (DEVELOPER)
Rohan Mehta (MANAGER)
Sana Iqbal (TESTER)
```

(role input isn't case sensitive, "developer" and "DEVELOPER" both work,
since it gets upper-cased before being matched against the enum)