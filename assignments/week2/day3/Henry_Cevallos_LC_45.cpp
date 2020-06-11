class Solution {
public:
    int jump(vector<int>& nums) {
        if(nums.size() == 1) return 0;   //edge gaurd
            
        int step = 0;
        for(int i = 0; i < nums.size() - 1;)    //loop through potential jumps
        {
            if(nums[i] == 0)    //0 means no possible jump
                break;
            
            
            int jump = 1;   //this is our min jump 
            int index_of_jump =  i + nums[i];   //this keeps track of the idex where we jump
            for(int j = i + nums[i]; j > i; j--)    //loop through potential jumps from i
            {
                if(j >= nums.size() - 1 )   //if the max jump will bring us to end
                    return ++step;  //return the step plus the one we just found
                
                if(jump < nums[j])  //if we found a better max jump
                {
                    jump = nums[j]; //set it to our jump
                    index_of_jump = j;  //get the index of the jump
                }
            }
            
            i = index_of_jump;  //move our position to the index of jump
            step++; //count the step we just took
        }
        
        return step;
    }
};