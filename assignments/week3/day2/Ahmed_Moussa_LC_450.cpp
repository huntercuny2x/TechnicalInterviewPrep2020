TreeNode* deleteNode(TreeNode* root, int key) {
    if(root == NULL) return NULL;
    if(root->val == key) {
        
        if(root->left == NULL) return root->right;
        if(root->right == NULL) return root->left;
        
        //Get Minimum Node in the right subTree
        //Then add root->left to the left of that node
        TreeNode* cur = root->right;
        while(cur->left != NULL) cur = cur->left;
        cur->left = root->left;
        return root->right;
    
    } else if(root->val < key) {
        root->right = deleteNode(root->right, key);
    } else {
        root->left = deleteNode(root->left, key);
    }
    return root;
}
