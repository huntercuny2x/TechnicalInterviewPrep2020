
vector<string> findRepeatedDnaSequences(string s) {
    map<string, int> reps;
    for(int i=9; i<s.size(); i++) reps[s.substr(i-9,10)] += 1;
    vector<string> ans;
    for(auto ent: reps)
        if(ent.second > 1) ans.push_back(ent.first);
    return ans;
}
