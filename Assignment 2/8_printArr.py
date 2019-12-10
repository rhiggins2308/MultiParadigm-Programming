# Assignment 2 - Challenge  8
# Print an array
# Given an array of integers print all the elements one per line.
# This is a little bit different as there is no need for a 'return' statement just to print and recurse.

def printStr(nums):
    # Base case: if nums is empty, print blank line to terminate
    if(len(nums) == 0):
        print()
    # if nums contains integers, print the first digit to screen and make recursive call
    # pass int array, with first element removed
    # continue until base case reached
    # return nested results back up the chain of recursive calls
    else:
        print(nums[0])
        printStr(nums[1:])

# -----
# test
# -----

print("Test 1:\n")
print("----------")
printStr([])
print("Test 2:\n")
print("----------")
printStr([0,1,2,3,4,5])