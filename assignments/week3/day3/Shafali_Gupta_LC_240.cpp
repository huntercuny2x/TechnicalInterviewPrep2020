//my original solution (below the first one) had a runtime error, but i thought it would be less of a brute force way.
//I was trying to get to close to a binary search, but i'm not sure why it's giving a time limit exceeded error.

class Solution {
public:

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.empty()){
            return false;
        }
        int i = 0;
        int h = matrix[0].size() - 1;
        while(i < matrix.size() && h >= 0) {
          if(matrix[i][h] == target)
             return true;
          if(matrix[i][h] < target)
                 i++;
          else
            h--;
        }

        return false;
    }
};


class Solution {
public:
    bool search_helper(vector<vector<int>>& matrix, int start_row, int start_col, int target){
        if(start_row >=matrix.size() || start_row<0 || start_col >matrix[0].size()||
          start_col <0){
            return false;
        }
        if(target==matrix[start_row][start_col]){
            return true;
        }
        if(target>matrix[start_row][start_col]){
            if((start_row >=matrix.size() || start_row<0 || start_col >matrix[0].size()||
          start_col <0) && matrix[start_row+1][start_col]>matrix[start_row][start_col+1]){
                if((start_row >=matrix.size() || start_row<0 || start_col >matrix[0].size()||
          start_col <0) && target> matrix[start_row+1][start_col]){
                    return search_helper(matrix, start_row+1,start_col,target);
                }
                else{
                    return search_helper(matrix, start_row, start_col+1, target);
                }
            }
            else{
                if((start_row >=matrix.size() || start_row<0 || start_col >matrix[0].size()||
          start_col <0) &&target> matrix[start_row][start_col+1]){
                    return search_helper(matrix, start_row,start_col+1,target);
                }
                else{
                    return search_helper(matrix, start_row+1, start_col, target);
                }
            }
        }
         else if(target<matrix[start_row][start_col]){
            if((start_row >=matrix.size() || start_row<0 || start_col >matrix[0].size()||
          start_col <0) && matrix[start_row-1][start_col]<matrix[start_row][start_col-1]){
                if((start_row >=matrix.size() || start_row<0 || start_col >matrix[0].size()||
          start_col <0)&&target< matrix[start_row-1][start_col]){
                    return search_helper(matrix, start_row-1,start_col,target);
                }
                else{
                    return search_helper(matrix, start_row, start_col-1, target);
                }
            }
            else{
                if((start_row >=matrix.size() || start_row<0 || start_col >matrix[0].size()||
          start_col <0) && target< matrix[start_row][start_col-1]){
                    return search_helper(matrix, start_row,start_col-1,target);
                }
                else{
                    return search_helper(matrix, start_row-1, start_col, target);
                }
            }
        }

        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int start = matrix[0][0];
        int start_row = 0;
        int start_col = 0;
        if(target< start){
            return false;
        }
        else{
            return search_helper(matrix,start_row, start_col, target);
        }
    }
