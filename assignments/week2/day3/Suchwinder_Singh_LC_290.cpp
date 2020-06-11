bool wordPattern(string pattern, string str) {
    istringstream sentence(str);
    vector<string> test;
    string temp;
    while(sentence >> temp) {
        test.push_back(temp);
    }
    
    if (test.size()!=pattern.size()) return false;
    
    unordered_map<char, string> patternToString;
    unordered_map<string, char> stringToPattern;
    for(int i = 0; i < pattern.size(); i++) {
        if(patternToString.count(pattern[i])){ // if have key check if its value matches word in vector if not it means there is a different word
            if(patternToString[pattern[i]] != test[i] ) return false;
        }
        else patternToString[pattern[i]]=test[i];
        if(stringToPattern.count(test[i])){ // check if string is in the pattern, if so then check if the character its mapped to is the same as the pattern letter
            if(stringToPattern[test[i]] != pattern[i] ) return false;

        }
        else stringToPattern[test[i]]=pattern[i];

    }
    return true;
}