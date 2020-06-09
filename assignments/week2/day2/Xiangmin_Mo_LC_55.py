# 55. Jump Game

# the values are the maximum length you can jump UP TO.
# You can jump from 1 to that length.
# my original thought process was to store all the possible indices that
# can be jumped to and then keep checking if the value will be greater than
# or equal to the last index, but I felt like that was too much to implement and would
# exceed the time limit.


def canJump(nums):
  maximum_index = 0
  for i, k in enumerate(nums):
    # if the maximum_index is less than the current index
    # that means we cannot jump any farther.
    if i > maximum_index:
      return False
    
    # we want the largest index that it can jump, so it compares itself to the
    # previous maximum index to the current index plus its jump range.
    maximum_index = max(maximum_index, i+k)

    # terminate if the maximum index you can reach at the current index is
    # greater than the last index.
    if maximum_index >= len(nums)-1:
      return True
  
  return True

print(canJump([2,3,1,1,4]))