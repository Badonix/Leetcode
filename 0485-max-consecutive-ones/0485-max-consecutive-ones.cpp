class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int answ = INT_MIN;
        for(int i = 0; i < nums.size(); i++){
            int len = 0;
            while(i < nums.size() && nums[i] == 1){
                len++;
                i++;
            }
            answ = max(answ, len);
        }
        return answ;
    }
};