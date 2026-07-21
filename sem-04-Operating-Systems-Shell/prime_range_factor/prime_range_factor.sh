#!/bin/sh
# Finds prime numbers in a given range using the 'factor' command.
# Usage: sh prime_range_factor.sh <lower> <upper>

echo "Find prime numbers in the range of $1 to $2"

i=$1
j=$2

while [ $i -lt $j ]
do
    prime=`factor $i | cut -f2 -d":" | cut -f2 -d" "`

    if [ $i -eq $prime ]
    then
        echo $prime
    fi

    i=`expr $i + 1`
done