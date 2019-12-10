# Assignment 2 - Challenge 5
# Replace a given character with '*' Given a string, and a character to replace,
# return a string where each occurance of the character is replaced with '*'
# ------------------------------------------------------------------------------------

def replaceChar(str, tok):
    # Base Case: when string argument is empty, return same
    if str == '':
        return ''
    # if first element of string argument matches the character specified to be altered
    # return '*' in place of that character concatenated with the result of recursive call, passing string argument with first character removed
    # continue until base case reached
    # return nested results back up the chain of recursive calls
    if str[0] == tok:
        return '*' + replaceChar(str[1:], tok)
    # if first element of string argument does not match the character specified to be altered
    # return str[0] unaltered, concatenated with the result of recursive call, passing string argument with first character removed
    # continue until base case reached
    # return nested results back up the chain of recursive calls
    else:
        return str[0] + replaceChar(str[1:], tok)

# -----
# test
# -----
print(replaceChar(input('Enter a string to modify: '), input('Enter a character to replace: ')))