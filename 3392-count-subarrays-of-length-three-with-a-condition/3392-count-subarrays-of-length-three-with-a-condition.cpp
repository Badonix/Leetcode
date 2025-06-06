class Solution {
public:
    int countSubarrays(vector<int>& nums) {
       int count = 0;
       int left = 0;
       int right = 2;
       while(right < nums.size()){
        if(nums[left] + nums[right] == nums[left+1]/2.0){
            count++;
        }
        left++;
        right++;
       }
       return count;
    }
};