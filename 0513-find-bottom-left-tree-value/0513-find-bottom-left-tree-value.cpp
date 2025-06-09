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
    int findBottomLeftValue(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int answ = root->val;
        while(!q.empty()){
            int n = q.size();
            vector<int> curr;
            for(int i = 0; i < n; i++){
                TreeNode* c = q.front();
                q.pop();
                curr.push_back(c->val);
                if(c->left)
                    q.push(c->left);
                if(c->right)
                    q.push(c->right);
            }
            answ = curr[0];
        }
        return answ;
    }
};