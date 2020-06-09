class Solution:
    def removeKdigits(self, num: str, k: int) -> str:
        # helper function to convert char to int and compare them
        def cmp(x, y):
            return int(x) < int(y)
        
        # we keep a stack that is nondecreasing
        stack = []
        i = 0
        while k > 0 and i < len(num):
            while k > 0 and stack and cmp(num[i], stack[-1]):
                stack.pop()
                k -= 1
            stack.append(num[i])
            i += 1
        
        while k > 0:
            # if we still have digits to remove:
            # our stack is nondecreasing, so popping the last digits
            # will result in the smallest possible number
            stack.pop()
            k -= 1
        
        # ignore leading zeros
        non_zero = 0
        while non_zero < len(stack) and stack[non_zero] == '0':
            non_zero += 1
            
        return ''.join(stack[non_zero:]) + num[i:] or "0"
