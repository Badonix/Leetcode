class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long answ = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); i++){
            int minN = lower - nums[i];
            int maxN = upper - nums[i];
            auto higher = upper_bound(nums.begin() + 1 + i, nums.end(), maxN);
            auto lower = lower_bound(nums.begin() + 1 + i, nums.end(), minN);
            answ += (higher - lower);
        }
        return answ;
    }
};