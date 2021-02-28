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

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    for(int i=0; i<matrix.size(); i++) {
        if(searchRow(matrix[i], target)) return true;
    }

    return false;
}
