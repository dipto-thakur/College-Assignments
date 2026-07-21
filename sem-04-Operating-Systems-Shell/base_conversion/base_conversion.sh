#!/bin/sh
# Converts a number from one base to another using 'bc', the basic
# calculator, since bc understands ibase/obase natively.

echo "Enter input base : "
read b1

echo "Enter output base : "
read b2

echo "Enter input number : "
read num

# bc expects letters in hex-style numbers to be uppercase (A-F), so
# lowercase input gets converted up front
num=`echo $num | tr '[a-z]' '[A-Z]'`

echo "ibase=$b1" > tem1
echo $num >> tem1
x=`bc < tem1`

echo "obase=$b2" > tem2
echo $x >> tem2
y=`bc < tem2`

echo "$num of base $b1 is equal to $y of base $b2"

rm tem1
rm tem2