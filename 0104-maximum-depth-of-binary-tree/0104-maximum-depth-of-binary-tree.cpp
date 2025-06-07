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
    void dfs(TreeNode* root, int curr, int& answ){
        if(!root){
            answ = max(answ, curr);
            return;
        }
        dfs(root->left, curr+1, answ);
        dfs(root->right, curr+1, answ);
    }

    int maxDepth(TreeNode* root) {
        int answ= 0;
        dfs(root, 0, answ);
        return answ;
    }
};