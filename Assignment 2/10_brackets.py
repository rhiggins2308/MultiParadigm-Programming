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
b7 = "((((((((((()))))))))))"
b8 = b7.split()

# # print(str(brackNest(b1)))
# # print(str(brackNest(b2)))
# # print(str(brackNest(b3)))

# print('Length: ', count_chars(b4))
# print(str(brackNest(b4)))
# # print(str(brackNest(b5)))
# # print(str(brackNest(b6)))
# # print(str(brackNest(b7)))


# for b in b8:
#     print(b, '\n')
print(b8[0])