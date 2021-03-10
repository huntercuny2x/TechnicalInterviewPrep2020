# Find the maximum total from top to bottom in triangle.txt
# Assume that it is a list of list of integers
# INCORRECT ANSWER
# Probably brute forced this and misunderstood the question
# I get 6580

with open('p067_triangle.txt') as f:
  levels = f.readlines() # or list(f)

triangle = []
for i in levels:
  triangle.append([int(val) for val in i.split()])

def maxPathSum(triangle):
  path_sum = triangle[0][0]
  start_index = 0

  # we are comparing only two numbers:
  # 1. the number at the index of the previous index
  # 2. the number at the index of the previous index plus one
  # these are considered "adjacent numbers on the row below"
  # for example: 2 4 6
  #             8 5 9 3
  # 2 and 4 will first be compared, and then 5 and 9 will be compared since 4 > 2.
  for i in range(1, len(triangle)):
    max_of_two_adj = max(triangle[i][start_index], triangle[i][start_index + 1])
    
    path_sum += max_of_two_adj

    # updates the start index by searching for the index of the maximum adj number
    # in the row from position [index of max num in row] to that plus two because
    # the stop param of splicing is always that minus 1.
    # also necessary to include start and stop because there are repeated numbers,
    # and the index function will return the index of the first instance it sees.
    start_index = triangle[i].index(max_of_two_adj, start_index, start_index + 2)

  return path_sum

print(maxPathSum(triangle))