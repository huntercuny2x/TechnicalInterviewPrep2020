class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> same, same2;
        vector<string> result;
        
        for (size_t i = 0; i < list1.size(); ++i) {
            same[list1[i]] = i;
        }
        
        for (size_t i = 0; i < list2.size(); ++i) {
            if (same.count(list2[i])) {
                same2[list2[i]] = i + same[list2[i]];
            }
        }
        
        int min = INT_MAX;
        
        for (const pair<string, int>& p : same2) {
            if (p.second < min) {
                min = p.second;
            }
        }
        
        for (const pair<string, int>& p : same2) {
            if (p.second == min) {
                result.push_back(p.first);
            }
        }
        
        return result;
    }
};