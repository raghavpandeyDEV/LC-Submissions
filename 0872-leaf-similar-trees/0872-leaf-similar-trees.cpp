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
               if(isLeaf(node))ans.push_back(node->val);
                node=node->right;
            }
        }
        
    }

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int>arr1;
        inorder(root1,arr1);
        vector<int>arr2;
        inorder(root2,arr2); 

        if(arr1.size()!=arr2.size())return false;

        for(int i=0;i<arr1.size();i++){
            if(arr1[i]!=arr2[i])return false;
        }
        return true;

    }
};