class Solution {
public:
    bool canWin(vector<int>& nums, int index, vector<bool>& v){
        if(v[index]) return false;
        if(index + nums[index] + 1 >= nums.size()){
            return true;
        }
        for(int i = 1; i <= nums[index]; i++){
            v[index+i-1] = true;
            if(canWin(nums, index + i, v)){
                return true;
            }
        }
        return false;
    }
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1) return true;
        vector<bool> v(nums.size(), false);
        return canWin(nums, 0, v);
    }
};