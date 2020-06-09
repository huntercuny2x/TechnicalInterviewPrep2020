class Solution {
public:
    int minAddToMakeValid(string S) {
        int add = 0, count = 0;
        
        for (char c : S) {
            if (c == '(') {
                ++count;
            }
            else if (count) {
                --count;
            }
            else {
                ++add;
            }
        }
        
        return add + count;
    }
};