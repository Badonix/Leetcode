class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> answ;
        vector<int> soFar;
        permuteClone(soFar, nums, answ);
        return answ;
    }
    void permuteClone(vector<int>& soFar, vector<int>& nums, vector<vector<int>>& answ){
        if(nums.empty()){
            answ.push_back(soFar);
            return;
        }
        for(int i = 0; i < nums.size(); i++){
            int currNum = nums[i];
            nums.erase(nums.begin() + i);
            soFar.push_back(currNum);
            permuteClone(soFar, nums, answ);
            nums.insert(nums.begin() + i, currNum);
            soFar.pop_back();
        }
    }
};