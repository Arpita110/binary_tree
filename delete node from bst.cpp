/*
Input: root = [5,3,6,2,4,null,7], key = 3
Output: [5,4,6,2,null,null,7]
*/

int minVal(TreeNode *root)      {
        
        TreeNode *temp = root;
        while(temp->left !=NULL )
            temp = temp->left;
        return temp->val;
        
    }
    
    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
        if(root->val == key)    {
            
            //no child
            if(root->left == NULL && root->right == NULL)   {
                delete root;
                return NULL;
            }
            
            //1 child only : left child
            if(root->left != NULL && root->right == NULL)   {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            //1 child only : right child
            if(root->left == NULL && root->right !=NULL )   {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            
            //2 child
            if(root->left != NULL && root->right != NULL )  {
                int mini = minVal(root->right);         
                root->val = mini;                        
                root->right = deleteNode(root->right,mini); 
                return root;
            }          
        
        }
        
        if( root->val > key )   {
            root->left = deleteNode(root->left,key);
            return root;
        }
        else if(root->val < key )   {
            root->right = deleteNode(root->right,key);
            return root;
        }
        
        return root;
    }
