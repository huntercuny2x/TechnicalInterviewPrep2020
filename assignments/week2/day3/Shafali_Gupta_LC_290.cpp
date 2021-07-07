class Solution {
public:
    bool wordPattern(string pattern, string str) {
        map<char, string> mapping_pat;
        map<string, char> mapping_2;
        vector<string> words;
        int i =0;
        int ctr = 0;
        string word = "";
        while(i<str.length()){
            if(str[i] == ' '){
                words.push_back(word);
                ctr++;
                word = "";
            }
            else{
                word+= str[i];
            }
            i++;
        }
        words.push_back(word);
        if(words.size() != pattern.length()){
            return false;
        }
        for(int j =0; j<words.size(); j++){
            if(mapping_pat.find(pattern[j]) == mapping_pat.end()){
                mapping_pat[pattern[j]] = words[j];
            }
            // cout << mapping_pat.find(pattern[j]) ->second << ' ';
            // cout << arr[j] << '\n';
            else if(mapping_pat.find(pattern[j]) ->second != words[j]){
                return false;
            }
            if(mapping_2.find(words[j]) == mapping_2.end()){
                mapping_2[words[j]] = pattern[j];
            }
            else if(mapping_2.find(words[j]) ->second != pattern[j]){
                return false;
            }
        }
        return true;
    }
};
