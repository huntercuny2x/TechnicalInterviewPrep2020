#include <vector>
#include <algorithm>

/**
 * Using dynamic programming where we have a table of 
 * the minimum number of perfect squares that will get us any 
 * number. At the end of this the last spot will be
 * the minumum number of perfect squares to get n. 
 */
int numSquares(int n) {
    if (n < 1) return 0;
    
    std::vector<int> dp(n + 1, n);
    dp[0] = 0;
    
    // checking min for all numbers up to & including n
    for(int i = 1; i <= n; ++i) {
        // for each number we will figure out what is the least
        // number of perfect squares to get that specific number
        for(int j = 1; j * j <= i; ++j) {
            dp[i] = std::min(dp[i], dp[i - j * j] + 1);
        }
    }
    
    return dp[n];
}