/*
Input: inorder = [9,3,15,20,7], postorder = [9,15,7,20,3]
Output: [3,9,20,null,null,15,7]
*/

 int index;
    map<int,int> m;
   TreeNode* solve(vector<int>& po,int start,int end)
   {
     if(start>end) 
         return NULL;
     int element=po[index];
     TreeNode* root=new TreeNode(element);
     index--;
     int posn=m[element];
   
     root->right=solve(po,posn+1,end); 
     root->left= solve(po,start,posn-1);  
     return root;
   }
  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        index=postorder.size()-1;
      int n=inorder.size();
     
      for(int i=0;i<n;i++)
      {
        m[inorder[i]]=i;
      }
     return solve(postorder,0,n-1);
      
    }
