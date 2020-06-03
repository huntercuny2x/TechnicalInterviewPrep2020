class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        string builder = "";
        string longest;
        size_t pos;
        for (int i = 0; i < s.length(); i++){
            if (builder.find(s[i]) == -1){
                builder += s[i];
                if (builder.length() > longest.length()){
                    longest = builder;
                }
            }
            else{
                builder = "";
                i = s.rfind(s[i], i - 1);
            }
        }
        return longest.length();
    }
};