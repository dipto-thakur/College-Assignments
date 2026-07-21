#!/bin/bash
# Sorts an array of numbers using Bubble Sort.
# Uses bash arrays, so this needs to be run with bash, not plain sh.

echo "Enter how many numbers to be sorted : "
read n

i=0
echo "Enter numbers : "
while [ $i -lt $n ]
do
    read arr[$i]
    let i=i+1
done

i=0
echo "The entered numbers are : "
while [ $i -lt $n ]
do
    echo ${arr[$i]}
    let i=i+1
done

i=0
j=0
while [ $i -lt $n ]
do
    let j=i+1
    while [ $j -lt $n ]
    do
        if [ ${arr[$i]} -gt ${arr[$j]} ]
        then
            temp=${arr[$i]}
            arr[$i]=${arr[$j]}
            arr[$j]=$temp
        fi
        let j=j+1
    done
    let i=i+1
done

i=0
echo "Numbers after sorting : "
while [ $i -lt $n ]
do
    echo ${arr[$i]}
    let i=i+1
done