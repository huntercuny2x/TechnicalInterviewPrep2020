# 1190. Reverse Substrings Between Each Pair of Parentheses
# Not the fastest solution -- Brute Force

def reverseParentheses(s):
  # one list to store the layered parenthesis
  # stack is used to go through the string
  reversed_letters, stack = [],[]

  for i in s:
    # indication that we reached the end of one parenthesis
    if i == ')':
      popped_letter = stack.pop()
      
      # keeps adding into the layered parenthesis array
      # because it's a stack, it's stored in reversed order
      while popped_letter != '(':
        reversed_letters.append(popped_letter)
        popped_letter = stack.pop()

      # adds the letters into the stack and then resets the reversed_letters array
      # in case there are more layered parentheses
      stack += reversed_letters
      reversed_letters = []
    
    else:
      stack.append(i)
  
  return ''.join(stack)

print(reverseParentheses("(abcd)"))