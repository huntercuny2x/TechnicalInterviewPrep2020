class Solution:
    def numSquares(self, n: int) -> int:
        def solution(n, memo):
            if n in memo:
                return memo[n]

            if n < 1:
                return 0

            # print(n)

            i = 1
            mymin = n
            while i * i <= n:
                mymin = min(mymin, solution(n - i * i, memo))
                i += 1

            memo[n] = 1 + mymin
            return 1 + mymin


        return solution(n, {})

s = Solution()
print(s.numSquares(10))
print(s.numSquares(12))
print(s.numSquares(13))
print(s.numSquares(64))
