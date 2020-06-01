//Cells With Odd Values In A Matrix
class Solution {
public:
    int oddCells(int n, int m, vector<vector<int>>& indices) {
        vector<vector<int>> matrix;
        for(int i=0; i<n; i++){
            vector<int> x;
            for(int y=0; y<m; y++){
                x.push_back(0);
            }
            matrix.push_back(x);
        }
        
        for(vector<int> i: indices){
            for(int& j: matrix[i[0]]){
                j++;
            }
            for(vector<int> &x: matrix){
                x[i[1]]++;
            }
        }
        
        int count = 0;
        for(vector<int> x: matrix){
            for(int& y: x){
                if(y%2!=0){
                    count++;
                }
            }
        }
        return count;
    }
};