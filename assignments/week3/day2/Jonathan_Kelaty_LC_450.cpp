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
        if ( ! root ) {
            return root;
        }
        else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        }
        else if ( ! root->right ) {
            TreeNode* left = root->left;
            delete root;
            return left;
        }
        else if ( ! root->right ) {
            TreeNode* right = root->right;
            delete root;
            return right;
        }
        else {
            root->val = findSuccessorNode(root->right)->val;
            root->right = deleteNode(root->right, root->val);
        }
        
        return root;
    }
    
    TreeNode* findSuccessorNode(TreeNode* root) {
        if (root->left) {
            return findSuccessorNode(root->left);
        }
        return root;
    }
};