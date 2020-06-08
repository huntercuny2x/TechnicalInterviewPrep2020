class Solution {
public:
    string longestPalindrome(string s) {        
        auto start = s.begin();
        size_t length = 0;
        
        for (auto it = s.begin(); it != s.end(); ++it) {
            auto next_it = next(it, 1);
            pair<string::iterator, size_t> new_string = palindromeHelper(s, it, make_reverse_iterator(next_it));
            
            if (new_string.second > length) {
                start  = new_string.first;
                length = new_string.second;
            }
            
            if (*it == *next_it) {
                new_string = palindromeHelper(s, next_it, make_reverse_iterator(next_it), 2);
                if (new_string.second > length) {
                    start  = new_string.first;
                    length = new_string.second;
                }
            }
            
            if (length == s.size()) {
                break;
            }
        }
        
        return s.substr(distance(s.begin(), start), length);
    }
    
    pair<string::iterator, size_t> palindromeHelper(string& s, string::iterator it1, string::reverse_iterator it2, size_t length = 1) {
        ++it1;
        ++it2;
        
        while (it1 != s.end() && it2 != s.rend()) {
            if (*it1 == *it2) {
                length += 2;
            }   
            else {
                break;
            }
            ++it1;
            ++it2;
        }
        
        advance(it1, -length);
        return {it1, length};
    }
};