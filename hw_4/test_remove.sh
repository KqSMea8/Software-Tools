#!/bin/sh   


#if file eosn't exist make the file                                                                                                                                                  
if [ ! -f rand_playlist.txt ]
then
    rand=(`cat index | shuf`)
    echo "creating file"

    for ((j=0; j<${#rand[@]}; j++)); do
        line=${rand[j]}
        printf "%s\n" $line >> rand_playlist.txt
    done
fi


c=1
j=0
while [ $c = 1 ]; do
    rand=(`cat rand_playlist.txt`)
    line=${rand[$j]}
    echo $rand

    sed -i "1d" rand_playlist.txt
#    sleep 3
    sleep 1
    #if file is empty exit
    if [ ! -s rand_playlist.txt ]
    then

        echo "file empty"
        rand=(`cat index | shuf`)
        echo "creating file"

        for ((j=0; j<${#rand[@]}; j++)); do
            line=${rand[j]}
            printf "line is:%s\n" $line
            printf "%s\n" $line >> rand_playlist.txt
        done

#        exit 0
    fi

    #if j is larger than array exit
#    if [ j >  ${#rand[@]} ]
#    then
#        echo "array too large"
#        exit 0
#    fi


done
