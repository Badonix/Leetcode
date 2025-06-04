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
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int answ = 0;
        while(!q.empty()){
            TreeNode* c = q.front();
            q.pop();
            if(!c){
                continue;
            }
            if(!(c->left) && !(c->right)){
                continue;
            }
            q.push(c->right);
            q.push(c->left);
            if(c->left && !(c->left->left) && !(c->left->right)){
                answ += c->left->val;
            }
        }                
        return answ;
    }
};