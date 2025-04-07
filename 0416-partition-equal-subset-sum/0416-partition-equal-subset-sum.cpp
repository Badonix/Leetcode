class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int curr : nums){
            sum += curr;
        }
        if(sum % 2 == 1){
            return false;
        }
        int target = sum / 2;
        return canSumUpToTarget(nums, target);
    }
    bool canSumUpToTarget(vector<int>& nums, int target){
       vector<bool> dp(target + 1, false);
       dp[0] = true;
       for(int n : nums){
        for(int i = target; i >= n; i--){
            dp[i] = dp[i] || dp[i-n];
        }
       } 
       return dp[target];
    }
};