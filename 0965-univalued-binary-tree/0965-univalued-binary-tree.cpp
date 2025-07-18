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
    bool dfs(TreeNode* root, int val){
        if(!root) return true;
        if(root->val != val) return false;
        if(!dfs(root->left, val) || !dfs(root->right, val)) return false;
        return true;
    }
    bool isUnivalTree(TreeNode* root) {
       if(!root || (!root->left && !(root->right))) return true;
       return dfs(root, root->val); 
    }
};