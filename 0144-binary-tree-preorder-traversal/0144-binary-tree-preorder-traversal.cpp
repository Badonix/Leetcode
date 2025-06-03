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
    void rec(TreeNode* root, vector<int>& answ){
        if(!root){
            return;
        }
        answ.push_back(root->val);
        rec(root->left, answ);
        rec(root->right, answ);
    }
    vector<int> preorderTraversal(TreeNode* root) {
       vector<int> answ; 
       rec(root, answ);
       return answ;
    }
};