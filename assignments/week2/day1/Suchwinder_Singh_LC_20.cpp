// Valid Parentheses

char checkClosing(char ch) {
    if(ch==')') return '(';
    if(ch=='}') return '{';
    if(ch==']') return '[';
    return 'x';
}

bool isValid(string s) {
    if(s.size()%2 != 0) return false; // if odd length, then something isn't paired 
    stack<char> tracker; // hold open parenthesis
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') tracker.push(s[i]);
        if(s[i] == ')' || s[i] == '}' || s[i] == ']') {
            if(!tracker.empty()) {
                if(tracker.top() != checkClosing(s[i])) return false;
                tracker.pop();
            }
            else return false;
        }
    }
    if(!tracker.empty()) return false;
    return true;
}
