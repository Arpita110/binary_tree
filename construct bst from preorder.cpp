/*
construct bst from preorder traversal
*/
TreeNode * solve(vector<int>&v,int& i,int bound)
    {
        if(i==v.size()||v[i]>bound)
            return NULL;
        TreeNode * temp = new TreeNode(v[i++]);
        temp->left= solve(v,i,temp->val);
        temp->right= solve(v,i,bound);
        return temp;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
       return  solve(preorder,i,INT_MAX);
    }
    
