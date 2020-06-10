bool isValid(string s) {
    stack<char> st;
    for(char c: s) {
        if(c == '(' || c == '{' || c == '[') st.push(c);
        else{
            char top = st.empty() ? 'E' : st.top();
            if(c == ')') {                
                if(top != '(') return false;
                else st.pop();
            } else if(c == '}') {
                if(top != '{') return false;
                else st.pop();
            } else {
                if(top != '[') return false;
                else st.pop();
            }
        }
    }
    if(!st.empty()) return false;
    return true;
}
