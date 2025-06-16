class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int answ = INT_MIN;
        int minSoFar = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if(nums[i] > minSoFar) answ = max(nums[i]-minSoFar, answ);
            minSoFar = min(minSoFar, nums[i]);
        }
        if (answ == INT_MIN)
            return -1;
        return answ;
    }
};