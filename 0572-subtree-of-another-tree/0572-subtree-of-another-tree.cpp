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
    bool compareTrees(TreeNode* root1, TreeNode* root2){
        if(!root1 && !root2)
            return true;
        if((root1 && !root2) || (!root1 && root2) || root1->val != root2->val){
            return false;
        }
        return compareTrees(root1->left, root2->left) && compareTrees(root1->right, root2->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* c = q.front();
            q.pop();
            if(!c){
                continue;
            }
            if(c->val == subRoot->val){
                if(compareTrees(c, subRoot)){
                    return true;
                }
            }
            q.push(c->left);
            q.push(c->right);
        }        
        return false;
    }
};