class Solution {
public:
    string triangleType(vector<int>& nums) {
        set<int> s;
        if(nums[0]+nums[1]<=nums[2] || nums[1]+nums[2] <= nums[0] || nums[0]+nums[2]<=nums[1]){
            return "none";
        }
        for(int n : nums){
            s.insert(n);
        }
        vector<string> answ = {"equilateral", "isosceles", "scalene"};
        return answ[s.size() - 1];
    }
};