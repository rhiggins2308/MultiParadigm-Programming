# Assignment 2 - Challenge 9
# Find the minimum element in an array of integers.
# You can carry some extra information through method arguments such as minimum value.

def findMin(n):
    # Base case: if nums is empty, return string and terminate
    if (len(n) == 0):
        return "Empty"
    # Base case: if nums has only one element, return it and terminate
    elif len(n) == 1:
       return n[0]
    # if n contains more than 1 integer,
    # retirn the minimum of n[0] and the reult of a recursive call that takes na as a parameter, with first element removed
    # continue until base case reached
    # return nested results back up the chain of recursive calls
    else:
       return min(n[0], findMin(n[1:]))

# -----
# test
# -----

nums = []
print(findMin(nums))

nums = [9]
print(findMin(nums))

nums = [9,-3333333333333, -2,6,1,80,9,-2]
print(findMin(nums))