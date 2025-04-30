class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> s;
        vector<int> curr;
        getSubsets(nums, curr, 0, s);
        return s;
    }
    void getSubsets(vector<int>& nums, vector<int> curr, int index, vector<vector<int>>& s){
        if(index == nums.size()){
            s.push_back(curr);
            return;
        }
        int currNum = nums[index];
        curr.push_back(currNum);
        getSubsets(nums, curr, index+1, s);
        curr.pop_back();
        getSubsets(nums, curr, index+1, s);
    }

};