/*
binary tree to linked list

*/
  void help(TreeNode* root,vector<int> &v){
			if(root == NULL) return;

			v.push_back(root -> val);
			help(root -> left,v);
			help(root -> right,v);
			
		}

	void flatten(TreeNode* root) {
		vector<int> v;
		help(root,v);
		int i = 1;
		int n = v.size();
		while(i < n){
			root -> left = NULL;
			root -> right = new TreeNode(v[i]);
			root = root -> right;
			i++;
		} 
