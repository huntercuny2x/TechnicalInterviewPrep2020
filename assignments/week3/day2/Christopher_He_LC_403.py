class Solution:
    def canCross(self, stones):
        if stones[1] != 1:
            return False

        last_stone = stones[-1]
        stones = set(stones)

        def solution(pos, jump, memo):
            if (pos, jump) in memo:
                return memo[pos, jump]

            if pos == last_stone:
                return True

            can_jump = False
            for i in range(jump-1,jump+2):
                if i == 0:
                    continue
                if can_jump:
                    break
                if pos+i in stones:
                    can_jump = solution(pos+i, i, memo)

            memo[pos, jump] = can_jump
            return can_jump

        return solution(1, 1, {})
