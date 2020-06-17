/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return nullptr;
        if(key < root->val) {
            root->left = deleteNode(root->left,key);
            return root;
        } else if(key == root->val) {
            if(root->left == nullptr and root->right == nullptr) {
                return nullptr;
            }
            if(root->left == nullptr and root->right != nullptr){
                TreeNode* temp = root->right;
                return temp;
            }
            if(root->right == nullptr and root->left != nullptr){
                TreeNode* temp = root->left;
                return temp;
            }
            TreeNode* replace = root->right;
            while(replace->left != nullptr)
                replace = replace->left;
            root->val = replace->val;
            root->right = deleteNode(root->right, replace->val);
            return root;
        } else {
            root->right = deleteNode(root->right, key);
            return root;
        }

    }
};
