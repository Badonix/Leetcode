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
    int dfs(TreeNode* root, vector<int>& v){
        if(!root) return 0;
        int sum = root->val + dfs(root->left, v) + dfs(root->right, v);
        if(!(root->right) && !(root->left)){
            v.push_back(root->val);
            return root->val;
        }
        v.push_back(sum);
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        vector<int> sum;
        dfs(root, sum);
        map<int, int> m;
        for(int n : sum){
            m[n]++;
        }
        int mostFrequentCount = 0;
        for(pair<int, int> p : m){
            if(p.second > mostFrequentCount){
                mostFrequentCount = p.second;
            }
        }
        vector<int> answ;
        for(pair<int, int> p : m){
            if(p.second == mostFrequentCount){
                answ.push_back(p.first);
            }
        }
        return answ;
    }
};