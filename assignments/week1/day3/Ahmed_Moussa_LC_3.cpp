
int lengthOfLongestSubstring(string s) {
    int ans = 0;
    set<char> alp;
    queue<char> q;
    for(char c : s) {
        if(alp.count(c)) {
            while(q.front() != c) {
                alp.erase(q.front());
                q.pop();
            } 
            q.pop();
        }
        alp.insert(c);
        q.push(c);
        ans = max(ans, (int)q.size());
    }
    return ans;    
}
