#include <unordered_set>

int lengthOfLongestSubstring(std::string s) {
    std::unordered_set<char> set;
    int longest = 0;
    // i is a pointer to the start of the substring
    // j is a pointer to the end of the substring
    int i = 0, j = 0;
    while (i < s.size()) {
        if (set.find(s[j]) != set.end()) {
            // if s[j] is found. Delete the previous elements from set
            set.erase(s[i]);
            ++i;
        } else {
            // if s[j] is not in the set. Insert element into set and move
            // j up, while updating the size of the longest to reflect the substring size
            set.insert(s[j]);
            ++j;
            longest = std::max(longest, j - i);
        }
    }
    return longest;
}