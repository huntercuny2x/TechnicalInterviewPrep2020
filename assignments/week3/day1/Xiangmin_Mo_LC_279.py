def numSquares(n):
  # Essentially go through every possible outcome, and it will eventually reach 0.
  # Got stuck on how to do it, so I searched it up.

  if n < 2:
    return n
  
  # get the possible square numbers
  squares = []
  i = 1
  while i * i <= n:
    squares.append(i * i)
    i += 1
  
  # 12 = [1,4,9]
  
  curr = {n}
  res = 0
  
  while curr:
    res += 1
    
    # sets have no duplicates
    
    temp = set()
    for i in curr:
      for j in squares:
        if i == j:
          return res
        if i < j:
          break
        temp.add(i-j)
    curr = temp
    
  return res

print(numSquares(12))