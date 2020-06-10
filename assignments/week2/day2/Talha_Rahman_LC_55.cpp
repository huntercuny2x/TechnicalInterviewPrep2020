#include <vector>

/**
 * my approach is working backwords in the vector and seeing if I end up at the start.
 * I have an end position, which is the last element, create a regular position which is 
 * one less than that end position and then see if I can reach the end position with the 
 * number of jumps available (nums[pos]). If I can reach the end_pos then I move the end_pos
 * to the current position and then keep working down.
 */
bool canJump(std::vector<int>& nums) {
    int end_pos = nums.size() - 1;

    for(int pos = end_pos - 1; pos >= 0; --pos) {
        if (pos + nums[pos] >= end_pos) 
            end_pos = pos;
    }

    return end_pos == 0;
}