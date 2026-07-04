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

    void solve(TreeNode*root ,string&temp ,vector<string>&ans){
        if(!root){
            temp.push_back('0');
            return;
        }
        if(isLeaf(root)){
            temp.push_back(root->val+'0');
            ans.push_back(temp);
            return ;
        }

        temp.push_back(root->val+'0');
        solve(root->left , temp ,ans);
         temp.pop_back();
        solve(root->right,temp,ans);
         temp.pop_back();
       

    }
    int sumNumbers(TreeNode* root) {
        string temp="";
        vector<string>ans;
        solve(root , temp ,ans);
       int sum=0;
        for(int i=0;i<ans.size();i++){
            sum+=stoi(ans[i]);
        }
        return sum;
    }
};