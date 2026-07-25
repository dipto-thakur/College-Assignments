# Assignment 14 — Doubly Linked List

**Date:** 10/2/2025

## Problem

Write a program to implement a Doubly Linked List. Include functions for
insertion, deletion, and search of a number, and reversing the list.

## How it works

The difference from a singly linked list is that every node has two
pointers, `next` and `prev`, so the list can be walked in either
direction.

- **Insertion** still walks to the end to append, but now also sets the
  new node's `prev` pointer back to the old tail, that second link is
  the whole point of "doubly."
- **Deletion** is where the doubly linked structure actually pays off,
  once the node to remove is found, its neighbors can be relinked
  directly through `current->prev` and `current->next`, no need to
  separately track "the node before this one" while walking, like a
  singly linked list's deletion has to.
- **Search** works the same as in a singly linked list, walking forward
  and comparing values.
- **Reverse** just swaps `prev` and `next` on every single node. Once
  every node's pointers are flipped, what used to be the tail is now
  reachable by following `next` from the start, so it becomes the new
  head.

The display functions show the list can genuinely be walked both ways,
`displayForward` starts at the head and follows `next`, `displayBackward`
walks to the tail first and follows `prev` back to the start.

## Compile and run

```
gcc -o doubly_linked_list doubly_linked_list.c
./doubly_linked_list
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
NULL <- 10 <-> 20 <-> 30 <-> NULL

Enter choice: 6
NULL <- 30 <-> 20 <-> 10 <-> NULL

Enter choice: 3
Enter value to search: 20
20 found at position 2.

Enter choice: 4
List reversed.
Enter choice: 5
NULL <- 30 <-> 20 <-> 10 <-> NULL

Enter choice: 2
Enter value to delete: 20
20 deleted.
Enter choice: 5
NULL <- 30 <-> 10 <-> NULL
```
