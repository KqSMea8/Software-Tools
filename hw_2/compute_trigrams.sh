#!/bin/bash
#finds all files with a ".txt and "cat's" them so their punctuation is removed #as well as only keeping letters and changing them to lowercase 
find $1 -name "*\.txt" -exec cat {} + | tr -d '[:punct:]' | tr -sc "[A-Z][a-z]'" '[\012*]' | tr  '[:upper:]' '[:lower:]' | awk -- 'first!=""&&second!="" { print first,second,$0; } { first=second; second=$0; }' | sort | uniq -c | sort -nr > trigrams

#the awk command takes the first word, shifts it to the second and the second
#to the third so that all combinations are printed, it is then sorted and number#iphied and sorted again and saved into trigrams

awk '{printf"%s %s %s\t%f%\n",$2, $3, $4, $1*100/814032}' trigrams | head -10 | column -t > top_ten

#awk displays three words and percentage at the end, then filters for top 10 and saves to top_ten

cat top_ten
#displays top_ten
