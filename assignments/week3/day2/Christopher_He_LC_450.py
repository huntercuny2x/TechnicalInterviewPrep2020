# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
        def successor(root):
            left = root.left
            while left.right:
                left = left.right
            return left.val

        def solution(root, key):
            if not root:
                return root

            if key < root.val:
                root.left = solution(root.left, key)
            elif root.val < key:
                root.right = solution(root.right, key)
            else:
                if not root.left and not root.right:
                    return None
                elif not root.left:
                    return root.right
                elif not root.right:
                    return root.left
                else:
                    # two children case
                    s = successor(root)
                    solution(root, s)
                    root.val = s

            return root

        return solution(root, key)
