/*
Input: root = [1,3,2,5,3,null,9]
Output: 4
Explanation: The maximum width exists in the third level with length 4 (5,3,null,9).
*/

 int widthOfBinaryTree(TreeNode* root) {
      if (root == NULL){
        return 0;
    }
    int ans = 0;
    queue<pair<TreeNode*, int>> q;   
    q.push({root, 0});
    
    while (!q.empty()){
        int size = q.size();
        int min_idx = q.front().second;
        int first, last;
        for (int i=0 ; i<size ; i++)
        {
            long curr_idx = q.front().second - min_idx;
            TreeNode *node = q.front().first;
            q.pop();
            if (i == 0) 
                first = curr_idx;
            if (i == size-1) 
                last = curr_idx;
            if (node->left != NULL)
            {
                q.push({node->left, (curr_idx*2)+1});
            }
            if (node->right != NULL)
            {
                q.push({node->right, (curr_idx*2)+2});
            }
        }
        ans = max(ans, last-first+1);
    }
    return ans;
    }
