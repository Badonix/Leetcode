class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> answ;
        map<int, vector<int>> m;
        for(int i = 0; i < nums.size(); i++){
            m[nums[i]].push_back(i);
        }
        for(int i = 0; i < nums.size(); i++){
            if(m.count(target - nums[i])){
                vector<int> possible = m[target - nums[i]];
                if(nums[i] * 2 == target){
                    if(possible.size() > 1){
                        answ.push_back(possible[0]);
                        answ.push_back(possible[1]);
                        return answ;
                    }
                } else {
                    if(possible[0] != i){
                        answ.push_back(i);
                        answ.push_back(possible[0]);
                        return answ;
                    }
                }
            }
        }
        return answ;
    }
};
