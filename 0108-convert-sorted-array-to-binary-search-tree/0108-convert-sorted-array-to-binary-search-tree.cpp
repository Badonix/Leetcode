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
    TreeNode* rec(vector<int>& nums, int left, int right){
        int currIndex = (left + right) / 2;
        TreeNode* curr = new TreeNode(nums[currIndex]);
        if(left == right - 1){
            curr->right = new TreeNode(nums[right]);
            return curr;
        }
        if(right <= left){
            return curr;
        }
        curr->left = rec(nums, left, currIndex - 1);
        curr->right = rec(nums, currIndex + 1, right);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* answ = rec(nums, 0, nums.size() - 1);
        return answ; 
    }
};