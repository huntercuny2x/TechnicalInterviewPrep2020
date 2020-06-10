class Solution {
public:
    bool wordPattern(string pattern, string str) {
        unordered_map<string, char> match_str;
        unordered_map<char, string> match_char;
        auto it = str.begin();
        
        for (char c : pattern) {
            if (it == str.end()) {
                return false;
            }
            
            size_t length = 0;
            
            while (it != str.end() && *it != ' ') {
                ++it;
                ++length;
            }
            
            string sub = str.substr(distance(str.begin(), it) - length, length);
            
            if (match_str.count(sub)) {
                if (c != match_str[sub]) {
                    return false;
                }
            }
            else if (match_char.count(c)) {
                if (sub != match_char[c]) {
                    return false;
                }
            }
            else {
                match_str[sub] = c;
                match_char[c] = sub;
            }
            
            if (it != str.end()) {
                ++it;
            }
        }
        
        if (it != str.end()) {
            return false;
        }
        
        return true;
    }
};