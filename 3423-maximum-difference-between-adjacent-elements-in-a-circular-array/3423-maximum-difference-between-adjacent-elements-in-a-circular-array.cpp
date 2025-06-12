class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int answ = 0;
        for(int i = 0; i < nums.size(); i++){
            int j = i + 1;
            if(i == nums.size() - 1) j = 0;
            answ = max(answ,abs(nums[i] - nums[j]));
        }        
        return answ;
    }
};