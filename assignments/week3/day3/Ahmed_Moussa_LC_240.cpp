bool searchRow(vector<int>& matrix, int target) {
    int l=0, r=matrix.size()-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(matrix[mid] == target) return true;
        if(matrix[mid] < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

bool searchCol(int col, vector<vector<int>>& matrix, int target) {
    int l=0, r=matrix.size()-1;
    while(l <= r){
        int mid = (l+r)/2;
        if(matrix[mid][col] == target) return true;
        if(matrix[mid][col] < target) l = mid + 1;
        else r = mid - 1;
    }
    return false;
}

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if(matrix.size() == 0 || matrix[0].size() == 0) return false;

    for(int i=0; i<matrix.size(); i++) {
        if(searchRow(matrix[i], target)) return true;
    }

   for(int i=0; i<matrix[0].size(); i++) {
        if(searchCol(i, matrix, target)) return true;
    }

    return false;
}
