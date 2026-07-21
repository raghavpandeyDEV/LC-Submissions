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
    void solve(TreeNode*root , int maxi , int&cnt){
        if(root==NULL)return ;

        if(root->val>=maxi)cnt++;
          solve(root->left , max(maxi,root->val) , cnt);
          solve(root->right , max(maxi,root->val) , cnt);
        

    }
    int goodNodes(TreeNode* root) {
        int cnt=0;
        solve(root,root->val,cnt);
        return cnt;

    }
};