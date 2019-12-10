# Assignment 2 - Challenge 3
# Remove all odd numbers
# Given an array of numbers return an array with all the odd numbers removed
# ------------------------------------------------------------------------------------

def findOdd(arr):
    # Base case 1: if an empty array is passed, return an empty array
    if not arr:
        return []
    # if array contains data, check the first element using modulus 2
    if arr[0] % 2 == 1:
        # add element to array also containing results of recursive call to findOdd()
        # pass array with 1st element removed
        # continue until base case reached
        # return nested results back up the chain of recursive calls
        return [arr[0]] + findOdd(arr[1:])
    else:
        # if mod 2 == 0
        # do not add element to array and continue by making recursive call to findOdd()
        # pass array with 1st element removed
        # continue until base case reached
        # return nested results back up the chain of recursive calls
        return findOdd(arr[1:])

lst = [1, 2, 3, 4, 5, 6, 7, 8, 9] 
print(findOdd(lst))