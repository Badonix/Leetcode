class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int count = 0;
        allSubsetXORS(nums, 0, count, 0);
        return count;
    }
    void allSubsetXORS(vector<int>& nums, int curr, int& answ, int index){
        if(index == nums.size()){
            answ += curr;
            return;
        }
        int currNum = nums[index];
        int temp = curr;
        curr = currNum ^ curr;
        allSubsetXORS(nums, curr, answ, index+1);
        curr = temp;
        allSubsetXORS(nums, curr, answ, index+1);
    }
};