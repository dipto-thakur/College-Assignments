# Assignment 09 — Method Overriding: Animal Sound

**Date:** 01.07.2025

## Problem

Define a base class `Animal` with a `makeSound()` method that prints a
generic message. Create `Dog`, `Cat`, and `Cow` subclasses that override
it with their own sound, then demonstrate runtime polymorphism by calling
`makeSound()` on objects of each.

## How it works

Each subclass overrides `makeSound()` with `@Override`, which isn't
strictly required by the compiler but is good practice, it makes the
intent explicit and causes a compile error if the method signature ever
drifts from the parent's by accident.

The `animal` variable is declared as type `Animal`, but which version of
`makeSound()` actually runs is decided at runtime based on what object
got assigned to it, a `Dog`, `Cat`, `Cow`, or a fallback plain `Animal` if
the input didn't match anything. That's the whole point being
demonstrated here: the same line of code, `animal.makeSound()`, behaves
differently depending on the real object behind that reference.

### What changed from the original

Added `.trim()` before `.toLowerCase()` on the input line, so a stray
space typed before or after "dog"/"cat"/"cow" doesn't accidentally send it
down the "unknown animal" fallback path.

## Run it

```
javac Main.java
java Main
```

## Sample run

```
Enter the animal name (dog/cat/cow):
cat
Meow Meow!
```