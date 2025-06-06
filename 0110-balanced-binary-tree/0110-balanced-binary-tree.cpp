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
    int height(TreeNode* root){
        if(!root) return true;
        int left = height(root->left);
        int right = height(root->right); 
        if(abs(left - right) > 1) return -1;
        if(left == -1 || right == -1) return -1;
        return max(left, right) + 1;
    }
    bool isBalanced(TreeNode* root) {
        int answ = height(root);
        return answ != -1;
    }
};