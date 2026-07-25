# Assignment 13 — Singly Linked List

**Date:** 29/01/2025

## Problem

Write a program to implement a Linked List. Include functions for
insertion, deletion, and search of a number, reversing the list, and
concatenating two linked lists.

## How it works

Two lists are kept (List 1 and List 2) so concatenation has something
real to demonstrate, rather than joining a list to itself.

- **Insertion** (`insertEnd`) walks to the last node and attaches the
  new node after it, keeping insertion order.
- **Deletion** handles the head specially (since removing the head means
  changing what the list's starting pointer even points to), otherwise
  it walks the list keeping one node "behind" the one being checked, so
  it can relink around whichever node gets removed.
- **Search** walks the list comparing each node's value, tracking the
  1-based position as it goes, and returns -1 if it runs off the end
  without a match.
- **Reverse** is done in place in a single pass: for every node, before
  overwriting its `next` pointer to point backward, its original `next`
  gets saved first, otherwise the rest of the list would be lost the
  moment the first pointer got flipped.
- **Concatenate** builds a fresh copy of List 2's nodes (so the original
  List 2 stays intact and usable afterward) and attaches that copy onto
  the end of List 1.

## Compile and run

```
gcc -o singly_linked_list singly_linked_list.c
./singly_linked_list
```

## Sample run

```
Enter choice: 1
Enter value to insert: 10
Enter choice: 1
Enter value to insert: 20
Enter choice: 1
Enter value to insert: 30
Enter choice: 5
List 1: 10 -> 20 -> 30 -> NULL

Enter choice: 6
Enter value to insert: 100
Enter choice: 6
Enter value to insert: 200
Enter choice: 7
List 2: 100 -> 200 -> NULL

Enter choice: 4
List 1 reversed.
Enter choice: 5
List 1: 30 -> 20 -> 10 -> NULL

Enter choice: 8
Lists concatenated into List 1.
Enter choice: 5
List 1: 30 -> 20 -> 10 -> 100 -> 200 -> NULL

Enter choice: 3
Enter value to search: 20
20 found at position 2.
```
