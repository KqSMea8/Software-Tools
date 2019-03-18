#!/bin/bash

#text to print out for the -help option
usage='name: convert.sh\nsynopsis: convert.sh [filename] [new directory] [options]\ndescr: takes a filename as its first argument, supports an option named “-help”, and converts this text file into a script that copies each file from one filename to another.\n\noptions:\n\t-help: display this help message\n\narguments: standard tool arguements are passed to the tool\n\nman pages: none\n'

#case setup to read all inputs and check for -help command
while [ "$1" != "" ]; do
    case $1 in
        -h | -help)  printf "$usage"
                     exit 0
                     ;;
        *) FILENAME="$1"
        shift
        NEWDIR="$1"
        ;;

    esac
    shift
done
echo $FILENAME
echo $NEWDIR

#if [ $# -eq 0 ]
#then
#    echo "No arguement detected, please enter your directory or -help"

#else

i=0

while IFS='' read -r line || [[ -n "$line" ]]; do
    i=`expr $i + 1`
    printf "cp $line $NEWDIR/f%08d.txt \n" $i
done < "$FILENAME" > documenation.txt

#fi
