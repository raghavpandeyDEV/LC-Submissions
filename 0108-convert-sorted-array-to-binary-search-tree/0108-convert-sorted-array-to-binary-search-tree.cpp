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
    TreeNode*solve(int l , int r , vector<int>& nums){
        int n=nums.size();
        int mid=(l+r)/2;
       if(l>r)return NULL;

     TreeNode*root=new TreeNode(nums[mid]);
     root->left=solve(l,mid-1,nums);
     root->right=solve(mid+1,r,nums);
     return root;
    }

    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return solve(0,nums.size()-1,nums);
    }
};