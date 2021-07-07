class Solution:
    def numSquares(self, n: int) -> int:
	# solution with dynamic programming
        def solution_dp(n):
	    squares = []
	    i = 1
	    while i * i <= n:
		squares.append(i * i)
		i += 1

	    dp = [0] * (n+1)

	    for num in range(1, n+1):
		mymin = n - 1
		for sq in squares:
		    if num - sq < 0:
			break
		    mymin = min(mymin, dp[num - sq])
		dp[num] = mymin + 1

	    return dp[n]

        # solution with recursion + memoization
        def solution(n, memo):
            if n == 1:
                return 1

            if n < 1:
                return 0

            if n not in memo:
                i = 2
                mymin = n
                while i * i <= n:
                    mymin = min(mymin, solution(n - i * i, memo))
                    i += 1

                memo[n] = 1 + mymin

            return memo[n]

	return solution_dp(n)
        # return solution(n, {})
