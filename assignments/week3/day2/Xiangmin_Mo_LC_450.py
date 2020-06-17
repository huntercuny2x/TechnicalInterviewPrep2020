# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def deleteNode(self, root: TreeNode, key: int) -> TreeNode:
      # find the node first
      if not root:
        return root
      
      if key > root.val:
        root.right = self.deleteNode(root.right, key)
      
      elif key < root.val:
        root.left = self.deleteNode(root.left, key)
      
      else:
        if not root.right:
          return root.left
        if not root.left:
          return root.right
        

        # had to search this part up

        # if the node have both left and right children,  
        # we replace its value with the minimum value in the right subtree and then 
        # delete that minimum node in the right subtree
        temp = root.right
        mini = temp.val
        while temp.left:
          temp = temp.left
          mini = temp.val
        root.val = mini # replace value
        root.right = self.deleteNode(root.right, root.val) # delete the minimum node in right subtree
        
      return root
        
    