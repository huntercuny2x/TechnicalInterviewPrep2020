# 509. Fibonacci Number
# Tried using memoization

def fib(N):
  if N == 0:
    return 0
  if N == 1:
    return 1
  
  # checks to see if the values are in the memo dict
  # if it is, then we just get the values
  # --> less recursive calls
  if N-1 not in memo:
    memo[N-1] = fib(N-1)
  if N-2 not in memo:
    memo[N-2] = fib(N-2)
  
  return memo[N-1] + memo[N-2]

# memo dictionary, stores 0 and 1 with their values because they are the base cases
memo = {0:0, 1:1}
print(fib(4))