int jump(vector<int>& nums) {
    int n = nums.size(), reached = 0;
    vector<int> level(n, -1);
    queue<int> qu; 
    qu.push(reached);
    level[reached] = 0;
    reached ++;
    while(!qu.empty()) {
        int cur = qu.front();  qu.pop();
        int maxJump = min(cur + nums[cur], n - 1);
        for(; reached <= maxJump; reached ++) {
            level[reached] = level[cur] + 1;
            qu.push(reached);
        }
    }
    return level[n-1];
}
