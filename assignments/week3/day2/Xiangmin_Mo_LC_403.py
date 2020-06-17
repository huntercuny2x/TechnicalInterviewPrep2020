def canCross(stones):
    # get all possible jump amounts
    # (Initially, the frog is on the first stone and assume the first jump must be 1 unit.)
    # [step - 1, step, step + 1]
    # use set over list bc constant lookup
    
    # The first stone's position is always 0.
    #   -> thus we can return false if the first value is not equal to 1
    
    if stones[1] != 1:
      return False
    
    jumps = {}
    
    for i in stones:
      jumps[i] = set()
    
    jumps[1].add(1)
    
    for i in stones[1:-1]:
      # iterates through the dictionary to see the possible jumps that can be taken
      for j in jumps[i]:
        # calculates the jumpable positions and adds the number of jumps needed to the set of the destination
        # start from step - 1, then step, then step + 1
        for k in range(j-1,j+2):
          # cases where step - 1 becomes 0
          # also needs to check if the jumpable number is in the list of stones
          if (k > 0) and (i+k in jumps):
            jumps[i+k].add(k)
    
    print(jumps)

    # if there is a set in the last element of the list in the dictionary
    # return true because it indicates that there's at least a stone that can jump to it
    
    # else if there is an empty set then return false
    return jumps[stones[-1]] != set()
        
    
    # 0 : ()
    # 1 : (1) -> 1 -> range(0, 3) --> 0 1 2 --> 1 2 3*
    # 3 : (2) -> 2 -> range(1, 4) --> 1 2 3 --> 4 5* 6*
    # 5 : (2) -> 2 -> range(1, 4) --> 1 2 3 --> 6 7 8*
    # 6 : (3) -> 3 -> range(2, 5) --> 2 3 4 --> 8* 9 10
    # 8 : (3,2) -> 3 -> 2 3 4 -> 10 11 12*
    #           -> 2 -> 1 2 3 -> 9 10 11 none
    # 12 : (4) -> 3 4 5 -> 15 16 17*
    # 17 : (5)

print(canCross([0,1,3,5,6,8,12,17]))