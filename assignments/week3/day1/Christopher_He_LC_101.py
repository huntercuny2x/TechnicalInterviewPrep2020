# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def palindrome(self, arr):
        lo, hi = 0, len(arr) - 1

        while lo < hi:
            if arr[lo] != arr[hi]:
                return False
            lo += 1
            hi -= 1

        return True

    def isSymmetric(self, root: TreeNode) -> bool:
        if not root:
            return True

        q = deque()
        q.append(root)

        while q:
            level = []
            empty_level = True
            for i in range(len(q)):
                node = q.popleft()
                if node:
                    empty_level = False

                q.append(node.left if node else None)
                q.append(node.right if node else None)
                level.append(node.val if node else None)

            if empty_level:
                break

            if not self.palindrome(level):
                return False

        return True

