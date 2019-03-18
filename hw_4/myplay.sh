#!/bin/sh

################################
##FILE CHECK AND INITIAL SETUP##
################################

#file directory input
filepath=$1

#find /data/courses/ece_3822/current/music/* -name "*.mp3" | sort -u | wc
find "$filepath" -name "*.mp3" -exec basename {} ';' | sort -u > music_file

#create array of all music found
arr=(`cat music_file | sort`)

#if index file doesn't exist make index
if [ ! -f index ]
then
    #iterate through array using a counter                                                                                                                                          
    for ((i=0; i<${#arr[@]}; i++)); do
    #index music and write to index file to use as reference 
        line_info=${arr[$i]}
        echo $line_info >> index
    done
fi

#if file doessn't exist make the file
if [ ! -f rand_playlist.txt ]
then
#   randomize song playlist
    rand=(`cat index | shuf`)
    for ((j=0; j<${#rand[@]}; j++)); do
#       put songs into file
        echo ${rand[j]} >> rand_playlist.txt
    done
fi


##############
## MAIN CODE##
##############

#if file exists check array for songs to still play
if [ -f rand_playlist.txt ]
    rand=(`cat rand_playlist.txt`)
#initialize song index listing
k=1
then
     while true; do
        rand=(`cat rand_playlist.txt`)
#       check first item in array
        line=${rand[0]} 
#       #find original song number
        orig_index=`cat index | grep -n -h "$line" | grep -Eo '^[^:]+'`
#       remove song from shuffle
        sed -i  "1d" rand_playlist.txt

#       debugging
#        echo "Press CTRL+C to proceed."
#        trap "pkill -f 'sleep 1h'" INT
#        trap "set +x ; sleep 1h ; set -x" DEBUG

#       display requirements
        printf "%s (%s, ): playing file %s\n"  $k $orig_index $rand
        #sleep to simulate playing song
        sleep 1
        #add to k for next song number being played
        ((k=k+1))

#       if file is empty make new shuffle                             
        if [ ! -s rand_playlist.txt ]
        then
            rand=(`cat index | shuf`)
#           restart song index listing
            k=1
            for ((j=0; j<${#rand[@]}; j++)); do
                line=${rand[j]}
                printf "%s\n" $line >> rand_playlist.txt
            done
        
        fi

    done
fi

#end of file
