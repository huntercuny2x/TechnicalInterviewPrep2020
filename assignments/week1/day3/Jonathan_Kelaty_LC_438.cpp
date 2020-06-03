class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> indeces;
        unordered_map<char, size_t> m1, m2;
        
        for (size_t i = 0; i < p.size(); ++i) {
            m1[p[i]]++;
            m2[s[i]]++;
        }
        
        bool flag = true;
        for (const pair<char, size_t> & p : m1) {
            if (m2[p.first] != p.second) {
                flag = false;
                break;
            }
        }
        
        if (flag) {
            indeces.push_back(0);
        }
        
        for (size_t i = 0, j = p.size(); j < s.size(); ++i, ++j) {
            m2[s[i]]--;
            m2[s[j]]++;
            
            bool flag = true;
            for (const pair<char, size_t> & p : m1) {
                if (m2[p.first] != p.second) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                indeces.push_back(i + 1);
            }
        }
        
        return indeces;
    }
};