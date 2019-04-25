#4.Write a function treemap to map a function over nested list.

#!/usr/bin/env python
import collections

def treemap(a):
    return [map(float, suba) for suba in a]
#    return [list(map(float, suba)) for suba in a]


if __name__ == "__main__":
    print treemap(lambda x: x*x, [1, 2, [3, 4, [5]]])
