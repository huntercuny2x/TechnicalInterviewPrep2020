# The prime factors of 13195 are 5, 7, 13 and 29.
# What is the largest prime factor of the number 600851475143?
# ANS : 6857

def largestPrimeFactor(num):
  # in case the input is negative or 1
  # 1 is not a prime number and dividing by one will cause
  # the loop to run infinitely
  if num <= 1:
    return

  start_value = 2

  # ex: 36
  # s=2, 2*2 <= 36 yes : 18 -> 9
  # s=3, 3*3 <= 9 yes : 3 -> 1
  # s=4, 4*4 <= 1 no. break
  while start_value ** 2 <= num:
    if num % start_value > 0:
      start_value += 1
    else:
      num /= start_value
  
  return(num)
  
print(largestPrimeFactor(600851475143))