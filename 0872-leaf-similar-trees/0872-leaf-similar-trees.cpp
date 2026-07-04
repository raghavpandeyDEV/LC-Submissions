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
   bool isLeaf(TreeNode*root){
    if(root->left==NULL && root->right==NULL)return true;
    return false;
   }

    void traverse(TreeNode*root , vector<int>&ans){
        if(!root)return;

        if(isLeaf(root)){
            ans.push_back(root->val);
            return;
        }
        traverse(root->left, ans);
        traverse(root->right,ans);
        
    }
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>nums1 ;
        vector<int>nums2 ;
        traverse(root1,nums1);
        traverse(root2,nums2);

        if(nums1.size()!=nums2.size())return false;
        
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]!=nums2[i])return false;
        }

  return true;
    }
};