class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> substr;
        int length = 0;
        for (int i = 0, j = 0; j < s.size(); ++j) {
            if (substr.count(s[j])) {
                if (i <= substr[s[j]]) {
                    i = substr[s[j]] + 1;
                }
            }
            substr[s[j]] = j;
            length = max(length, j - i + 1);
        }
        return length;
    }
};