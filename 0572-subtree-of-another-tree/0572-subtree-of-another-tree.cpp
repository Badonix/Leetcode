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
    bool isSame(TreeNode* a, TreeNode* b){
        if(!a && !b) return true;
        if(a && !b || !a && b) return false;
        if(a->val != b->val) return false;
        return isSame(a->left, b->left) && isSame(a->right, b->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       if(!root) return false;
       if(isSame(root, subRoot)) return true; 
       if(isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot)) return true;
       return false;
    }
};