class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int m = 0;
        for(int n : nums){
            if(n > m){
                m = n;
            }
        }
        long long count = 0;
        int maxCount = 0;
        int left = 0;
        
        for(int right = 0; right < nums.size(); ++right){
            if(nums[right] == m){
                maxCount++;
            }
            while (maxCount >= k) {
                count += nums.size() - right;
                if (nums[left] == m) {
                    maxCount--;
                }
                left++;
            }
        }
        return count;
    }
};