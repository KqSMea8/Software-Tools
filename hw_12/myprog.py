#!/usr/bin/env python
##myprog.py
##music shuffler

##used for help input
##
import argparse

##used to search directories?
##
import os

##import random
##
import random

import time


if __name__ == "__main__":
    ##music database
    ##
    mdb = []
    directory = '/data/courses/ece_3822/current/music/'
    parser = argparse.ArgumentParser(description='Description: randomly shuffles music')
#    parser.add_argument('-ngram', action="store", dest='ngram_l',  type=int, help="Ngram length")
#    parser.add_argument('-pattern', action="store", dest='word',  type=str, help="Ngram word to search")
#    parser.add_argument('file', type=argparse.FileType('r'), nargs='*')
#    variables = parser.parse_args()
    parser.parse_args()

    ##for testing local directory
    ##
#    for root, dirs, files in os.walk('.'):

    for root, dirs, files in os.walk(directory, topdown=False):
        for name in files:
            if os.path.splitext(name)[1] == ".mp3":
                    ##prints name and directory
                    ##
#                    print os.path.join(root, name)
                    ##prints mp3 name
                    ##
#                    print name
                    mdb.append(name)
    ##shuffle database
    ##
    random.shuffle(mdb)
    for song in mdb:
        print "Playing: " + song
        time.sleep(5)
