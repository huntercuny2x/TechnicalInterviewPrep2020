bool isSymmetric(TreeNode *root)
{

    if (root == nullptr)    //if root is null then no need to recurse
        return true;

    return symetricHelper(root->left, root->right);
}

bool symetricHelper(TreeNode *left, TreeNode *right)
{
    if (left == nullptr && right == nullptr)    //if they both reach end at same time
        return true;

    if (left == nullptr || right == nullptr)    //if one differs from the other
        return false;

    if (left->val != right->val)    //if they dont share share they same value
        return false;

    return symetricHelper(left->left, right->right) && symetricHelper(left->right, right->left); //check children
}