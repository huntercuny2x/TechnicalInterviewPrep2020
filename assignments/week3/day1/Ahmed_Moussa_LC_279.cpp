int allPossibleCases(int n, vector<int> &perfectSquares, vector<int>& vis) {
    if(n == 0) return 0;
    if(vis[n] != -2)  return vis[n];
    int ans = -1;
    for(int x: perfectSquares) {
        if(x > n) break;
        int ret = allPossibleCases(n-x, perfectSquares, vis);
        if(ret != -1) {
            if(ans == -1) ans = ret + 1;
            else ans = min(ans, ret + 1);
        }
    }
    return vis[n] = ans;
}


int numSquares(int n) {
    int limit = sqrt(INT_MAX);
    vector<int> perfectSquares;
    for(int i = 1; i <= limit; i++) {
        perfectSquares.push_back(i*i);
    }
    vector<int> vis(n+1, -2);
    return allPossibleCases(n, perfectSquares, vis);
}
