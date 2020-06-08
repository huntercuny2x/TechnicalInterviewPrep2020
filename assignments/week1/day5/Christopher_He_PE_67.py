f = open('triangle.txt', 'r')
lines = f.readlines()

triangle = []
for line in lines:
    triangle.append([int(x) for x in line.split()])

# solution with memoization + recursion
def solution(level, node, memo):
    if level >= len(triangle):
        return 0

    if not (level, node) in memo:
        l = solution(level+1, node, memo)
        r = solution(level+1, node+1, memo)
        memo[level, node] = max(l, r) + triangle[level][node]

    return memo[level, node]

# solution with dynamic programming
def solution_with_dp(triangle):
    n = len(triangle)
    dp = [[0 for x in range(n)] for x in range(n)]
    i = len(triangle) - 1

    while i >= 0:
        for j in range(len(triangle[i])):
            if i == len(triangle) - 1:
                # base case
                dp[i][j] = triangle[i][j]
            else:
                # recursive step
                dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]) + triangle[i][j]
        i -= 1

    return dp[0][0]

print(solution_with_dp(triangle)) # 7273
print(solution(0, 0, {})) # 7273
