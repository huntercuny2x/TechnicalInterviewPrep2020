#include <bits/stdc++.h>
using namespace std;

int getMaxSum(int row, int col, vector<vector<int> > & tree, vector<vector<int> > & dp) {
    if(row == tree.size()) return 0;

    if(dp[row][col] != -1) return dp[row][col];

    int ans = getMaxSum(row+1, col, tree, dp);
    ans = max(ans, getMaxSum(row+1, col+1, tree, dp));
    ans += tree[row][col];

    return dp[row][col] = ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    freopen("in.txt", "r", stdin);
    int n = 100;
    vector<vector<int> > tree(n), dp(n);
    for(int i=0; i<n; i++) {
        tree[i].resize(i+1);
        dp[i].resize(i+1);
        for(int j=0; j < i+1; j++) {
            cin >> tree[i][j];
            dp[i][j] = -1;
        }
    }
    cout << getMaxSum(0, 0, tree, dp);
    return 0;
}


//Answer:  7273
