# Fibonacci Number
class Solution:
    def fib(self, N: int) -> int:
        first = 0

        if N == 0:
            return first

        second = 1

        for i in range(2, N + 1):
            sum = first + second

            first = second
            second = sum

        return second
