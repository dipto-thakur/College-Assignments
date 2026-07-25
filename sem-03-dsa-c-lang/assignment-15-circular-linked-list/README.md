# Assignment 15 — Circular Linked List

**Date:** 11/2/2025

## Problem

Write a program to implement a Circular Linked List. Include functions
for insertion, deletion, and search of a number, and reversing the list.

## How it works

In a circular linked list, there's no `NULL` at the end, the last node's
`next` pointer wraps back around to the first node instead. That changes
how a few things need to be handled compared to a regular (non-circular)
list:

- Rather than tracking `head`, this implementation tracks **`tail`**
  instead, with `tail->next` always giving the head. Keeping the tail
  directly means inserting a new node at the end is O(1), tack it on
  after `tail` and update which node `tail` points to, no need to walk
  the whole list first just to find where it ends.
- **Traversal, search, and delete** all use a `do...while` loop instead
  of the usual `while (current != NULL)`, since there's no `NULL` to
  stop at. The loop instead stops once it's walked all the way back
  around to the head (`current != tail->next`).
- **Delete** has a couple of extra edge cases to handle beyond a normal
  list: deleting the only node in the list (which leaves the list
  empty), and deleting the tail itself (which means the node before it
  has to become the new tail).
- **Reverse** flips every node's `next` pointer, same idea as reversing
  any singly linked list, but again has to track where the loop starts
  and stops manually, since normal linked-list reversal usually relies
  on hitting `NULL` to know it's done.

## Compile and run

```
gcc -o circular_linked_list circular_linked_list.c
./circular_linked_list
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
10 -> 20 -> 30 -> (back to head)

Enter choice: 3
Enter value to search: 20
20 found at position 2.

Enter choice: 4
List reversed.
Enter choice: 5
30 -> 20 -> 10 -> (back to head)

Enter choice: 2
Enter value to delete: 20
20 deleted.
Enter choice: 5
30 -> 10 -> (back to head)
```
