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
    vector<int> largestValues(TreeNode* root) {
        vector<int> answ;
        if(!root) return {};
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            int currentMax = INT_MIN;
            for(int i = 0; i < n; i++){
                TreeNode* curr = q.front();
                q.pop();
                if(curr->val > currentMax) currentMax = curr->val;
                if(curr->left) q.push(curr->left);                
                if(curr->right) q.push(curr->right);                
            }
            answ.push_back(currentMax);
        }
        return answ;
    }
};