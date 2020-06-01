//To Lower Case
class Solution {
public:
    string toLowerCase(string str) {
        for(char& c : str){
            (c>='A' && c<='Z') ? c=c+32 : NULL;
        }
        return str;
    }
};