vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) 
{
    unordered_map<string,int> m1;
    unordered_map<string,int> m2;
    vector<string> result;
    int count = 0; 
    int sum = 0;
    int minind = 9999;
    for(string i : list1)
    {
        m1.insert(make_pair(i,count));
        count++;
    } 
            
    for(int i = 0; i < list2.size(); i++)
    {
        if(m1.count(list2[i]) == 1)
        {
            sum = i + m1[list2[i]];
            if(sum < minind)
            {
                result.clear();
                result.push_back(list2[i]);
            }
            if(sum == minind)
            {
                    result.push_back(list2[i]);
            }
            minind = min(minind,sum);
        }
    }
    return result;
}

TreeNode* deleteNode(TreeNode* root, int key) 
{
    if(!root) 
    {
        return NULL;
    }
    
    if(key < root->val) 
    {
        root->left = deleteNode(root->left,key);
    }
    
    else if(key > root->val) 
    {
        root->right = deleteNode(root->right,key);
    }
    
    else
    {
        if(!root->left) 
        {
            root = root->right;
        }
        
        else if(!root->right) 
        {
            root = root->left;
        }
        
        else
        {
            TreeNode* temp = root->right;
            while(temp->left) temp = temp->left;
            temp->left = root->left->right;
            root->left->right = root->right;
            root = root->left;    
        }
    }
    return root;
}

