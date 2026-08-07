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
    TreeNode* solve(int is , int ie , int ps , int pe ,vector<int>& preorder, vector<int>& inorder,unordered_map<int,int>&mpp){
        if(is>ie || ps>pe)return NULL;
        TreeNode*root=new TreeNode(preorder[ps]);
        int index=mpp[root->val];
        int numsLeft=index-is;

    root->left=solve(is,index-1, ps+1,ps+numsLeft, preorder,inorder ,mpp) ;
    root->right=solve(index+1,ie, ps+numsLeft+1,pe , preorder,inorder,mpp);
    return root;


    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int>mpp;
        for(int i=0 ;i<inorder.size();i++){
           mpp[inorder[i]]=i;
        }

        int n=preorder.size();
        return solve(0 , n-1 , 0 ,n-1, preorder,inorder,mpp);
    }
};