class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int> answ;
        for(int i = 0; i < nums.size() / 2; i++){
            answ.push_back(nums[i]);
            answ.push_back(nums[i+n]);
        }
        return answ;
    }
};