# Assignment 10 — Evaluation of Postfix Expression

**Date:** 23/12/2024

## Problem

Write a program to evaluate a postfix expression.

## How it works

Postfix notation (also called Reverse Polish Notation) puts the operator
*after* its two operands, `6 2 /` instead of `6 / 2`. The whole point of
this notation is that it can be evaluated in a single left-to-right pass
with a stack, no precedence rules or parentheses to worry about, since
the order operators appear in already encodes exactly when each one
should run.

The scan works like this:

- Every **digit** encountered gets pushed onto the stack as a number.
- Every **operator** encountered means "combine the two most recent
  operands". Two values get popped, `b` (popped first, since it was
  pushed more recently) and `a` (popped second), the operation is
  applied as `a <operator> b`, and the result gets pushed back onto the
  stack as if it were a single operand.

By the time the whole expression has been scanned, exactly one value is
left on the stack, that's the final answer.

This version only supports single-digit operands (0-9), for simplicity,
multi-digit numbers would need space-separated tokens instead of
single characters.

## Compile and run

```
gcc -o postfix_evaluation postfix_evaluation.c
./postfix_evaluation
```

## Sample run

```
Enter a postfix expression (single-digit operands, e.g. 62/3-42*+): 62/3-42*+
Result = 8
```

Worked out by hand: `6 2 /` → 3, `3 3 -` → 0, `4 2 *` → 8, `0 8 +` → 8.
Which matches the infix reading of that same expression: `(6/2) - 3 + 4*2 = 8`.
