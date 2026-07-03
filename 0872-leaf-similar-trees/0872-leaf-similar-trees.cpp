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
   bool isLeaf(TreeNode* node){
     
    if(node->left ==NULL && node->right==NULL)return true;
    return false;
   }
   
   void traverse(TreeNode*root , vector<int>&ans){
    if(root == NULL) return;
    if(isLeaf(root)){
        ans.push_back(root->val);
        return ;
    }
    traverse(root->left,ans);
    traverse(root->right,ans);
   }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        traverse(root1,arr1);
        vector<int>arr2;
        traverse(root2,arr2); 

        if(arr1.size()!=arr2.size())return false;

        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=arr2[i])return false;
        }
        return true;

    }
};