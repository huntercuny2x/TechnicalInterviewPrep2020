# 20. Valid Parentheses

def isValid(s):
  stack = []
  brackets = {'(':')', '[':']', '{':'}'}
  
  for i in s:
    if i in brackets:
      stack.append(i)
    else:
      # if the stack isnt empty
      # check to see if the last element in the stack's value in the dictionary is equal to the
      # value of the current position in the string
      if stack and brackets[stack[-1]] == i:
        stack.pop()
      else:
        return False
  
  # return type is a bool, so we know if it is valid once the stack is empty again
  return stack == []

print(isValid("()"))