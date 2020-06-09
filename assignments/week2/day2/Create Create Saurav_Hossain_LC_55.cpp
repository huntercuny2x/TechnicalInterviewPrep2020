class Solution 
{
public:
    bool canJump(vector<int>& nums) 
    {
        
        //make the max jump unless its a 0, then make max - 1 until its 1 space hop 
        
        //covers if first element is huge and we can do big leap so we dont bother with algorithm 
        if(nums[0] >= nums.size()-1)
        {
            return true;
        }
        
        int i = 0;
        
        while(i < nums.size()-1)
        {
            //make biggest possible jump without hitting 0
            if(nums[i + nums[i]] != 0)
            {
                i = i + nums[i];
            }
            //make next biggest possible jump doing - 1 each time 
            for(int j = 1; j < nums[i]; j++)
            {
                if(nums[i + nums[i] - j] != 0)
                {
                    i = i + nums[i] - j;
                    break;
                }
            }
        }
        if(i >= nums.size()-1)
        {
            return true;
        }
        
        cout << i;
        return false;
    }
};
