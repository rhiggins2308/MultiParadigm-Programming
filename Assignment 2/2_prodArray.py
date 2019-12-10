# Assignment 2 - Challenge 2
# Product of an array
# Given an array of numbers return it’s product (all the numbers multiplied together)
# ------------------------------------------------------------------------------------

def prodArr(arr):
    # Base Case 1: check array length. If empty, return 0
    if (len(arr) == 0):
        return 0
    # Base Case 2: if first element in array argument is zero, then product will be zero irrespective of any further multiplication
    elif (arr[0] == 0):
        return 0
    # Base Case 3: check array length. If only 1 element, return it
    elif (len(arr) == 1):
        return arr[0]
    # If more than 1 element, multiply 1st elemwent by result of recursive call to prodArr()
    # with modified array from index 1 to end
    # this recursively reduces the length of the passed array by 1 each time
    # continue until a base case applies
    # return nested results back up the chain of recursove calls
    else: 
        return arr[0] * prodArr(arr[1:])

# ----
# test
# ----

nums = []
print(str(prodArr(nums)))

nums = [0]
print(str(prodArr(nums)))

nums = [1]
print(str(prodArr(nums)))

nums = [1, 2, 3]
print(str(prodArr(nums)))

nums = [1, 2, 3, 0]
print(str(prodArr(nums)))

nums = [1, 2, 0, 3]
print(str(prodArr(nums)))