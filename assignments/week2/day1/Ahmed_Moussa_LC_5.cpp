string longestPalindrome(string s) {
    int ans = 0, n = s.size(), answerBegin = 0;
    for(int i=0; i<n; i++) {
        //assume middle char (Odd length Palindrome)
        int len = 1, leftPointer = i-1, rightPointer = i+1;
        while(leftPointer >= 0 && rightPointer < n && s[leftPointer] == s[rightPointer]) {
            len += 2; leftPointer --; rightPointer ++;
        }
        if(len > ans) {ans = len; answerBegin = leftPointer+1;}


        //assume left char (Even length Palindrome)
        len = 0, leftPointer = i, rightPointer = i+1;
        while(leftPointer >= 0 && rightPointer < n && s[leftPointer] == s[rightPointer]) {
            len += 2; leftPointer --; rightPointer ++;
        }
        if(len > ans) {ans = len; answerBegin = leftPointer+1;}
    }
    return s.substr(answerBegin, ans);
}
