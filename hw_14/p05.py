#5.Write a function tree_reverse to reverse elements of a nested-list recursively

#!/usr/bin/env python


import collections


def tree_reverse(L):

    # Empty list
    if len(L) == 0:
        return

    # List with one element
    if len(L) == 1:
        
        # Check if that's a list
        if isinstance(L[0], list):
            return [tree_reverse(L[0])]
        else:
            return L
        
    # List has more elements
    else:
        # Get the reversed version of first list as well as the first element
        return tree_reverse(L[1:]) + tree_reverse(L[:1])




if __name__ == "__main__":
    L = [[1, 2], [3, [4, 5]], 6]
#    print tree_reverse([[1, 2], [3, [4, 5]], 6])
    print tree_reverse(L)
