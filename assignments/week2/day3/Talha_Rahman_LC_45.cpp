#include <vector>

/**
 * nums = [2, 3, 1, 1, 4]
 * My logic was to try to go through each possible case from the start while
 * keeping some sort of count to see how many moves you've made.
 * So you can go to nums[1] or nums[2] from the start because nums[0] = 2. 
 * And then those positions can go to other positions and if at any point 
 * you get to the end then return the number of jumps we've made
 * However, I have no clue how to code this. I kept getting nested for loops
 * and couldn't exactly figure out how to backtrack? I am not even sure how to 
 * explain where my code was messing up. I checked the "Discuss" part on leetcode
 * and none of the solutions were making sense for me. I couldn't figure out how 
 * to always move to the best spot? 
 */
int jump(std::vector<int>& nums) {
    int jumps = 0, pos = 0, max_dist = nums[0];
    
    while (pos <= max_dist) {
        ++jumps;
        
        if (max_dist >= nums.size() - 1) return jumps;
        
        // for(; pos <= max_dist; ++pos) {
            
        // }
    }
    
    return jumps;
}