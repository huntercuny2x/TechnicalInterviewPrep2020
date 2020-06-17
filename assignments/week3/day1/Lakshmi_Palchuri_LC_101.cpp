bool checkSame(TreeNode* root1, TreeNode* root2) 
{
    if( !root1 && !root2 )  
    {
        return true;
    }
    if( !root1 || !root2 )  
    {
        return false;
    }
    return (root1->val == root2->val && checkSame(root1->left, root2->right) && checkSame(root1->right, root2->left) );
}
bool isSymmetric(TreeNode* root) 
{
    return checkSame(root, root);
}
