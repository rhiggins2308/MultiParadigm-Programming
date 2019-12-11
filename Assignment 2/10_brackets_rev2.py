def check(string, bracks):
    # Base Case: where no elements/chars left in string
    if not string:
        # if no. open brackets matches no. close brackets
        # string is balanced
        if (bracks == 0):
            return True
        # if no. open brackets does not match no. close brackets
        # string is not balanced
        else:
            return False   
    # if first string element is (
    elif (string[0] == "("):
        # increment bracks and pass to recursive call
        # with string minus first element
        # continue recursion until Base Case reached
        # i.e. empty string passed to recursive call
        return check(string[1:], bracks+1)
    # if first string element is )
    elif (string[0] == ")"):
        # decrement bracks and pass to recursive call
        # with string minus first element
        # continue recursion until Base Case reached
        # i.e. empty string passed to recursive call
        return check(string[1:], bracks-1)
    # caters for any other char in the first string element
    else:
        # do not modify bracks and pass to recursive call
        # with string minus first element
        # continue recursion until Base Case reached
        # i.e. empty string passed to recursive call
        return check(string[1:], bracks)

# -----
# test
# -----

bracks = 0
string =""
print("Test 1:", string, check(string, bracks))

string ="))"
print("Test 2:", string, check(string, bracks))

string ="("
print("Test 3:", string, check(string, bracks))

string ="()"
print("Test 4:", string, check(string, bracks))

string ="())"
print("Test 5:", string, check(string, bracks))

string =")()(((())()))"
print("Test 6:", string, check(string, bracks))

string ="((((((((()))()))))))"
print("Test 7:", string, check(string, bracks))

string =")"
print("Test 8:", string, check(string, bracks))
print()
print("Done ...")
print("Noice!  Merry Christmas ....Time to GET SCHWIFTY!!")