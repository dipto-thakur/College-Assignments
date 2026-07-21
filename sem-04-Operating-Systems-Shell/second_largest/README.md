# Assignment 07 — Second Largest Number

**Date:** 14/07/25

## Problem

Write a shell script that finds the second largest number from a list of
numbers entered by the user, without writing your own sorting logic.

## How it works

Instead of sorting manually, the script just writes every entered number
into a temporary file called `fnm`, one per line. Then it hands the actual
sorting off to the `sort` command, sorting numerically in reverse with
`sort -nr`. `head -2` grabs the top two lines from that sorted output, and
`tail -1` keeps only the second one, which is exactly the second largest
value.

Added a small `> fnm` at the top to clear out that file before writing to
it, otherwise old numbers from a previous run would stick around and mess
with the result. The original script didn't have this and would silently
append to the same file every time it ran.

## Run it

```
sh second_largest.sh
```

## Sample run

```
$ sh second_largest.sh
Enter how many numbers you want to enter : 5
Enter numbers :
21
78
46
94
53

Entered numbers are :
21
78
46
94
53

Second largest number is :
78
```