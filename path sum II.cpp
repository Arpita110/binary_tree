/*PATH SUM II
Input: root = [5,4,8,11,null,13,4,7,2,null,null,5,1], targetSum = 22
Output: [[5,4,11,2],[5,8,4,5]]
*/


 void dfs(TreeNode* root, vector<vector<int>>& res, vector<int>& temp, int targetSum)
     {
        if(!root) return;
        temp.push_back(root->val);
        if(!root->left && !root->right && targetSum == root->val)
            res.push_back(temp);
        dfs(root->left, res, temp, targetSum - root->val);
        dfs(root->right, res, temp, targetSum - root->val);
        temp.pop_back();
         
    }
    
     vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> temp;
        dfs(root, res, temp, targetSum);
        return res;
    }

