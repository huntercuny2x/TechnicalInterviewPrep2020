def jump(nums):
    # I think my original approach for the first Jump Game question might be helpful
    # in tackling this question. We would have to store the possible jump locations
    # and then for each we see if it reaches the last index. However, this will be
    # time consuming as we would have to check recursively through every potential
    # outcome. Since we're doing it for every possible outcome, we need to compare
    # the previous min jump with the current number of jumps.