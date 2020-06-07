
string reverseParentheses(string s) {
    string cur = "";
    vector<string> olderParts;
    for(char c: s) {
        if(c == '(') {
            olderParts.push_back(cur);
            cur = "";
        } else if (c == ')') {
            reverse(cur.begin(), cur.end());
            string old = "";
            if(olderParts.size() > 0) {
                old = olderParts.back();
                olderParts.pop_back();
            }
            cur = old + cur;
        } else cur += c;
    }
    if(olderParts.size() > 0) {
        cur = olderParts.back() + cur;
        olderParts.pop_back();
    }
    return cur;
}
