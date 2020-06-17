//I think that this should ork in most cases, but it gets stuck when the one you are removing is the root. However,
//I feel like this code should take that into account. I don't know where it gets stuck.

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
        //if the delete is the root
        //if the delete is a parent
        //if the delete is a leaf
        TreeNode * parent = nullptr;
        TreeNode * current = root;
        while(current != nullptr && current->val != key){
            parent = current;
            if(current->val > key){
                current = current->left;
            }
            else if (current->val < key){
                current = current->right;
            }
        }
        if(current == nullptr || current->val != key){ // it's not found in the tree
            return root;
        }
        //so at this point, current is the pointer to the value we want to delete and parent is the parent of that.
        //if current is a leaf, then just make the parent pointer to current null and return current;
        if(current->val == key && current->left == nullptr && current->right == nullptr){
            TreeNode * ret = current;
            if(parent != nullptr && parent->left == current){
                parent->left = nullptr;
            }
            else if (parent != nullptr && parent->right == current){
                parent->right = nullptr;
            }
            else{
                delete current;
                return nullptr;
            }
            return root;
        }
        //if current is a parent and has only one child
        else if(current->val == key && (current->right == nullptr && current->left != nullptr || current->right!= nullptr && current->left == nullptr)){
            TreeNode * ret = current;
            TreeNode * temp;
            if(parent->right == current){
                if(current->left != nullptr){
                    temp= current->left;
                    parent->right = temp;
                }
                else{
                    temp = current->right;
                    parent->right = temp;
                  }
                delete current;
            }

            else{
                if(current->left != nullptr){
                    temp = current->left;
                    parent->left = temp;
                }
                else{
                    temp = current->right;
                    parent->left = temp;
                }
                 delete current;
    }
                        return root;

            }
        //if current has two children, then set the node your deleting with the right most of the left tree and then delete
        TreeNode * temp = current->left;
        while(temp!=nullptr && temp->right != nullptr){
            temp = temp->right;
        }
        //temp is the node we want to get the value
        current->val = temp->val;
        if(current->left->val == temp->val){
            current->left = nullptr;
        }
        else{
            deleteNode(current->left, temp->val);
        }
        return root;
    }
};
