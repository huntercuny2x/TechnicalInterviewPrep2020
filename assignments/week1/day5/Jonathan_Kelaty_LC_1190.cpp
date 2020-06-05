class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> st1, st2;
        bool flag = true;
        
        for (char c : s) {
            if (c == '(') {
                flag = ! flag;
            }
            
            if (c == ')') {
                flag = ! flag;
                if (flag) {
                    while ( ! st1.empty() && st1.top() != '(') {
                        st2.push(st1.top());
                        st1.pop();
                    }
                    if ( ! st1.empty() ) {
                        st1.pop();
                    }
                }
                else {
                    while ( ! st2.empty() && st2.top() != '(') {
                        st1.push(st2.top());
                        st2.pop();
                    }
                    if ( ! st2.empty() ) {
                        st2.pop();
                    }
                }
            }
            else if (flag) {
                st2.push(c);
            }
            else {
                st1.push(c);
            }
        }
         
        string result;
        while ( ! st2.empty() ) {
            if (st2.top() != '(') {
                st1.push(st2.top());
            }
            st2.pop();
        }
        while ( ! st1.empty() ) {
            if (st1.top() != '(') {
                result.push_back(st1.top());
            }
            st1.pop();
        }
        
        return result;
    }
};