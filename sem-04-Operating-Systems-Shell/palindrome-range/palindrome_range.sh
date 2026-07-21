#!/bin/sh
# Prints all palindrome numbers between a given lower and upper range.

echo "Enter lower and upper range"
read low
read up

while [ $low -le $up ]
do
    num=$low
    number=$low
    sum=0

    while [ $num -gt 0 ]
    do
        rem=`expr $num % 10`
        sum=`expr $sum \* 10 + $rem`
        num=`expr $num / 10`
    done

    if [ $sum -eq $number ]
    then
        echo "$number is palindrome"
    fi

    low=`expr $low + 1`
done