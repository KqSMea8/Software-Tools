#1.Count the number of times each word occurs in the EEG reports database

#!/usr/bin/env python

import glob, os
from collections import Counter

# Given a list of words, return a dictionary of
# word-frequency pairs.
def wordListToFreqDict(wordlist):
    wordfreq = [wordlist.count(p) for p in wordlist]

    return dict(zip(wordlist,wordfreq))


# Sort a dictionary of word-frequency pairs in
# order of descending frequency.
def sortFreqDict(freqdict):
    aux = [(freqdict[key], key) for key in freqdict]
    aux.sort()
    aux.reverse()
    return aux


def createList(file):
    f= open(file, "r")
    contents = f.read()
    f.close()
    return contents


def word_count(filename):
    with open(filename, 'r') as f:
        c = Counter()
        for line in f:
            c.update(line.strip().split(' '))
        return c


if __name__ == "__main__":
    counters = []
    contents = []
    wordlist = []
    direc = "/data/courses/ece_3822/2019_spring/eeg_reports/"

    direc = "."


    for root, dirs, files in os.walk(direc):
        for file in files:
            if file.endswith(".txt"):
                print os.path.join(root, file)
                counters = word_count(os.path.join(root, file))

#    dict = wordListToFreqDict(wordlist)

    total = sum(counters, Counter())  # sum needs an empty counter to start with

    totalsorted = sortFreqDict(total)

    for t in totalsorted: print(str(t))
#    for s in sorteddict: print(str(s))

