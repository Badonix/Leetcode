/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    void dfs(TreeNode* root, queue<TreeNode*>& s) {
        if (!root)
            return;
        s.push(root);
        dfs(root->left, s);
        dfs(root->right, s);
    }
    void flatten(TreeNode* root) {
        if (!root)
            return;
        queue<TreeNode*> q;
        dfs(root, q);
        TreeNode* prev = q.front();
        q.pop();
        prev->left = nullptr;
        while (!q.empty()) {
            TreeNode* curr = q.front();
            q.pop();
            prev->right = curr;
            prev->left = nullptr;
            prev = curr;
        }
        prev->left = nullptr;
        prev->right = nullptr;
    }
};