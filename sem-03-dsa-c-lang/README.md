# Data Structure Lab Assignments [CC3] — C Language

Fifteen lab exercises covering searching, sorting, stacks, expression
conversion and evaluation, polynomial arithmetic, binary search trees,
and the three main flavors of linked lists. Each folder is self
contained: one `.c` file plus a README explaining the problem and the
approach.

## Assignments

| Folder | Topic |
|---|---|
| assignment-01-binary-linear-search | Linear search and binary search, user picks which |
| assignment-02-matrix-multiplication | Matrix multiplication |
| assignment-03-sparse-matrix | Sparse matrix, triplet representation, and fast transpose |
| assignment-04-sorting-menu | Insertion / bubble / selection sort, user picks which |
| assignment-05-merge-sort | Merge Sort |
| assignment-06-quick-sort | Quick Sort (Lomuto partition) |
| assignment-07-heap-sort | Heap Sort |
| assignment-08-stack-array | Stack operations (push, pop, peek, display) using an array |
| assignment-09-infix-postfix-prefix | Infix to postfix and prefix conversion |
| assignment-10-postfix-evaluation | Postfix expression evaluation |
| assignment-11-polynomial-addition-linked-list | Polynomial addition using linked lists |
| assignment-12-bst-operations | BST: insert, delete, search, all 3 traversals, level-order, leaf nodes, height |
| assignment-13-singly-linked-list | Singly linked list: insert, delete, search, reverse, concatenate |
| assignment-14-doubly-linked-list | Doubly linked list: insert, delete, search, reverse |
| assignment-15-circular-linked-list | Circular linked list: insert, delete, search, reverse |

## Compile and run

Every folder works the same way:

```
cd assignment-01-binary-linear-search
gcc -o search search.c
./search
```

Just swap in the folder and filename for whichever assignment you're
running. All programs are self contained, standard C, no external
libraries beyond the usual `stdio.h`, `stdlib.h`, `string.h`, `ctype.h`.

## How these fit together

- **Assignments 5, 6, and 7** are all O(n log n) sorting algorithms
  (merge, quick, heap), shown separately from assignment 4's simpler
  O(n²) trio (insertion, bubble, selection), so it's easy to compare
  approaches side by side on the same kind of input.
- **Assignments 9 and 10** go together: 9 converts an infix expression
  into postfix (and prefix), 10 evaluates a postfix expression. Feed the
  postfix output of 9 into 10 and it'll evaluate cleanly.
- **Assignments 13, 14, and 15** are the three linked list variants,
  same core operations (insert, delete, search, reverse) implemented
  three times, so the difference in what each structure actually buys
  you shows up directly: singly linked (13) is the baseline, doubly
  linked (14) adds backward traversal and simpler deletion, circular
  (15) removes the `NULL` terminator entirely and needs `do...while`
  loops in its place.

## On the assignment dates

The original lab sheet listed 16 dates for 15 assignments, with the
first one (06/11/2021) years out of step with the rest, which all fall
in the 2024-2025 range. That first date looks like a stray leftover
(possibly the semester's original start date, or a typo), so it wasn't
used, the remaining 15 dates were assigned to assignments 1 through 15
in order, and that's what each README's date line reflects.
