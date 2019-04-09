#!/usr/bin/env python

import argparse
import nltk
from nltk import ngrams
from nltk import word_tokenize
from collections import Counter
import re
from string import digits

if __name__ == "__main__":
    filtered_ngrams = []
    count=[]
    wordfreq = []
    final_ngram = []
    ##initialize argparser to take in arguements and setup help
    ##
    parser = argparse.ArgumentParser()
    parser.add_argument('-ngram', action="store", dest='ngram_l',  type=int, help="Ngram length")
    parser.add_argument('-pattern', action="store", dest='word',  type=str, help="Ngram word to search")
    parser.add_argument('file', type=argparse.FileType('r'), nargs='*')
    variables = parser.parse_args()

    for f in variables.file:
#        content = f.read().lower().replace('\n', ' ').replace('[^a-zA-Z0-9\s]', '')
        content = f.read().lower().replace('\n', ' ').strip('[^a-zA-Z0-9\s]')

        content = content.translate(None, digits)
        tokens = [token for token in content.split(" ") if token != ""]

        all_ngrams = ngrams(tokens,variables.ngram_l)
        ##list comprehension
        ##
        filtered_ngrams.append([x for x in all_ngrams if variables.word in x])

#    for pair in filtered_ngrams:
#        wordfreq.append(filtered_ngrams.count(pair))

    n = 0
    for grammy in filtered_ngrams:
        for row in filtered_ngrams:
#            print row
            for item in row:
#                print item
#                wordfreq.count(item)
                final_ngram.append(item)
                n = n + 1
    wordfreq = Counter(final_ngram)
#    print(str(wordfreq.keys()) + str(wordfreq.values()) + "\n")
#    for i in count:

    # The Top-N words
    print("The Top {0} tokens".format(n))
    for word, count in wordfreq.most_common(n):
        print("{0}: {1}".format(word, count))

##create dictionary
