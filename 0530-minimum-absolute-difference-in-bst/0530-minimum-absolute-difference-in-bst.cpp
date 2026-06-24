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
    void inorder(TreeNode* root , vector<int>&ans) {
        stack<TreeNode*>st;
       TreeNode*node=root;
        while(true){
            while(node){
                st.push(node);
                node=node->left;
            }
            if(st.empty())break;
            else{
                node=st.top();
                st.pop();
                ans.push_back(node->val);
                node=node->right;
            }
        }
      
    }
    int getMinimumDifference(TreeNode* root) {
        vector<int>ans;
        inorder(root,ans);

        int mini=INT_MAX;

        for(int i=1;i<ans.size();i++){
        
         mini=min(mini,ans[i]-ans[i-1]);

        }

        return mini;
    }
};