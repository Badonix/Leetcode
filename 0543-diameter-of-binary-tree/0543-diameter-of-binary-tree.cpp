class Solution {
public:
    int answ = 0;
    int height(TreeNode* root){
        if(!root){
            return 0;
        }
        int left = height(root->left);
        int right = height(root->right);
        answ = max(answ, left + right);
        return 1 + max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        height(root);
        return answ;
    }
};
