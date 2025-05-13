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
    void dfs(TreeNode* root, int target, int curr, vector<int>& currVec, vector<vector<int>>& answ){
        if(!root){
            return;
        }
        currVec.push_back(root->val);
        if(curr+root->val == target && (!root->left && !root->right)){
            answ.push_back(currVec);
        }
        dfs(root->left, target, curr+root->val, currVec, answ);
        dfs(root->right, target, curr+root->val, currVec, answ);
        currVec.pop_back();
        return;
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> answ;
        vector<int> c;
        dfs(root, targetSum, 0, c, answ);        
        return answ;
    }
};