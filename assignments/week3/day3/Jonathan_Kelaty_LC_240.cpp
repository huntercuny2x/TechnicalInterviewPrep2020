class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        
        vector<int> rows;
        int index = 0;
        
        for (vector<int>& row : matrix) {
            if (row[0] <= target && row[row.size() - 1] >= target) {
                rows.push_back(index);
            }
            else if (row[0] > target) {
                break;
            }
            ++index;
        }
        
        for (int row : rows) {
            int lo = 0, hi = matrix[row].size() - 1;
            
            while (lo < hi) {
                int mid = (lo + hi) / 2;
                if (matrix[row][mid] == target) {
                    return true;
                }
                else if (matrix[row][mid] < target) {
                    lo = mid + 1;
                }
                else {
                    hi = mid - 1;
                }
            }
            
            if (matrix[row][lo] == target) {
                return true;
            }
        }
        
        return false;
    }
};