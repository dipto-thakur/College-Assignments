# Assignment 08 — Base Conversion

**Date:** 14/07/25

## Problem

Write a shell script that converts a number from one base to another,
given the input base, the output base, and the number itself.

## How it works

Rather than writing base conversion math by hand, this leans entirely on
`bc`, the command line calculator, which already understands `ibase` and
`obase`. The script writes `ibase=<input base>` followed by the number
into a temp file (`tem1`), and piping that into `bc` gives back the
decimal value. Then it does the same thing in reverse with `obase=<output
base>` in a second temp file (`tem2`) to get the number printed in the
target base.

Since `bc` only accepts uppercase letters for digits above 9 (like A-F in
hex), the script runs the input through `tr` first to force lowercase
letters to uppercase. Both temp files get deleted at the end so they don't
clutter the folder.

## Run it

```
sh base_conversion.sh
```

## Sample run

```
$ sh base_conversion.sh
Enter input base :
16
Enter output base :
10
Enter input number :
a9b6a9
A9B6A9 of base 16 is equal to 11122345 of base 10
```

Note: that sample output is copied straight from the original lab record.
`bc` conversions depend on your system's `bc` build, so double check the
actual number you get before trusting it against a real hex-to-decimal
calculation.