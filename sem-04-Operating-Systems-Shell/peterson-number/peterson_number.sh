#!/bin/sh
# Checks whether a number is a Peterson (Krishnamurthy) number.
# A Peterson number is one where the sum of the factorial of its
# digits equals the number itself. 145 is the classic example:
# 1! + 4! + 5! = 1 + 24 + 120 = 145

echo "Enter a number :"
read num

no=$num
sum=0

while [ $no -ge 1 ]
do
    rem=`expr $no % 10`
    no=`expr $no / 10`

    mulsum=1
    while [ $rem -ge 1 ]
    do
        mulsum=`expr $mulsum \* $rem`
        rem=`expr $rem - 1`
    done

    sum=`expr $sum + $mulsum`
done

if [ $sum -eq $num ]
then
    echo "$num is a Peterson or Krishnamurthi Number"
else
    echo "$num is NOT a Peterson or Krishnamurthi Number"
fi