using SymmetricNodes = pair<TreeNode*, TreeNode*>;

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
    // Recursive solution
    bool isSymmetric(TreeNode* root) {
        if (root) {
            return symmetricHelper(root->left, root->right);
        }
        else {
            return true;
        }
    }
    
    // Recursive helper
    bool symmetricHelper(TreeNode* nodeA, TreeNode* nodeB) {
        if (nodeA && nodeB) {
            return
                (nodeA->val == nodeB->val) && 
                symmetricHelper(nodeA->left,  nodeB->right) && 
                symmetricHelper(nodeA->right, nodeB->left);
        }
        else if (nodeA || nodeB) {
            return false;
        }
        else {
            return true;
        }
    }

    // Iterative solution
    bool isSymmetricIterative(TreeNode* root) {
        queue<SymmetricNodes> q;
        
        if (root) {
            q.push(make_pair(root->left, root->right));
        }
        
        while ( ! q.empty() ) {
            SymmetricNodes& nodes = q.front();
            
            if (nodes.first && nodes.second) {
                if (nodes.first->val == nodes.second->val) {
                    q.push(make_pair(nodes.first->left, nodes.second->right));
                    q.push(make_pair(nodes.first->right, nodes.second->left));
                }
                else {
                    return false;
                }
            }
            else if (nodes.first || nodes.second) {
                return false;
            }
            
            q.pop();
        }
        
        return true;
    }
};