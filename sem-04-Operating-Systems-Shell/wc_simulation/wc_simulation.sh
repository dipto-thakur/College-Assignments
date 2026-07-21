#!/bin/sh
# A homemade version of 'wc', supporting -l (lines), -w (words) and
# -c (characters). Usage: sh wc_simulation.sh -l|-w|-c <filename>

case $1 in

    -l)
        nol=0
        while read line
        do
            nol=$((nol + 1))
        done < $2
        echo "Number of lines = $nol"
        ;;

    -w)
        now=0
        while read line
        do
            set -- $line
            now=$((now + $#))
        done < $2
        echo "Number of words = $now"
        ;;

    -c)
        noc=0
        while read line
        do
            for word in $line
            do
                ch=${#word}
                ch=$((ch + 1))
                noc=$((noc + ch))
            done
        done < $2
        echo "Number of characters = $noc"
        ;;

    *)
        echo "Invalid option"
        ;;
esac