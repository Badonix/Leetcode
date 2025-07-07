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
    void dfs(TreeNode* root, int currLevel, int& maxLevel, vector<int>& answ){
        if(!root) return;
        if(currLevel > maxLevel){
            maxLevel = currLevel;
            answ.push_back(root->val);
        }
        dfs(root->right, currLevel+1, maxLevel, answ);
        dfs(root->left, currLevel+1, maxLevel, answ);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> answ;
        int maxLevel = INT_MIN;
        dfs(root, 0, maxLevel, answ);
        return answ;
    }
};