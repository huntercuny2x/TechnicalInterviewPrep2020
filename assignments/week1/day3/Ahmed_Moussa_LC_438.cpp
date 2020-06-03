bool check(vector<int> &base, vector<int> &cur) {
    for(int i =0; i<26; i++) {
        if(base[i] != cur[i]) return false;
    }
    return true;
}

vector<int> findAnagrams(string s, string p) {
    if(p.size() > s.size()) return vector<int> ();
    vector<int> base(26), cur(26);
    for(char c: p) base[c-'a'] ++;
    int n = s.size();
    int i=0, st = 0;
    while(i < p.size()) {
        cur[s[i] - 'a'] ++;
        i++;
    }
    vector<int> ans;
    if(check(base, cur)) ans.push_back(st);
    for(; i<n; i++) {
        cur[s[i] - 'a'] ++;
        cur[s[st] - 'a'] --;
        st++;
        if(check(base, cur)) ans.push_back(st);
    }
    return ans;
}
