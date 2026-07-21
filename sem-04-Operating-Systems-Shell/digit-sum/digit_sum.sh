#!/bin/sh
# Finds the sum of digits of a number.
# e.g. 846915 -> 8+4+6+9+1+5 = 33

echo "Enter a Number : "
read num

sum=0

while [ $num -gt 0 ]
do
    rem=`expr $num % 10`
    sum=`expr $sum + $rem`
    num=`expr $num / 10`
done

echo "The sum of the digits of the number is $sum"