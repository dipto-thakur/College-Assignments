# Shell Scripting Assignments

Ten small shell scripting exercises, each in its own folder with a script
and a short README explaining the problem and how the solution works.

Each folder is self contained, so you can `cd` into any one of them and
just run the script directly.

## Assignments

| Folder | What it does |
|---|---|
| assignment-01-peterson-number | Checks if a number is a Peterson (Krishnamurthy) number |
| assignment-02-digit-sum | Adds up the digits of a number |
| assignment-03-palindrome-range | Lists all palindrome numbers in a given range |
| assignment-04-fibonacci-series | Prints the first N terms of the Fibonacci series |
| assignment-05-prime-range-factor | Finds primes in a range using the `factor` command |
| assignment-06-bubble-sort | Sorts a list of numbers using bubble sort (needs bash for arrays) |
| assignment-07-second-largest | Finds the second largest number in a list without sorting it manually |
| assignment-08-base-conversion | Converts a number between two number bases using `bc` |
| assignment-09-wc-simulation | Recreates `wc -l/-w/-c` from scratch |
| assignment-10-quadratic-roots | Solves a quadratic equation, handles real, repeated, and complex roots |

## Running these

Most scripts just need plain `sh`:

```
sh assignment-01-peterson-number/peterson_number.sh
```

The one exception is assignment 06, which uses bash arrays and needs to be
run with `bash` instead of `sh`:

```
bash assignment-06-bubble-sort/bubble_sort.sh
```

A couple of scripts (08 and 10) rely on the `bc` calculator being
installed on your system, which it is by default on most Linux distros
but might need `apt install bc` on a fresh machine.

## A note on the source

These are cleaned up from handwritten lab record scans, so a few things
got fixed along the way, smart/curly quotes swapped for real ones, a
couple of typos in variable names, and one script (assignment 07) got a
line added to clear its temp file between runs so results don't get mixed
up with a previous run. Each README calls out anything that was actually
changed from the original.