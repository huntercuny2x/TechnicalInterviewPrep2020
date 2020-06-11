#include <string>
#include <unordered_map>
#include <unordered_set>
#include <sstream>
using std::string;
/**
 * my approach is to go through both the chars of the string pattern and 
 * each word in string str at the same time. Then I map each character in 
 * pattern to a word and add the word to a set. If I find a character already in the map, 
 * and the associated word is not being processed right now in str then we can return false.
 * Also we will return false if the character in pattern was not found but the 
 * word already exists inside of the set. Lastly we only return true if all 
 * characters in pattern and all words in str were processed.
 */
bool wordPattern(string pattern, string str) {
    std::unordered_map<char, string> char_map;
    std::unordered_set<string> word_set;
    std::istringstream ss(str);
    string word;
    int i = 0;
    
    while (ss >> word) {
        // return false if there are more words than chars in pattern
        if (i >= pattern.size()) return false;    
        
        if (char_map.find(pattern[i]) != char_map.end()) {
            // if map contains pattern[i] it must map to the word else false
            if (char_map[pattern[i]] != word) 
                return false;
        } else {
            // if map doesn't contain the current char, the word must have not been seen
            if (word_set.find(word) != word_set.end()) return false;
            char_map[pattern[i]] = word;
            word_set.insert(word);
        }
        ++i;
    }
    // if we've gone through all words and chars then this will be true
    return i == pattern.size();
}