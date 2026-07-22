# Java Programming Assignments

Eleven small Java exercises, moving from basic loops and conditionals
through overloading, inheritance, and polymorphism. Each folder is self
contained, a `.java` file plus a README explaining the problem and the
approach.

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

## Running these

Every folder works the same way:

```
cd assignment-01-prime-checker
javac PrimeNumberChecker.java
java PrimeNumberChecker
```

Just swap in whichever folder and file name you're working with. Most
files are named after their public class (`PrimeNumberChecker.java`,
`Main.java`, and so on), which Java requires, the file name has to match
the public class it contains.

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