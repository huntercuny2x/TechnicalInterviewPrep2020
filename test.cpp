#include <iostream>

// Structure of a tree node. 
struct Node { 
    int key; 
    Node *left, *right; 
}; 
  
// Function to create new tree node. 
Node* newNode(int key) 
{ 
    Node* temp = new Node; 
    temp->key = key; 
    temp->left = temp->right = NULL; 
    return temp; 
} 

int findLargestSubtreeSum(Node* root) {
    
}

int main() {
    /* 
               1 
             /   \ 
            /     \ 
          -2       3 
          / \     /  \ 
         /   \   /    \ 
        4     5 -6     2 
    */
    Node* root = newNode(1); 
    root->left = newNode(-2); 
    root->right = newNode(3); 
    root->left->left = newNode(4); 
    root->left->right = newNode(5); 
    root->right->left = newNode(-6); 
    root->right->right = newNode(2); 
  
    std::cout << findLargestSubtreeSum(root); 
}