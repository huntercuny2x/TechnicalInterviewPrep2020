class Solution {
public:
    bool canJump(vector<int>& nums) {
        vector<int> states(nums.size(), -1);
        int pos = nums.size() - 1;
        states[pos] = 1;
        
        for (int i = pos; i >= 0; --i) {
            if ((pos - i) <= nums[i]) {
                states[i] = 1;
                pos = i;
            }
            else {
                states[i] = 0;
            }
        }
        
        return states[0];
    }
};