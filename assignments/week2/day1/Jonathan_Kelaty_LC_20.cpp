class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char, char> brackets = {
            { ')', '(' },
            { '}', '{' },
            { ']', '[' }
        };
        
        for (char c : s) {
            if (brackets.count(c)) {
                if (! st.empty() && st.top() == brackets[c]) {
                    st.pop();
                }
                else {
                    return false;
                }
            }
            else {
                st.push(c);
            }
        }
        
        if (st.empty()) {
            return true;
        }
        else {
            return false;
        }
    }
};