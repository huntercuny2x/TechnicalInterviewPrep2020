class Solution {
public:
    int numSquares(int n) {
        vector<int> count{0};
        
        while (count.size() <= n) {
            int max = count.size(), squares = INT_MAX;
            for (int i = 1; (i * i) <= max; ++i) {
                squares = min(squares, count[max - (i * i)] + 1);
            }
            count.push_back(squares);
        }
        
        return count[n];
    }
};