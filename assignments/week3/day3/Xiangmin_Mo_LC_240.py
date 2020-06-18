def searchMatrix(matrix, target):
  """
  :type matrix: List[List[int]]
  :type target: int
  :rtype: bool
  """
  
  # check if curr val is greater than the target
  # if not then go down
  # worst case is if the target is at the end of the row
  
  # original approach
  
#         i= 0
#         while i < len(matrix):
#           for j in matrix[i]:
#             if j > target:
#               break
      
#             if j == target:
#               return True
#           i += 1
#         return False
  
  
  # faster approach (ty discussion board)
  
  if not matrix or len(matrix) < 1 or len(matrix[0]) < 1:
    return False
  
  row = 0
  col = len(matrix[0]) - 1

  while row <= len(matrix)-1 and col >= 0:
    if target == matrix[row][col]:
      return True
    
    # if the target is higher than the last column of the current row,
    # we know that the previous elements are also less since it's sorted
    # so we move down
    elif target > matrix[row][col]:
      row += 1
      
    # keep moving left until we reach the target and if we dont,
    # then we break out of the loop
    else:
      col -= 1

  return False

print(searchMatrix([[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], 5))