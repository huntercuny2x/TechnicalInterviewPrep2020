class Solution:
    def canJump(self, nums: List[int]) -> bool:
        target = len(nums) - 1
        i = target - 1
        while i >= 0:
            max_jump = nums[i]
            if i + max_jump >= target:
                target = i
            i -= 1
        
        return target == 0
