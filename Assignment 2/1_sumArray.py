# Assignment 2 - Challenge 1
# Sum of an array
# Given an array of numbers return it’s sum (all the numbers added together)
# ----------------------------------------------------------------------------

def sumArr(arr):
    # check array length. 
    
    # Base case: If empty, return 0
    if (len(arr) == 0):
        return 0
    # If 1 or more elements, add the first element to the return of a recursive call to sumArr()
    # with modified array from index 1 to end
    # this recursively reduces the length of the passed array by 1 each time
    # continue until a base case applies
    # return nested results back up the chain of recursive calls
    else: 
        return arr[0] + sumArr(arr[1:])
# ----
# test
# ----

nums = []
print(str(sumArr(nums)))

nums = [1]
print(str(sumArr(nums)))

nums = [1, 2, 3]
print(str(sumArr(nums)))