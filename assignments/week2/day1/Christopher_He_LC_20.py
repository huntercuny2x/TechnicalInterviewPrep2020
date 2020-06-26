class Solution:
    def isValid(self, s: str) -> bool:
        d = {
            ')': '(',
            '}': '{',
            ']': '[',
                }

        stack = []

        for char in s:
            if char in d:
                if not stack:
                    return False

                if stack[-1] == d[char]:
                    stack.pop()
                else:
                    return False
            else:
                # open
                stack.append(char)

        return len(stack) == 0

