/*
 Binary Tree Paths
Input: root = [1,2,3,null,5]
Output: ["1->2->5","1->3"]
*/

void printAllPath(TreeNode * root, string s, vector<string> &ans){
        if(root==NULL)
        {
            return;
        } 
        if(root->left==NULL && root->right==NULL)
        {
            s += to_string(root->val);
            ans.push_back(s);
            s="";
            return;
        }
        
        s += to_string(root->val) + "->";
        printAllPath(root->left, s, ans);
        printAllPath(root->right, s, ans);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        printAllPath(root, "", ans);
        return ans;
    }
