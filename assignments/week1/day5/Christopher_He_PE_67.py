f = open('triangle.txt', 'r')
lines = f.readlines()

triangle = []
for line in lines:
    triangle.append([int(x) for x in line.split()])

def solution(level, node, memo):
    if level >= len(triangle):
        return 0

    if not (level, node) in memo:
        l = solution(level+1, node, memo)
        r = solution(level+1, node+1, memo)
        memo[level, node] = max(l, r) + triangle[level][node]

    return memo[level, node]

print(solution(0, 0, {}))
