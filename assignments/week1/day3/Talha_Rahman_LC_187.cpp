#include <unordered_set>
#include <vector>

std::vector<std::string> findRepeatedDnaSequences(std::string s) {
    // sequences will hold all unique DNA Sequences of size 10
    // repeated will hold all unique DNA Sequences of size 10 that were repeated
    std::unordered_set<std::string> sequences, repeated;
    
    for(int i = 0; i < s.size(); ++i) {
        // tmp will represent the current DNA Sequence
        std::string tmp = "";
        if (i + 10 <= s.size()) {
            tmp = s.substr(i, 10);
        }
        
        // if this sequence was already in the sequences set add to repeated set
        if (sequences.find(tmp) != sequences.end()) {
            repeated.insert(tmp);
        }
        
        // only add sequences that are of size 10
        if (tmp.size() == 10) {
            sequences.insert(tmp);
        }
    }
    
    // return a new vector created from the repeated set
    return std::vector<std::string>(repeated.begin(), repeated.end());
}