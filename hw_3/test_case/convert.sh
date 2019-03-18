#!/bin/bash

#text to print out for the -help option
usage='name: convert.sh\nsynopsis: convert.sh [filename] [new directory] [options]\ndescr: takes a filename as its first argument, supports an option named “-help”, and converts this text file into a script that copies each file from one filename to another.\n\noptions:\n\t-help: display this help message\n\narguments: standard tool arguements are passed to the tool\n\nman pages: none\n'

#case setup to read all inputs and check for -help command
while [ "$1" != "" ]; do
    case $1 in
        -h | -help)  printf "$usage"
                     exit 0
                     ;;
#takes both arguements and stores them
        *) FILENAME="$1"
           NEWDIR="$2"       
           shift
        ;;

    esac
#shifts arguements to check for further inputs
    shift
done
#initial count i at 0
i=0
#using IFS to read line by line and make edits
while IFS='' read -r line || [[ -n "$line" ]]; do
    i=`expr $i + 1`
    printf "cp $line $NEWDIR/f%08d.txt \n" $i
#storing final results to documentation.txt file
done < "$FILENAME" > documenation.txt

