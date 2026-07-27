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
   TreeNode*solve(vector<int>& preorder , int ps , int pe , vector<int>& inorder , int is , int ie ,unordered_map<int,int>&mpp){

    if(ps>pe || is>ie)return NULL;
    TreeNode*root=new TreeNode(preorder[ps]);
    int index=mpp[root->val];  // index in inorder
    int numsleft=index-is;
    root->left=solve(preorder , ps+1 , ps+numsleft ,inorder , is ,index-1,mpp);
    root->right=solve(preorder ,ps+numsleft+1  ,pe  ,inorder ,index+1,ie,mpp );
    return root;
   }
    
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0;i<inorder.size();i++){
            mpp[inorder[i]]=i;
        }
        return solve(preorder , 0 ,preorder.size()-1,inorder,0,inorder.size()-1,mpp);

    }
};