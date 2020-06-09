#921. Minimum Add to Make Parentheses Valid

def minAddToMakeValid(S):
  stack = []
  missingNums = 0
  
  for i in S:
    if i == '(':
      stack.append(i)
    else:
      if stack:
        stack.pop()
      else:
        missingNums += 1
  
  return len(stack) + missingNums

print(minAddToMakeValid('())'))