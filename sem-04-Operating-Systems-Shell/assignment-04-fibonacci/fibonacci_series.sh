#!/bin/sh
# Prints the first N numbers of the Fibonacci series.

echo "Enter how many numbers to be printed of Fibonacci Series"
read num

fib1=0
fib2=1

echo "Fibonacci Series is"
echo $fib1
echo $fib2

num=`expr $num - 2`

while [ $num -gt 0 ]
do
    fib3=`expr $fib1 + $fib2`
    echo $fib3

    fib1=$fib2
    fib2=$fib3
    num=`expr $num - 1`
done