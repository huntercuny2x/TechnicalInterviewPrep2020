class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {        
        unordered_set<string> res;
        unordered_set<string> seq;
        int index = 0, size = s.size();
        
        while(index + 9 < size){
            string substr = s.substr(index, 10);
            if(seq.find(substr) == seq.end()){
                seq.insert(substr);
            } else {
                res.insert(substr);
            }
            ++index;
        }
        return vector<string>(res.begin(), res.end());
    }
};
