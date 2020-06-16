/**
 * To check for symmetry we first check if left->val == right->val
 * and if either are null, then both must be to be symmetrical.
 * Afterwards we just call this recursively on the appropriate children
 */ 
bool symmetricHelper(TreeNode* left, TreeNode* right) {
    // if one node is empty, both have to be empty to be symmetrical
    if (!left || !right) return left == right;
    if (left->val != right->val) return false;
    
    return symmetricHelper(left->left, right->right) &&
            symmetricHelper(left->right, right->left);
}

bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    
    return symmetricHelper(root->left, root->right);
}

