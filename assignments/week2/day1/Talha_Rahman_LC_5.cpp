#include <iostream>
#include <vector>
using std::string;

/**
 * The brute force way is to just make all possible substrings and checking if they
 * are palindromes and store the largest one. However that has an extremely bad runtime.
 * My current algorithm was to go through the string s and for each character try to see if 
 * you can make a palindrome with the adjacent characters. For instance, if string s = "dabac"
 * and we're at character 'b' then it will check if the position before and after are the same 
 * character, if they are then this substring is a valid palindrome and it will expand one more layer
 * and then check if 'd' and 'c' are the same as well. And it would do this as you go through each char
 * but only does the check if s[i] - offset and s[i] + offset are both within the bounds of the string.
 * This however only works for palindromes of odd length. I couldn't figure out how to make 
 * this work for even length palindromes. I feel like there might be some dynamic programming technique
 * to make this work better but I spent most of my time on this solution and wasn't able to think of 
 * how to do a dynamic programming way
 */
string longestPalindrome(string s) {
    string longest = "";

    for(int i = 0; i < s.size(); ++i) {
        string current(1, s[i]);

        for(int offset = 1; (offset < s.size() - i && i - offset >= 0); ++offset) {
            if (s.at(i + offset) == s.at(i - offset)) {
                current = s[i - offset] + current + s[i + offset]; 
            } 
            else if (offset == 1 && (s.at(i + offset) == s[i] || s.at(i - offset) == s[i])) {
                current += s[i];
                break;
            }
        }
        if (current.size() > longest.size()) longest = current;
    }
    return longest;
}

int main() {
    string s = "bb";
    
    std::cout << longestPalindrome(s) << "\n";
}