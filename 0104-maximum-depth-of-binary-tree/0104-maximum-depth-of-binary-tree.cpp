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
    int maxDepth(TreeNode* root) {
        int count = 0;        
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            count++;
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(!curr){
                    continue;
                }
                q.push(curr->left);
                q.push(curr->right);
            }
        }
        return count - 1;
    }
};