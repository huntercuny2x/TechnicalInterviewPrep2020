//  Longest Substring Without Repeating Characters

int lengthOfLongestSubstring(string s) {
    int maxCount = 0;
    unordered_map<char, int> tracker;
    for(int i = 0, j = 0; j < s.size(); j++){
        if(tracker[s[j]] > 0) { // exists already
            i = max(tracker[s[j]], i); // take most recent location of repeated character
        }
        maxCount=max(maxCount, j-i+1);
        tracker[s[j]]=j+1;
    }
    return maxCount;
}

// Time Complexity: O(N)
// Space Complexity: O(N) - depends on size