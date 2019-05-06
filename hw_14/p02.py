#2.Write a function flatten_dict to
# flatten a nested dictionary by joining the keys with "." character

#!/usr/bin/env python

import os
import collections

def flatten_dict (d, parent_key='', sep='.'):
    items = []
    for k, v in d.items():
        new_key = parent_key + sep + k if parent_key else k
        if isinstance(v, collections.MutableMapping):
            items.extend(flatten_dict(v, new_key, sep=sep).items())
        else:
            items.append((new_key, v))
    return dict(items)



if __name__ == "__main__":
    print flatten_dict({'a': 1, 'c': {'a': 2, 'b': {'x': 5, 'y' : 10}}, 'd': [1, 2, 3]})
# print flatten_dict(os.argv[1])
