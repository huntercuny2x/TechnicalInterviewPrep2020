class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> result;
        unordered_map<string, int> mp1;
        for(int i = 0; i < list1.size(); ++i) {
            mp1[list1[i]] = i;
        }
        
        int lowest = INT_MAX;
        for(int i = 0; i < list2.size(); ++i){
            if(mp1.find(list2[i]) != mp1.end()){
                mp1[list2[i]] += i;
                lowest = min(lowest, mp1[list2[i]]);
                cout << lowest << "\n";
            }
        }
        for(auto itr = mp1.begin(); itr != mp1.end(); ++itr){
            if(itr->second == lowest && find(list2.begin(), list2.end(), itr->first) != list2.end()){
                result.push_back(itr->first);
            }

        }        
        return result;
    }
};
