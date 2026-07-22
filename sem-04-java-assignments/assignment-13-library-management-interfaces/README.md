# Assignment 13 — Library Management Using Inheritance and Interfaces

**Date:** 18.07.2025

## Problem

Create a base class `LibraryItem` with shared properties like `title` and
`author`. Derive `Book` and `Magazine` from it using single-level
inheritance. Create a `Borrowable` interface with a `borrowItem()`
method, and implement it in the appropriate classes. Display book and
magazine details along with their borrow status.

## How it works

`LibraryItem` is abstract and holds the fields every catalog item shares,
plus a `readCommonDetails()` method both subclasses reuse instead of
duplicating the title/author prompts. It also declares an abstract
`displayDetails()`, which forces `Book` and `Magazine` to each define
their own version.

`Borrowable` is kept as a separate interface rather than folded into
`LibraryItem`, since not every possible library item necessarily needs to
be borrowable (reference-only items, for instance, wouldn't be). Here
both `Book` and `Magazine` do implement it, each tracking its own
`borrowed` boolean and flipping it to `true` inside `borrowItem()`.

This shows two different kinds of code reuse side by side: inheritance
gives `Book` and `Magazine` their shared `title`/`author` handling from
`LibraryItem`, while the `Borrowable` interface gives them a shared
*contract* (a guarantee that `borrowItem()` exists) without forcing them
to share an implementation, each class borrows itself in its own way.

`main` reads in one book and one magazine, borrows only the book, then
prints both, so you can see one item's status change while the other
stays "Available".

## Run it

```
javac Main.java
java Main
```

## Sample run

```
=== Enter Book Details ===
Enter title: Klara and the Sun
Enter author: Kazuo Ishiguro
Enter number of pages: 320

=== Enter Magazine Details ===
Enter title: National Geographic
Enter author: NG Staff
Enter issue number: 214

"Klara and the Sun" has been borrowed.

=== Library Catalog ===
Book: Klara and the Sun by Kazuo Ishiguro
Pages: 320
Status: Borrowed
--------------------------
Magazine: National Geographic by NG Staff
Issue Number: 214
Status: Available
```