class Solution {
public:
    bool isValid(string s) {
        if(s.size() % 2 != 0) return false;
        
        stack<char> stk;
        for(char& ch: s){
            if(ch == ')'){
                if(stk.empty() || stk.top() != '(') return false;
                stk.pop();
            } else if(ch == ']'){
                if(stk.empty() || stk.top() != '[') return false;
                stk.pop();
            } else if(ch == '}'){
                if(stk.empty() || stk.top() != '{') return false;
                stk.pop();
            } else stk.push(ch);
        }
        return stk.empty();
    }
};
