class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int i;
        for(i = nums.size() - 2; i >= 0; i--){
            if(nums[i] >= nums[i+1]) break;
        }        
        if(i < 0) return 0;
        return i+1;
    }
};