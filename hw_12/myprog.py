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

class shuffle(object):
    mdb = []
    contents = []
    def __init__(self):

        directory = '/data/courses/ece_3822/current/music/'
        f= open("songlist.txt","w+")
        for root, dirs, files in os.walk(directory, topdown=False):
            for name in files:
                if os.path.splitext(name)[1] == ".mp3":
                    ##add name
                    self.mdb.append(name)

                    f.write(name + "\n")
        f.close() 
    def shuffler(self):
        random.shuffle(self.mdb)
        f= open("shuffle.txt", "w+")
        for i in self.mdb:
            f.write(i + "\n")
        f.close()

    def open_music(self):
        f= open("shuffle.txt", "r")
        self.contents = f.read()
#        self.contents.split("\n")
        f.close()

    def play(self):
        for song in self.contents:
            print "Playing: " + song
            time.sleep(5)


if __name__ == "__main__":

    music = shuffle()

    parser = argparse.ArgumentParser(description='Description: randomly shuffles music')
    parser.parse_args()

    music.shuffler()
    music.open_music()
    ##shuffle database
    ##
    music.play()
#    for song in music.mdb:
#        print "Playing: " + song
#        time.sleep(5)
