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
    void dfs(TreeNode* root, int minVal, int maxVal, int& answ){
        if(!root) return;
        int pos1 = abs(root->val - minVal);
        int pos2 = abs(root->val - maxVal);
        int pos = max(pos1, pos2);
        answ = max(answ, pos);
        dfs(root->left, min(minVal, root->val), max(maxVal, root->val), answ);
        dfs(root->right, min(minVal, root->val), max(maxVal, root->val), answ);
    }
    int maxAncestorDiff(TreeNode* root) {
       int answ = 0; 
       dfs(root, root->val, root->val, answ);
       return answ;
    }
};