#3.Write a function unflatten_dict to do reverse of flatten_dict.

#!/usr/bin/env python


import os
import collections

def unflatten_dict(dictionary):
    resultDict = dict()
    for key, value in dictionary.iteritems():
        parts = key.split(".")
        d = resultDict
        for part in parts[:-1]:
            if part not in d:
                d[part] = dict()
            d = d[part]
        d[parts[-1]] = value
    return resultDict



if __name__ == "__main__":
    print unflatten_dict({'a': 1, 'b.x': 2, 'b.y': 3, 'c': 4})
