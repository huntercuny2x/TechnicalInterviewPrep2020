class Solution:
    def minAddToMakeValid(self, S: str) -> int:
        s = []
        count = 0
        for char in S:
            if char == '(':
                s.append(char)
            else:
                if s:
                    s.pop()
                else:
                    count += 1
        
        return count + len(s)
