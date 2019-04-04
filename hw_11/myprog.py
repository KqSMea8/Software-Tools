#!/usr/bin/env python

import argparse
import nltk
from nltk import ngrams
from nltk import word_tokenize
from collections import Counter

if __name__ == "__main__":
    grams=[]
    ##initialize argparser to take in arguements and setup help
    ##
    parser = argparse.ArgumentParser()
    parser.add_argument('-ngram', action="store", dest='ngram_l',  type=int, help="Ngram length")
    parser.add_argument('-pattern', action="store", dest='word',  type=str, help="Ngram word to search")
    parser.add_argument('file', type=argparse.FileType('r'), nargs='*')
    variables = parser.parse_args()

    for f in variables.file:
        content = f.read().split()


        grams.append(ngrams(content,variables.ngram_l))
        print(grams)
#        for line in f:

#            grams = ngrams(line.split(), variables.ngram_l)

    for grammy in grams:
        print grammy

