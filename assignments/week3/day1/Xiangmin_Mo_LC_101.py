# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
      res, curr = [], [root]

      while root and curr:
        vals = []
        
        for i in curr:
          if i:
            vals.append(i.left)
            vals.append(i.right)
          
        ptr1 = 0
        ptr2 = len(vals) - 1

        while ptr1 < ptr2:
          h, t = vals[ptr1], vals[ptr2]
          ptr1 += 1
          ptr2 -= 1
          
          # if they're both null
          if h == t and not h and not t:
            continue

          # if one of them is null of if the values are not equal, return false
          if None in (h,t) or h.val != t.val:
            return False

        curr = vals

      return True