class Solution {
public:
    bool canJump(vector<int>& nums) {
        
        int s = (int)nums.size();
        if(s == 1)
            return true;
        
        int prev_pos = s-1;
        
        //bool isvalid[s];
        //isvalid[s-1] = true;
        
        for(int i = s-2; i >= 0; i--){
            if(i + nums[i] >= prev_pos)
                prev_pos = i;
                //isvalid[prev_pos] = true;
        }
        
        return (prev_pos == 0);
    }
};
