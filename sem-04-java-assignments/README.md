# Java Programming Assignments

Fourteen small Java exercises, moving from basic loops and conditionals
through overloading, inheritance, interfaces, and finally packages and
enums. Each folder is self contained, one or more `.java` files plus a
README explaining the problem and the approach.

## Assignments

| Folder | Topic |
|---|---|
| assignment-01-prime-checker | Checks whether a number is prime |
| assignment-02-factorial-calculator | Calculates the factorial of a number |
| assignment-03-sum-of-digits | Adds up the digits of a number |
| assignment-04-reverse-number | Reverses the digits of a number |
| assignment-05-even-odd-counter | Counts evens and odds within a range |
| assignment-06-area-calculator-overloading | Method overloading, one `calculateArea()` per shape |
| assignment-07-student-constructor-overloading | Constructor overloading with constructor chaining |
| assignment-08-employee-manager-inheritance | Single-level inheritance, Employee → Manager |
| assignment-09-animal-sound-overriding | Method overriding and runtime polymorphism |
| assignment-10-calculator-overloading | Method overloading across int and double types |
| assignment-11-shape-hierarchy | Abstract classes, inheritance, and polymorphism together |
| assignment-12-grade-evaluator-inheritance | Single-level inheritance, Student → GradeCalculator |
| assignment-13-library-management-interfaces | Inheritance plus an interface, LibraryItem → Book/Magazine, Borrowable |
| assignment-14-employee-role-manager | Custom packages, an enum, and sorting with `java.util` |

## Running these

Assignments 01 through 13 are all single-file, single-package programs
and work the same way:

```
cd assignment-01-prime-checker
javac PrimeNumberChecker.java
java PrimeNumberChecker
```

Just swap in whichever folder and file name you're working with. Most
files are named after their public class (`PrimeNumberChecker.java`,
`Main.java`, and so on), which Java requires, the file name has to match
the public class it contains.

Assignment 14 is the one exception, it actually spans real packages
(`company.employees`, `company.utils`), so it has its own multi-file
folder structure and its own compile command. See that folder's README
for details.

## A note on the code

These started as handwritten lab record scans, so a handful of small
things got cleaned up along the way: pulled a few inline loops out into
their own named methods for readability, fixed a couple of formatting
slips in the original source (a stray line break inside a print
statement, `\n` swapped for the more portable `%n` in one `printf` call),
and marked a few fields `final` where they're genuinely never reassigned
after construction. None of that changes what any program actually does,
every sample output still matches. Each README calls out exactly what, if
anything, changed in that particular file.

Assignment 02's original problem description was also a copy-paste of
assignment 01's (both said "prime number checker"), that's corrected here
to actually describe factorials.