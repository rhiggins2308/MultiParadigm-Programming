# Assignment 2 - Challenge 6
# Find index in array for item.
# Given an array, and an element to search for
# return the index of the element in the array or -1 if the element is not present in the array.

def findIndex(s, tok):
    # base case: where array argument is empty, return -1
    if (len(s) == 0):
        return -1
    # if last element in array matches search token, return element index
    elif (s[len(s)-1] == tok):
        return len(s)-1
    # if last element in array does not match search token
    # make recursive call, passing search token and array with last element removed
    # continue until base case reached
    # return nested results back up the chain of recursive calls
    else:
       return findIndex(s[:-1], tok)

# -----
# test
# -----

strNums = []
print(findIndex(strNums, 4))
strNums = [0]
print(findIndex(strNums, 4))
strNums = [4]
print(findIndex(strNums, 4))
strNums = [0, 1, 4]
print(findIndex(strNums, 4))
strNums = [0, 1, 5]
print(findIndex(strNums, 4))

strNums = [0, 1, 4, 9, 16, 25]
print(findIndex(strNums, 0))
print(findIndex(strNums, 1))
print(findIndex(strNums, 4))
print(findIndex(strNums, 9))
print(findIndex(strNums, 16))
print(findIndex(strNums, 25))
print(findIndex(strNums, 40))