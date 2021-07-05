class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> sub;
        int length = 0, i = 0, j = 0, size = s.size();
        
        while(j < size){
            if(sub.find(s[j]) == sub.end()){
                sub.insert(s[j]);
                length = max(length, j - i + 1);
                j++;
            } else {
                sub.erase(s[i]);
                i++;
            }
        }
        return length;
    }
};
