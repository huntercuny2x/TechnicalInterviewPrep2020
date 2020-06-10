#include <stack>
#include <string>
#include <vector>
#include <iostream>
using namespace std;

bool canJump(vector<int>& nums) {
    //O(N) time O(1) space approach
    int prev_jump = nums.size()-1; //we start our jump from the end index
    for (int pos = nums.size() - 1; pos >= 0; pos--) //loop backwards from end index, looking at jumps
    {
        //if given the position + max jump at position will reach our prev_jump position
        if (nums[pos] + pos >= prev_jump)
            prev_jump = pos; //set prev_jump to our pos
    }
    //our last jump should be the 0 index
    //This would show that there is ability to jump from 0 to end

    bool ans;
    prev_jump == 0 ? ans = true : ans = false;
    return ans;


    /*
    //O(N^2) time O(1) space approach
    if(nums.size() == 1) return true;   //edge gaurd
    int jump = 0;
    for(int i = 0; i < nums.size() - 1;)    //loop through potential jumps
    {
        if(nums[i] == 0)    //0 means no possible jump
            break;
            
        int max_jump = 0;
        for(int j = i + 1; j < nums.size() && j <= nums[i]; j++)//loop through possible jumps
        {
            max_jump = max(max_jump, nums[j]);//find largest jump
        }
            
        jump += max_jump;   //keep track of our jumps
        i += jump;  //move us along the array
            
        if(jump >= nums.size() - 1)//we reached a position that we can reach the end
            return true; 
            
    }
             
    return false;   //no valid jumps to end found
    */
}

int main()
{
    vector<int> nums {1, 2, 0, 4, 3};
    cout << canJump(nums) << endl;

}