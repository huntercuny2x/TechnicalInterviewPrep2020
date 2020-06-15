bool check(TreeNode* a, TreeNode* b) {
    if(a == NULL && b == NULL) return true;
    if(a == NULL || b == NULL) return false;
    if(a->val != b->val) return false;
    return check(a->left, b->right) && check(a->right, b->left);
}

bool isSymmetric(TreeNode* root) {
    if(root == NULL) return true;
    return check(root->left, root->right);
}
