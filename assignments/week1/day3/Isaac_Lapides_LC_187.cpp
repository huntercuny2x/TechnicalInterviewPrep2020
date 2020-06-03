#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> returns;
        map<string, bool> dnamap;
        string dnasubstr;
        int vector_index = 0;
        if (s.length() < 10){
            return returns;
        }
        for (int i = 0; i < s.length() - 9; i++){
            dnasubstr = s.substr(i, 10);
            if (dnamap.find(dnasubstr) == dnamap.end()){
                dnamap.insert({dnasubstr, false});
            }
            else if(dnamap[dnasubstr] == false){
                dnamap[dnasubstr] = true;
                returns.push_back(dnasubstr);
            }
        }
            
        return returns;
    }
};