class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int count = 0;
        solve(nums, 0, target, count);
        return count;
    }
    void solve(vector<int>& nums, int currSum, int target, int& count){
        if(nums.size() == 0){
            if(currSum == target)
                count++;
            return;
        }
        int curr = nums[nums.size() - 1];
        nums.pop_back();
        solve(nums, currSum + curr, target, count);
        solve(nums, currSum - curr, target, count);
        nums.push_back(curr);
    }
};