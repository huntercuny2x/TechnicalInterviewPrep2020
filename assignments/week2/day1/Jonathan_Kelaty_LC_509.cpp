class Solution {
public:
    int fib(int N) {
        if (N == 0) {
            return 0;
        }
        
        vector<int> nums(N + 1, 0);
        
        nums[0] = 0;
        nums[1] = 1;
        
        for (size_t i = 2; i <= N; ++i) {
            nums[i] = nums[i - 1] + nums[i - 2];
        }
        
        return nums[N];
    }
};