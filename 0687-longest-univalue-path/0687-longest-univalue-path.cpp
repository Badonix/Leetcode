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
    int dfs(TreeNode* root, int& res, TreeNode* prev){
        if(!root) return 0;
        int left = dfs(root->left, res, root);  
        int right = dfs(root->right, res, root);  
        res = max(res, left+right);
        if(!prev) return 0;
        return root->val == prev->val ? 1 + max(left, right) : 0;
    }
    int longestUnivaluePath(TreeNode* root) {
        int res = 0;
        dfs(root, res, nullptr);        
        return res;
    }
};