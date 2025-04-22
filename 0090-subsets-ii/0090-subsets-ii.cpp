class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> answ;
        vector<int> empty;
        dfs(0, nums, empty, answ);
        return answ;
    }
    void dfs(int start, vector<int>& nums, vector<int>& curr, vector<vector<int>>& answ) {
        answ.push_back(curr);
        for (int i = start; i < nums.size(); ++i) {
            if (i > start && nums[i] == nums[i - 1]) continue;
            curr.push_back(nums[i]);
            dfs(i + 1, nums, curr, answ);
            curr.pop_back();
        }
    }
};