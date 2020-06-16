vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
    unordered_map<string, int> rep; 
    int i = 1;
    for(auto st: list1) {
        rep[st] = i++;
    }
    i = 1;
    int cur = INT_MAX;
    vector<string> ans;
    for(auto st: list2) {
        if(rep.count(st)) {
            int sum = rep[st] + i;
            if(sum < cur) {
                cur = sum;
                ans.clear();
                ans.push_back(st);                    
            } else if (sum == cur) ans.push_back(st);
        }
        i++;
    }
    return ans;
}
