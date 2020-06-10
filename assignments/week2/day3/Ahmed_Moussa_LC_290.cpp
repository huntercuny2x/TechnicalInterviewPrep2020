vector<string> splitString(string x) {
    vector<string> splitted;
    string cur = "";
    for(char c: x) {
        if(c == ' ') {
            splitted.push_back(cur);
            cur = "";
        } else cur += c;
    }
    splitted.push_back(cur);
    return splitted;
}

bool wordPattern(string pattern, string str) {
    vector<string> splitted = splitString(str);
    if(splitted.size() != pattern.size()) return false;
    vector<string> mapper(26, "");
    for(int i=0; i<pattern.size(); i++) {
        int ind = pattern[i] - 'a';
        if(mapper[ind] == "") mapper[ind] = splitted[i];
        else if(mapper[ind] != splitted[i]) return false;
    }


    map<string, char> strmap;
    for(int i=0; i<splitted.size(); i++) {
        if(!strmap.count(splitted[i])) strmap[splitted[i]] = pattern[i];
        else if(strmap[splitted[i]] != pattern[i]) return false;
    }

    return true;   
}
