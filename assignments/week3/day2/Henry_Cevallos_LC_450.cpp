bool isLeaf(TreeNode *node)
{
    return (node->left == nullptr && node->right == nullptr);
}

//get the leftmost node
TreeNode *inorderSuccessor(TreeNode *node)
{
    while (node->left != nullptr) //go though all left nodes
    {
        node = node->left;
    }

    return node;
}

//find node that contains key
TreeNode *findNode(TreeNode *node, int key)
{
    while (node != nullptr && node->val != key) //look at all nodes
    {
        if (node->val < key) //if key is greater look at right tree
            node = node->right;

        else //if key is smaller look at left tree
            node = node->left;
    }
    return node;
}

void deleteNodeHelper(TreeNode *node)
{
    if (isLeaf(node)) //leaf node is easy delete
    {
        node = nullptr;
        delete node;
    }

    else if (node->left == nullptr) //if it has one child we just swap and delete
    {
        TreeNode *right_child = node->right;
        node = right_child;
        right_child = nullptr;
        delete right_child;
    }
    else if (node->right == nullptr) //if it has one child we just swap and delete
    {
        TreeNode *left_child = node->left;
        node = left_child;
        left_child = nullptr;
        delete left_child;
    }

    else //has to children
    {
        TreeNode *leftmost_node = inorderSuccessor(node->right); //get the leftmost node
        node->val = leftmost_node->val;                          //swap their values

        leftmost_node = nullptr; //delete the one we swapped
        delete leftmost_node;
    }
}

//Actual Function
TreeNode *deleteNode(TreeNode *root, int key)
{

    TreeNode *node_to_delete = findNode(root, key); //find the node to delete
    //cout << node_to_delete->val << endl;

    if (node_to_delete == nullptr) //not found key
        return root;

    deleteNodeHelper(node_to_delete); //delete the node
    return root;                      //return the root
}