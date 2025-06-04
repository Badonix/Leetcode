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

    int answ = 0;
    int height(TreeNode* root, int currVal){
        if(!root){
            return currVal;
        }                
        return max(height(root->left, currVal + 1),height(root->right, currVal + 1));
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(!root){
            return 0;
        }
        int h = 0;
        int b = 0;
        answ = max(answ, height(root->left, 0) + height(root->right, 0));       
        diameterOfBinaryTree(root->left);
        diameterOfBinaryTree(root->right);
        return answ;
    }
};