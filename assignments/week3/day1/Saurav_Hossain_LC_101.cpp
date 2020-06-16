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
    
    bool swapChecker(TreeNode * rootLeft, TreeNode * rootRight)
    {
        //both null
        if(rootLeft == nullptr && rootRight == nullptr)
        {
            return true;
        }
        
        //1 nulls
        if(rootLeft == nullptr && rootRight != nullptr)
        {
            return false;
        }
        
        if(rootLeft != nullptr && rootRight == nullptr)
        {
            return false;
        }
        
        //values not same 
        if(rootLeft->val != rootRight->val)
        {
            return false;
        } 
        
        //are same check next kids
        else
        {
            return swapChecker(rootLeft->left, rootRight->right) && swapChecker(rootLeft->right, rootRight->left);
        }
        
    }
    
    bool isSymmetric(TreeNode* root) 
    {
        //starting from root check if left and right child are equal
            //if true check if left childs right is same as rights left & rights left is same as lefts right 
        //need to cover null
       
        //root null edge case
        if(root == nullptr)
        {
            return true;
        }
        
        //start left right checks
        else
        {
            return swapChecker(root->left, root->right);
        } 
        
    }
};
