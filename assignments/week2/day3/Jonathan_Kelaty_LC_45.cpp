class Solution {
public:
    int jump(vector<int>& nums) {
        assert(nums.size() != 0);
        
        vector<int> jumps(nums.size(), INT_MAX);
        jumps[0] = 0;
        
        for (size_t i = 0; i < nums.size();) {
            size_t max_index = i;
            
            for (size_t j = 1; j <= nums[i]; ++j) {
                if (i + j >= nums.size()) {
                    break;
                }
                else {
                    jumps[i + j] = min(jumps[i + j], jumps[i] + 1);
                }
                
                if (nums[i + j] + i + j >= nums[max_index] + max_index) {
                    max_index = i + j;
                }
            }
            
            if (max_index == i) {
                ++i;
            }
            else {
                i = max_index;
            }
            
        }
        
        return jumps[nums.size() - 1];
    }
};