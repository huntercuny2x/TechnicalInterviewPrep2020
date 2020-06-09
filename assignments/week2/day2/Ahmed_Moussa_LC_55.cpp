bool canJump(vector<int>& nums) {
    int vis = 0;
    queue<int> qu;
    qu.push(0);
    vis++;
    while(!qu.empty()) {
        int ind = qu.front(); qu.pop();
        int maxJump = min(ind+nums[ind], (int)nums.size()-1);
        if(maxJump == nums.size()-1) return true;
        for(; vis<=maxJump; vis++) qu.push(vis);
    }
    return false;
}
