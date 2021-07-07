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
    bool helper(TreeNode* left_node, TreeNode* right_node){
        if(left_node== nullptr || right_node == nullptr){
            if(left_node != right_node){
                return false;
            }
            return true;
        }
        else if(left_node->val != right_node->val){
            return false;
        }
        return helper(left_node->left, right_node->right) && helper(left_node->right, right_node->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(root == nullptr){
            return true;}
        return helper(root->left, root->right);
    }
};
