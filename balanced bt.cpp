/*
BALANCED BINARY TREE
Input: root = [3,9,20,null,null,15,7]
Output: true
*/

 int height(TreeNode* root){
        if(root==NULL) 
            return 0;
        return 1+max(height(root->left),height(root->right));
    }
    
    bool isBalanced(TreeNode* root) {
        if(root==NULL) 
            return true;
        if(abs(height(root->left) - height(root->right)) >1) 
            return false;
        return isBalanced(root->right) && isBalanced(root->left);
    }
};


