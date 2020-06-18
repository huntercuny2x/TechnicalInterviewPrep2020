#include <vector>
using std::vector;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int row_size = matrix.size(), col_size = matrix[0].size();
    
    int row = 0, col = col_size - 1;
    while (row < row_size && col >= 0) {
        if (matrix[row][col] == target)
            return true;
        else if (matrix[row][col] < target) 
            ++row;  // we can ignore this whole row if target is greater than it
        else 
            --col;  // we can ignore this whole col if target is less than it                       
    }
    
    return false;
}