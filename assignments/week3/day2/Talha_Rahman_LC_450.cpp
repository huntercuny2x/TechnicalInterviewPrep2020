// My approach is to just find the node in the binary tree
// then if it has only one child we can just return the other child
// and it will reconnect appropriately. However, if there is two
// children we must go down the right subtree and find the lowest num
// and replace that node with the original node we're trying to delete
// and delete the lowest node in the right subtree
TreeNode* deleteNode(TreeNode* root, int key) {
    if (!root) return root;
    
    if (root->val < key) {
        root->right = deleteNode(root->right, key);
    } else if (root->val > key) {
        root->left = deleteNode(root->left, key);
    } else {
        // has 1 Child
        if (!root->left) return root->right;
        if (!root->right) return root->left;
        
        // Has 2 Children
        auto tmp = root->right;
        
        // go as low as possible in the right subtree
        while (tmp->left) {
            tmp = tmp->left;
        }
        
        // swap the lowest num with the original root
        root->val = tmp->val;
        // delete the lowest num in the right subtree
        root->right = deleteNode(root->right, root->val);
    }
    
    return root;
}