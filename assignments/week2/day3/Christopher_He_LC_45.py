class Solution:
    def jump(self, nums: List[int]) -> int:
        max_reach = cur_reach = 0
        i = jumps = 0
        
        while cur_reach < len(nums) - 1:
            max_reach = max(max_reach, i + nums[i])
            
            if i == cur_reach:
                jumps += 1
                cur_reach = max_reach
            
            i += 1
        
        return jumps
