/*
Input: preorder = [3,9,20,15,7], inorder = [9,3,15,20,7]
Output: [3,9,20,null,null,15,7]
*/
 int preInd;
    map<int,int> m;
    TreeNode* build(vector<int> pre,int s,int e){
        if(s>e) return NULL;
        
        TreeNode* root = new TreeNode(pre[preInd]);
        int ind = m[pre[preInd]];
        preInd++;
        root->left = build(pre,s,ind-1);
        root->right = build(pre,ind+1,e);
        return root;
    }
    
    TreeNode* buildTree(vector<int>& pre, vector<int>& in) {
        preInd = 0;
        for(int i=0;i<in.size();i++) m[in[i]] = i;
        return build(pre,0,in.size()-1);
    }
