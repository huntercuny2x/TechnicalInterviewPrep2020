class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        map<string,int> rests;
        for(int i =0; i<list1.size(); i++){
                rests[list1[i]] = i;
        }
        int min = INT_MAX;
        vector<string> min_string;
        for(int i =0; i<list2.size(); i++){
            if(rests.find(list2[i]) != rests.end()){
                if(rests[list2[i]] + i < min){
                    min = rests[list2[i]] + i;
                    min_string.clear();
                    min_string.push_back(list2[i]);
                }
                else if(rests[list2[i]] + i == min){
                    min_string.push_back(list2[i]);
                }
            }
        }
        return min_string;
    }
};
