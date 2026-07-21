# Assignment 03 — Palindrome Numbers in a Range

**Date:** 09/06/25

## Problem

Write a shell script that takes a lower and upper bound and prints every
palindrome number that falls within that range.

## How it works

For each number in the range, the script reverses it digit by digit (same
`% 10` / `/ 10` trick again) and builds up the reversed value in `sum`. If
the reversed number equals the original, it's a palindrome and gets
printed. Then it just moves to the next number and repeats until it passes
the upper bound.

## Run it

```
sh palindrome_range.sh
```

It'll ask for the lower range first, then the upper range.

## Sample run

```
$ sh palindrome_range.sh
Enter lower and upper range
101
202
101 is palindrome
111 is palindrome
121 is palindrome
131 is palindrome
141 is palindrome
151 is palindrome
161 is palindrome
171 is palindrome
181 is palindrome
191 is palindrome
202 is palindrome
```