#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// This was my first attempt.
// It passes 34/36 of the cases on leetcode, but times out on extremely large strings
// the runtime of this is very bad because we're not only sorting once at the start
// which is n(logn), but sorting each time for each individual substring of s that's of size p
// im not perfectly
vector<int> findAnagrams1(string s, string p) {
    std::vector<int> indicies;

    // if you sort any two strings, they will be the same if they're anagrams
    // so I intended on sorting the p string here and then sorting the s substrings later
    sort(p.begin(), p.end());

    for(int i = 0; i < s.size(); ++i) {
        string tmp;
        if (i + p.size() <= s.size()) {
            tmp = s.substr(i, p.size());
            sort(tmp.begin(), tmp.end());
        }
        if (tmp == p) indicies.push_back(i);
    }
    
    return indicies; 
}

/**
 * I tried to create some sort of Hashmap, but with regular vectors
 * where I create a vector of size 26 and each index is going to represent
 * a character and the int value at the array index is going to be the count 
 * of that character.
 * I wanted to try doing something like, create a substring in string s
 * and then check if that substring is somehow inside of the char_countsP vector
 * however I was not entirely sure how to get it to work. I even looked up the 
 * sliding window technique and was not quite able to follow along with what was
 * going on. I feel if I spend another hour/half-hour on this I might be able to 
 * understand, but I was not able to submit it on time so I decided to just leave it here
 */ 

vector<int> findAnagrams2(string s, string p) {
    std::vector<int> indicies, char_countS(26, 0), char_countP(26, 0);
    
    // map all occurence for a char to the count
    // char_countP(a) will return the number of a's in p
    for(char& c : p) {
        ++char_countP[c - 'a'];
    }
    // same idea but with the chars in string s
    for(char& c : s) {
        ++char_countS[c - 'a'];
    }
    
    int length = p.size();

    for(int i = 0; i < s.size(); ++i) {
        string tmp;
        if (i + length <= s.size()) {
            tmp = s.substr(i, length);
        }

        for(char& c : s) {
            // do something to check if this substring is an anagram
        }

        indicies.push_back(i);
    }
    return indicies; 
}