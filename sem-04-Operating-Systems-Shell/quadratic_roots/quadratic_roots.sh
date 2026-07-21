#!/bin/sh
# Calculates the roots of a quadratic equation ax^2 + bx + c = 0

echo -n "Enter the value of X^2 : "
read a
echo -n "Enter the value of X : "
read b
echo -n "Enter the constant term : "
read c

det=$((2 * a))
d=$(echo "$b*$b - 4*$a*$c" | bc)

if [ "$d" -eq 0 ]; then
    Root1=$(echo "scale=2; -1*$b / $det" | bc -l)
    echo "Root1 = $Root1"
    echo "Root2 = $Root1"

elif [ "$d" -lt 0 ]; then
    l=$(echo "scale=2; sqrt(-1*$d)" | bc -l)
    echo "Root1 = (-$b + i$l) / $det"
    echo "Root2 = (-$b - i$l) / $det"

else
    l=$(echo "scale=2; sqrt($d)" | bc -l)
    Root1=$(echo "scale=2; (-1*$b + $l) / $det" | bc -l)
    Root2=$(echo "scale=2; (-1*$b - $l) / $det" | bc -l)
    echo "Root1 = $Root1"
    echo "Root2 = $Root2"
fi