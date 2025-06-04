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
    int prev = -1;
    void dfs(TreeNode* root, int& answ){
        if(!root){
            return;
        }
        dfs(root->left, answ);
        if(prev != -1){
            answ = min(abs(root->val - prev), answ);
        }
        prev = root->val;
        dfs(root->right, answ);
    }
    int getMinimumDifference(TreeNode* root) {
        int answ = INT_MAX;    
        dfs(root, answ);
        return answ;
    }
};