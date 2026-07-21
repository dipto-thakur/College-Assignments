#!/bin/sh
# Finds the second largest number from a list, without using a sorting
# algorithm of our own, we just lean on 'sort' at the very end.

echo "Enter how many numbers you want to enter : "
read n

# start clean in case this file already exists from a previous run
> fnm

echo "Enter numbers : "
while [ $n -gt 0 ]
do
    read num
    echo $num >> fnm
    let n=n-1
done

echo "Entered numbers are : "
cat fnm

echo "Second largest number is : "
echo `sort -nr fnm | head -2 | tail -1`