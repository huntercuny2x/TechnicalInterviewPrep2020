class Solution:
    def longestPalindrome(self, s: str) -> str:
        n = len(s) + 1
        dp = [[True for x in range(n)] for x in range(n)]

        ans = [0,0]
        k = 1
        while k < len(s):
            for lo in range(len(s) - k):
                hi = lo + k
                if lo == hi + 1:
                    dp[lo][hi] = (s[lo] == s[hi])
                else:
                    dp[lo][hi] = (s[lo] == s[hi] and dp[lo+1][hi-1])

                if dp[lo][hi]:
                    ans[0], ans[1] = lo, hi
            k += 1

        return s[ans[0]:ans[1]+1]
