#include <vector>
#include <unordered_set>
#include <stack>

bool canCross(std::vector<int>& stones) {
    // check if any stone is impossible to get to 
    for(int i = 3; i < stones.size(); ++i) {
        if (stones[i] > stones[i - 1] * 2) return false;
    }
    
    std::unordered_set<int> set(stones.begin(), stones.end());
    std::stack<std::pair<int, int>> stk;
    stk.push({0, 0});
    
    while (!stk.empty()) {
        // stack contains a pair of the starting position, and the previous jump_dist taken
        int pos = stk.top().first;
        int k = stk.top().second;
        stk.pop();
        
        // try to move k - 1, k and k + 1 units
        for(int dist = k - 1; dist <= k + 1; ++dist) {
            // always move forward
            if (dist <= 0) continue;
            if (pos + dist == stones.back()) return true;
            
            if (set.count(pos + dist)) {
                // add any possible moves onto stack to be processed
                stk.push({pos + dist, dist});
            }
        }
    }
    return false;
}