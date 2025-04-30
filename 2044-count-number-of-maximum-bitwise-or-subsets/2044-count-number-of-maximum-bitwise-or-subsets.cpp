class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        vector<int> s;
        generate(nums, 0, 0, s);
        return getMaximumCount(s);
    }
    void generate(vector<int>& nums, int currOR, int index, vector<int>& s){
        if(index == nums.size()){
            s.push_back(currOR);
            return;
        }
        int currNum = nums[index];
        int temp = currOR;
        currOR = currNum | currOR;
        generate(nums, currOR, index + 1, s);
        currOR = temp;
        generate(nums, currOR, index + 1, s);
    }
    int getMaximumCount(vector<int>& s){
        int maxN = INT_MIN;
        for(int n : s){
            if (n > maxN){
                maxN = n;
            }
        }
        int count = 0;
        for(int n : s){
            if(n == maxN){
                count++;
            }
        }
        return count;
    }
};