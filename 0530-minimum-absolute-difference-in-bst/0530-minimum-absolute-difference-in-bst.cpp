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
   
    int getMinimumDifference(TreeNode* root) {
        int mini=INT_MAX;
        int prev=1e9;
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

                mini=min(mini,abs(prev-node->val));
                prev=node->val;

                node=node->right;
            }
        }
        return mini;
    }
};