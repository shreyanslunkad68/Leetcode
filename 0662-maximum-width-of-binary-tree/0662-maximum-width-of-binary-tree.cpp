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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL) return 0;

        queue<pair<TreeNode*, unsigned long long>> q;
        q.push({root, 0});
        unsigned long long ans = 0;

        while(!q.empty()){
            int n = q.size();
            unsigned long long left = q.front().second;
            unsigned long long right = q.back().second;

            ans = max(ans, right - left + 1);

            while(n--){
                auto[node, index] = q.front();
                q.pop();

                if(node->left){
                    q.push({node->left, 2*index});
                }
                if(node->right){
                    q.push({node->right, 2*index+1});
                }
            }
        }
        return ans;
    }
};