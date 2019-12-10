# Assignment 2 - Challenge 7
# Sum of Digits
# Given a whole number such as 23, return the sum of the digits in the number
# i.e. 2 + 3 = 5.
# For this would be useful to convert the number to a string then break it apart into digits.

def sumDigits(n):
    # base case: when no more digits left, return zero with no recursive call
    if (len(n) == 0):
        return 0
    # if n contains digits, add the first digit to the result of make recursive call
    # pass specified number, with first digit removed
    # continue until base case reached
    # return nested results back up the chain of recursive calls
    else:
        return int(n[0]) + sumDigits(n[1:])


# -----
# test
# -----

print(sumDigits(input('Enter an integer value: ')))