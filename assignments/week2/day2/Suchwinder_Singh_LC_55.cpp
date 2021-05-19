// Jump Game

bool canJump(vector<int>& nums) {
    if(nums.size() == 1) return true;
    int gap = 1;
    for(int i = nums.size()-2; i >= 0; i--) {
        if(nums[i] >= gap) gap = 1;
        else if(nums[i] < gap) gap++;
    }
    return gap==1;
}