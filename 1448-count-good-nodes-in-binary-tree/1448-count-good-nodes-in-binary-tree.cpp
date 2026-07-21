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
    void solve(TreeNode*root , int maxi , vector<int>&ans){
        if(root==NULL)return;

        if(root->val>=maxi)ans.push_back(root->val);
        solve(root->left , max(maxi,root->val) , ans);
        solve(root->right , max(maxi,root->val) , ans);

    }
    int goodNodes(TreeNode* root) {
        vector<int>ans;
        solve(root,root->val,ans);
        return ans.size();

    }
};