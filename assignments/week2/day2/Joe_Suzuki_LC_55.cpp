class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0, size = nums.size();
        for(int i = 0; i <= reach; ++i){
            if(i == size - 1){
                return true;
            }
            reach = max(reach, i + nums[i]);
        }
        return false;
    }
};
