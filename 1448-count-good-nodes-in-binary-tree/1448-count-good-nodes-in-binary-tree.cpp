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
    void dfs(TreeNode* root, int currMax, int& answ){
        if(!root) return;
        if(root->val >= currMax){
            answ++;
        }
        dfs(root->left, max(currMax, root->val), answ);
        dfs(root->right, max(currMax, root->val), answ);
    }
    int goodNodes(TreeNode* root) {
        int answ = 0;
        dfs(root, root->val, answ);
        return answ;
    }
};