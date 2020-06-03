// INCOMPLETE
// time out

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> returns;
        // vector<int> alph(26, 0);
        // vector<int> alphclone;
        string sbstr;
        sort(p.begin(), p.end());
        
        
        // for (int i = 0; i < p.length(); i++){
        //     alph[p[i] - 'a']++;
        // }
        
        if (p.length() > s.length()) return returns;

        
        for (int i = 0; i < s.length() - p.length() + 1; i++){
            // alphclone = alph;
            sbstr = s.substr(i, p.length());
            // for (int j = 0; j < p.length() && i + j < s.length(); j++){
            //     if (alphclone[s[i+j] - 'a'] < 1){
            //         alphclone.clear();
            //         break;
            //     }
            //     else{
            //         alphclone[s[i+j] - 'a']--;
            //     }
            //     if (j == p.length() - 1){
            //         alphclone.clear();
            //         returns.push_back(i);
            //     }
            // }
            if (sbstr == p) {
                returns.push_back(i);
            }
            else {
                sort(sbstr.begin(), sbstr.end());
                if (sbstr == p) returns.push_back(i);
            }
        }
        return returns;
    }
};