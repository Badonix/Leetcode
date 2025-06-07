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
    void traverse(TreeNode* root, int& visited, int k, int& answ){
        if(!root || answ != -1) return;
        traverse(root->left, visited, k, answ);
        visited++;
        if(visited == k){
            answ = root->val;
            return;
        }
        traverse(root->right, visited, k, answ);
    }
    int kthSmallest(TreeNode* root, int k) {
        int answ = -1;
        int nodesVisited = 0;
        traverse(root, nodesVisited, k, answ);
        return answ;
    }
};