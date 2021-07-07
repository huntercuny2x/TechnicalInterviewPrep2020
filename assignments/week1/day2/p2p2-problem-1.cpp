// Problem: Replace Elements with Greatest Element on Right Side

vector<int> replaceElements(vector<int>& arr){ 
    int current_max = arr[arr.size()-1];
    arr[arr.size()-1] = -1;
    for(int i = arr.size()-2; i >= 0; i--){
        int temp = arr[i];
        arr[i]=current_max;
        if(current_max<temp){
            swap(temp, current_max);
        }
    }
    return arr;
}

// Time Complexity: O(N)
// Space Complexity: O(1)