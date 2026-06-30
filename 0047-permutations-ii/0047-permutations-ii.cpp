class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> answ;
        helper(nums, answ, 0);
        return answ;
    }
private:
    void helper(vector<int>& nums, vector<vector<int>>& answ, int index) {
        if (index == nums.size()) {
            answ.push_back(nums);
            return;
        }        
        unordered_set<int> seen;      
        for (int i = index; i < nums.size(); i++) {
            if (seen.count(nums[i])) {
                continue;
            }
            seen.insert(nums[i]);
            swap(nums[index], nums[i]);
            helper(nums, answ, index + 1);
            swap(nums[index], nums[i]);
        }
    }
};