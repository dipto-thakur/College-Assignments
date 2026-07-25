# Assignment 12 — Binary Search Tree (BST) Operations

**Date:** 22/1/2025

## Problem

Write a program to create a BST and include the following operations:

(a) Insertion
(b) Deletion
(c) Search a node in BST
(d) Display its preorder, postorder, and inorder recursively
(e) Display its level-by-level nodes and leaf nodes
(f) Display height of tree

## How it works

A BST keeps one invariant at every node: everything in its left subtree
is smaller, everything in its right subtree is larger (or equal, here
ties go right). Every operation below relies on that invariant to avoid
searching the whole tree.

**(a) Insertion** walks down from the root, going left or right based on
the comparison, until it finds an empty spot (a `NULL` child) and puts
the new node there.

**(b) Deletion** has three cases, since removing a node can't just
delete it blindly without breaking the tree structure:
- No children → just remove it.
- One child → replace the node with that one child.
- Two children → can't just remove it without leaving a gap, so instead
  its value gets replaced with its **inorder successor** (the smallest
  value in its right subtree, found by `findMin`), and *that* successor
  node gets deleted instead, which is guaranteed to be an easier case
  since the successor never has a left child.

**(c) Search** is the same left/right walk as insertion, just checking
for equality instead of finding an empty spot.

**(d) The three recursive traversals** all visit left subtree, node,
right subtree in some order, just in a different sequence:
- Preorder: node, left, right
- Inorder: left, node, right (this one always comes out sorted, for a
  BST specifically)
- Postorder: left, right, node

**(e) Level-order** uses a simple array-backed queue: start with the
root queued up, then repeatedly dequeue a node, print it, and queue up
its children. Printing a newline every time the current queue length
(captured at the start of that round) empties out marks the boundary
between tree levels. **Leaf nodes** are just any node with no children
at all, found with a plain recursive scan.

**(f) Height** is defined here as the number of edges on the longest
path from the root down to a leaf (so a single-node tree has height 0,
an empty tree is defined as height -1). Computed recursively: a node's
height is 1 plus the taller of its two subtrees' heights.

## Compile and run

```
gcc -o bst_operations bst_operations.c
./bst_operations
```

## Sample run

Inserting 50, 30, 70, 20, 40, 60, 80 builds this tree:

```
              50
           /      \
         30        70
        /  \      /  \
      20    40   60    80
```

```
Enter choice: 4
Preorder: 50 30 20 40 70 60 80 

Enter choice: 5
Inorder: 20 30 40 50 60 70 80 

Enter choice: 6
Postorder: 20 40 30 60 80 70 50 

Enter choice: 7
Level-by-level:
50 
30 70 
20 40 60 80 

Enter choice: 8
Leaf nodes: 20 40 60 80 

Enter choice: 9
Height of tree: 2
```

Deleting 30 (a node with two children) replaces it with its inorder
successor, 40, the smallest value in its right subtree:

```
Enter choice: 2
Enter value to delete: 30
30 deleted.

Enter choice: 5
Inorder: 20 40 50 60 70 80 
```
