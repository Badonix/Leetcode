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
    void dfs(TreeNode* root, int currNum, int& sum){
        if(!root) return;
        if(!(root->left) && !(root->right)){
            sum += currNum*10 + root->val;
            return;
        }
        dfs(root->left, currNum*10 + root->val, sum);
        dfs(root->right, currNum*10 + root->val, sum);
    }
    int sumNumbers(TreeNode* root) {
        int sum = 0;        
        dfs(root, 0, sum);
        return sum;
    }
};