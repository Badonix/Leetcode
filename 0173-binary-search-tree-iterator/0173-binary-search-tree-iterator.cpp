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
class BSTIterator {
public:
    TreeNode* dummy;
    stack<TreeNode*> s;
    BSTIterator(TreeNode* root) {
        dummy = root;
        s.push(root);
        s.pop();
    }
    
    int next() {
        while(dummy){
            s.push(dummy);
            dummy = dummy->left;
        }        
        TreeNode* curr = s.top();
        s.pop();
        dummy = curr->right;
        return curr->val;
    }
    
    bool hasNext() {
        return s.size() > 0 || dummy;        
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */