class Solution {
public:
    int jump(vector<int>& nums) {
        int step = 0;
        int ret = 0;
        if(nums.size()<=1){
            return 0;
        }
        while((step+nums[step]) < nums.size()-1){
            int m=0;
            int j =0;
            for(int i =0; i<=nums[step]; i++){
                if((nums[step+i]+i) > j){
                    j = nums[step+i]+i;
                    m =i;
                }
            }
            step+=m;
            ret++;
        }
        return ret+=1;

    }
};
