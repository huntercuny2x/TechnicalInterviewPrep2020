from collections import deque

class Solution:
    def reverseParentheses(self, s: str) -> str:
        def reverse(l, lo, hi):
            while lo < hi:
                l[lo], l[hi] = l[hi], l[lo]
                lo += 1
                hi -= 1

        stack = []
        q = deque()

        for i in range(len(s)):
            char = s[i]
            if char == '(':
                stack.append(i)
            elif char == ')':
                n = stack.pop()
                q.append((n, i))

        l = list(s)
        while q:
            start, end = q.popleft()
            reverse(l, start, end)

        return ''.join([x for x in l if x != ')' and x != '('])
