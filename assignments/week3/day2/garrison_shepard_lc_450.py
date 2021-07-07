 def deleteNode(self, root, key):
        if root is None: 
            return root 
        if key < root.val: 
            root.left = deleteNode(root.left, key)
        elif key > root.val: 
            root.right = deleteNode(root.right, key)
        else: 
            if root.left is None : 
                temp = root.right  
                root = None 
                return temp  
            elif root.right is None : 
                temp = root.left  
                root = None
                return temp 
            current = root.right
            while(current.left is not None): 
                current = current.left 
                
            root.val = current.val
            root.right = deleteNode(root.right , current.val)  
        return root
   