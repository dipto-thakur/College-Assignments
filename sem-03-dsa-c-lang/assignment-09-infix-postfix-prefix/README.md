# Assignment 09 — Infix to Postfix and Prefix Conversion

**Date:** 18/12/2024

## Problem

Write a program to convert an infix expression into both postfix and
prefix notation.

## How it works

### Infix to Postfix

This uses the standard stack-based conversion algorithm. Reading the
infix expression left to right:

- **Operands** (letters or digits) go straight to the output, they never
  touch the stack.
- **`(`** always gets pushed, it marks a boundary that later operators
  shouldn't cross.
- **`)`** triggers popping everything off the stack into the output
  until the matching `(` is found, that `(` itself gets discarded, not
  output.
- **Operators** pop anything already on the stack with equal or higher
  precedence first (which sends those to the output before the current
  operator), then get pushed themselves. The one exception is `^`
  (power), which is right-associative, so equal-precedence `^` doesn't
  get popped, that's what the `c != '^'` check in the precedence
  comparison handles.

At the end, whatever's left on the stack gets popped off into the
output in order.

### Infix to Prefix

Rather than writing a second algorithm from scratch, this reuses the
postfix logic with a well-known trick:

1. Reverse the infix string.
2. Swap every `(` for `)` and every `)` for `(`.
3. Run that through the exact same infix-to-postfix function.
4. Reverse the result.

Reversing and swapping parentheses effectively flips which side each
operator "reaches for" first, which is exactly the adjustment needed to
turn a postfix-style algorithm into a prefix one.

Only single-character operands are supported (like `a`, `b`, `1`), not
multi-digit numbers or multi-letter variable names, that keeps the
parsing simple and is the standard scope for this kind of lab exercise.

## Compile and run

```
gcc -o infix_conversion infix_conversion.c
./infix_conversion
```

## Sample run

```
Enter an infix expression (single-character operands, e.g. a+b*(c-d)): a+b*(c-d)

Infix:   a+b*(c-d)
Postfix: abcd-*+
Prefix:  +a*b-cd
```
