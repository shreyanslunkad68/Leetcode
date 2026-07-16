/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* f(TreeNode* root, int n1, int n2)
    {
        if(!root) return NULL;

        if(root->val == n1||root->val== n2) return root;

        TreeNode* left = f(root->left, n1, n2);
        TreeNode* right = f(root->right, n1, n2);

        if (left && right) return root;
        return (left!=NULL)?left:right;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return f(root, p->val, q->val);
    }
};