class Solution {
public:
    vector<int> findAnagrams(string s, string p) {        
        vector<int> result, s_vec(26), p_vec(26);
        int p_size = p.size(), s_size = s.size();   
        if(p_size > s_size || !s_size)
            return result;
        
        for(int i = 0; i < p_size; i++){
            s_vec[s[i] - 'a']++;
            p_vec[p[i] - 'a']++;
        }
        if(s_vec == p_vec)
            result.push_back(0);
        for(int i = 1; i <= s_size - p_size; i++){
            s_vec[s[i - 1] - 'a']--;
            s_vec[s[i + p_size - 1] - 'a']++;
            if(s_vec == p_vec) 
                result.push_back(i);
        }

        return result;
    }
};
