#!/usr/bin/env python

import argparse
import nltk
from nltk import ngrams
from nltk import word_tokenize
from collections import Counter
import re

if __name__ == "__main__":
    filtered_ngrams = []
    wordfreq = []
    ##initialize argparser to take in arguements and setup help
    ##
    parser = argparse.ArgumentParser()
    parser.add_argument('-ngram', action="store", dest='ngram_l',  type=int, help="Ngram length")
    parser.add_argument('-pattern', action="store", dest='word',  type=str, help="Ngram word to search")
    parser.add_argument('file', type=argparse.FileType('r'), nargs='*')
    variables = parser.parse_args()

    for f in variables.file:
        content = f.read().lower().replace('\n', ' ').replace('[^a-zA-Z0-9\s]', '')
        tokens = [token for token in content.split(" ") if token != ""]

        all_ngrams = ngrams(tokens,variables.ngram_l)
        ##list comprehension
        ##
        filtered_ngrams.append([x for x in all_ngrams if variables.word in x])

#    for pair in filtered_ngrams:
#        wordfreq.append(filtered_ngrams.count(pair))


    for grammy in filtered_ngrams:
        for i in grammy:
            wordfreq.append(filtered_ngrams.count(i))
            print i

    print("Frequencies\n" + str(wordfreq) + "\n")
