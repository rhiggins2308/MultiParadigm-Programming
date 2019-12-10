# # Assignment 2 - Challenge  8 - DONE
# # Print an array
# # Given an array of integers print all the elements one per line.
# # This is a little bit different as there is no need for a 'return' statement just to print and recurse.

# # def printStr(text):
# #     if(len(text) == 0):
# #         print('End!')
# #     else:
# #         print(text[0])
# #         printStr(text[1:])


# # printStr([0,1,2,3,4,5])

# #---------------------------------------------------------------
# #---------------------------------------------------------------


# # Assignment 2 - Challenge 9
# # Find the minimum element in an array of integers.
# # You can carry some extra information through method arguments such as minimum value.

# # def findMin(n):
# #     if (len(n) == 0):
# #         return "Empty"
# #     elif len(n) == 1:
# #        return 0
# #     else:
# #        return min(n[0], findMin(n[1:]))

# # nums = [9,-3333333333333, -2,6,1,80,9,-2]
# # print(findMin(nums))

# #---------------------------------------------------------------
# #---------------------------------------------------------------


# # Assignment 2 - Challenge 10
# # Verify the parentheses
# # Given a string, return true if it is a nesting of zero or more pairs of parenthesis
# # like \(())" or \((()))".
# def count_chars(txt):
# 	result = 0
# 	for char in txt:
# 		result += 1     # same as result = result + 1
# 	return result

# def brackNest(s):
#     if (count_chars(s) == 0):
#         return True
#     elif (count_chars(s) % 2 == 1):
#         print('In Condition 2')
#         print(count_chars(s))
#         return False
#     else:
#         if (s[0] == '(' and s[count_chars(s)-1] == ')'):
#             print('In Condition 3A')
#             return brackNest(s[1:-1])
#         else:
#             print('In Condition 3B')
#             return False

# # b1 = []
# # b2 = ['(']
# # b3 = [')']
# b4 = ['()']
# # b5 = ['()(']
# # b6 = ['())']
b7 = ["((((((((((()))))))))))"]

# # print(str(brackNest(b1)))
# # print(str(brackNest(b2)))
# # print(str(brackNest(b3)))

# print('Length: ', count_chars(b4))
# print(str(brackNest(b4)))
# # print(str(brackNest(b5)))
# # print(str(brackNest(b6)))
# # print(str(brackNest(b7)))


for b in b7:
    print(b, '\n')