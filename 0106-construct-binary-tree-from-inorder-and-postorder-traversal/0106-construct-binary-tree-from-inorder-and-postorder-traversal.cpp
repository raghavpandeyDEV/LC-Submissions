/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
     TreeNode*solve(vector<int>& postorder , int ps , int pe , vector<int>& inorder , int is , int ie ,unordered_map<int,int>&mpp){

    if(ps>pe || is>ie)return NULL;
    TreeNode*root=new TreeNode(postorder[pe]);

    int index=mpp[root->val];  // index in inorder

    int numsleft=index-is;

    root->left=solve(postorder , ps , ps+numsleft-1 ,inorder , is ,index-1,mpp);
    root->right=solve(postorder ,ps+numsleft  ,pe-1  ,inorder ,index+1,ie,mpp );
    return root;
   }
    
  
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
         unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return solve(postorder , 0 ,postorder.size()-1,inorder,0,inorder.size()-1,mpp);
    }
};