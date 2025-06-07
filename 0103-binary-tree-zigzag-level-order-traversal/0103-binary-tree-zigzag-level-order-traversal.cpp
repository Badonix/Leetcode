/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> answ;
        queue<TreeNode*> q;
        if (!root)
            return {};
        q.push(root);
        int level = 0;
        while (!q.empty()) {
            vector<int> v;
            int size = q.size();
            level++;
            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();
                v.push_back(curr->val);
                if (curr->left)
                    q.push(curr->left);
                if (curr->right)
                    q.push(curr->right);
            }
            if(level % 2 == 0){
               reverse(v.begin(), v.end()); 
            }
            answ.push_back(v);
        }
        return answ;
    }
};
