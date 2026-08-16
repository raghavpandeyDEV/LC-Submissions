class Solution {
public:

    bool solve(TreeNode* p, TreeNode* q) {

        if(p == NULL || q == NULL)
            return p == q;

        if(p->val != q->val)
            return false;

        return solve(p->left, q->left) &&
               solve(p->right, q->right);
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if(!root)
            return false;

        if(solve(root, subRoot))
            return true;

        return isSubtree(root->left, subRoot) ||
               isSubtree(root->right, subRoot);
    }
};