int jump(vector<int>& nums) 
{
    int i = 0, jumps = 0, size = nums.size();
    if(size == 1) return 0;
    while(i < size) {
        if(i+nums[i] > size-2) return ++jumps; 
        int next = 0, maxDes = 0;
        for(int j = i+1; j <= i+nums[i]; ++j) {
            if(nums[j]+j > maxDes) 
                next = j, maxDes = nums[j]+j;
        }
        i = next; 
        jumps++;
    }
    return 0;
}