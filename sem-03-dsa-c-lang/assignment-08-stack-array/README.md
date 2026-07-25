# Assignment 08 — Stack Operations Using Array

**Date:** 09/12/2024

## Problem

Write a program to implement stack operations using an array.

## How it works

A stack is Last-In-First-Out (LIFO), the most recently added element is
always the first one to come back out. Here it's backed by a plain array
plus a single integer, `top`, which tracks the index of the current top
element. An empty stack is represented by `top == -1`.

- **Push** increments `top` and stores the new value there, after first
  checking the stack isn't already full (`top == MAX - 1`), that would
  be stack overflow.
- **Pop** reads the value at `top`, then decrements `top`, effectively
  removing it. Checked against an empty stack first (stack underflow).
- **Peek** just looks at `stack[top]` without removing anything, useful
  to check what's on top without committing to popping it.
- **Display** prints everything currently on the stack, from the top
  down to the bottom.

Everything is wrapped in a menu loop so you can push, pop, and peek
repeatedly in one run instead of the program exiting after a single
operation.

## Compile and run

```
gcc -o stack_array stack_array.c
./stack_array
```

## Sample run

```
--- Stack Menu ---
1. Push
2. Pop
3. Peek (top element)
4. Display
5. Exit
Enter choice: 1
Enter value to push: 10
10 pushed onto the stack.

--- Stack Menu ---
...
Enter choice: 1
Enter value to push: 20
20 pushed onto the stack.

--- Stack Menu ---
...
Enter choice: 4
Stack (top to bottom): 20 10 

--- Stack Menu ---
...
Enter choice: 2
20 popped from the stack.

--- Stack Menu ---
...
Enter choice: 5
Exiting.
```
