#! /bin/bash

today="$( date +"%Y%m%d" )"
number=0

for i in `seq -w 1 10`
    do
        while  test -e "$today$suffix.txt"; do
        (( ++number ))
        suffix="$( printf -- '-%02d' "$number" )"
        done

    fname="$today$suffix.txt"

    printf 'Will use "%s" as filename\n' "$fname"
    touch "$fname"
    done
