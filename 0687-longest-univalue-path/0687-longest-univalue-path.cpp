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

    pair<int, int> dfs(TreeNode* root, int& answ) {
        if (!root) return make_pair(-1, 0);
        pair<int, int> l = dfs(root->left, answ);
        pair<int, int> r = dfs(root->right, answ);
    
        int currStreak = 0;
        if (l.first == root->val) {
            currStreak += l.second;
        }
        if (r.first == root->val) {
            currStreak += r.second;
        }
        answ = max(answ, currStreak);
        if (currStreak == 0) {
            return make_pair(root->val, 1);
        }
        else {
            return make_pair(root->val, max(r.second, l.second) + 1);
        }
    }
    int longestUnivaluePath(TreeNode* root) {
       	int answ = 0;
        dfs(root, answ);
        return answ;
    }
};