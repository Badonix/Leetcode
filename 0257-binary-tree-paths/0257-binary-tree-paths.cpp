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
    void rec(TreeNode* root, string curr, vector<string>& answ){
        if(!root){
            return;
        }
        if(!(root->left) && !(root->right)){
            answ.push_back(curr + to_string(root->val));
            return;
        }
        curr += to_string(root->val);
        curr += "->";
        rec(root->left, curr, answ);
        rec(root->right, curr, answ);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
       vector<string> answ;
       rec(root, "", answ);
       return answ; 
    }
};