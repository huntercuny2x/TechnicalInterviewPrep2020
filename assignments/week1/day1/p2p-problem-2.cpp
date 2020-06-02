#include <vector>
#include <iostream>
using std::vector;

int oddCells(int n, int m, vector<vector<int>>& indices) {
    int oddCount = 0;
    
    vector<vector<int>> matrix(n, vector<int>(m, 0));
    
    for(auto& ind : indices) {
        for(int i = 0; i < m; ++i) {
            ++matrix[ind[0]][i];
        }
        for(int i = 0; i < n; ++i) {
            ++matrix[i][ind[1]];
        }
    }
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            if (matrix[i][j] % 2 != 0) {
                ++oddCount;
            }
        }
    }
    
    return oddCount;
}

int main() {
    vector<vector<int>> vec {{0, 1}, {1, 1}};
    std::cout << oddCells(2, 3, vec) << "\n";
}