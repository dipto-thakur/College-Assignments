# Assignment 09 — Simulating `wc` Without Using It

**Date:** 28/07/25

## Problem

Write a shell script that mimics what the `wc` command does, counting
lines, words, or characters in a file, without actually calling `wc`.

## How it works

The script takes an option (`-l`, `-w`, or `-c`) and a filename as command
line arguments and branches on the option using a `case` statement.

- `-l` just reads the file line by line and counts how many lines it read.
- `-w` reads each line, splits it into positional arguments with `set --`,
  and adds `$#` (the count of words on that line) to a running total.
- `-c` goes a level deeper, looping over every word in every line and
  adding its length plus one (for the space or newline that followed it)
  to a running character count.

Anything other than those three options falls through to "Invalid
option".

A small `text.txt` is included here so you have something to test the
script against right away.

## Run it

```
sh wc_simulation.sh -l text.txt
sh wc_simulation.sh -w text.txt
sh wc_simulation.sh -c text.txt
```

## Sample run

```
$ sh wc_simulation.sh -l text.txt
Number of lines = 5

$ sh wc_simulation.sh -w text.txt
Number of words = 14

$ sh wc_simulation.sh -c text.txt
Number of characters = 74
```

(exact word/character counts will depend on whatever is inside your
`text.txt` at the time)