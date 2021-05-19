// Longest Palindromic Substring

// Couldn't Complete 100%

int checkFromCenter(string s, int begin, int end) {
    while (begin >= 0 && end < s.length() && s[begin] == s[end]) {
        begin--;
        end++;
    }
    return end - begin - 1;
}


string longestPalindrome(string s) {
    if(s.size()==0) return "";
    int begin = 0, end = 0;
    for (int i = 0; i < s.size(); i++) {
        int len1 = checkFromCenter(s, i, i); // for odd
        int len2 = checkFromCenter(s, i, i + 1); // for even
        int len = max(len1, len2); // take larger of two
        if (len > end - begin) { // not sure how this works entirely -sometime incorrect
            begin = i - (len - 1) / 2;
            end = i + len / 2;
        }
    }
    return s.substr(begin, end+1);
}
