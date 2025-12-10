class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        bool arr[nums.size() + 1];
        for(int i = 0; i < nums.size() + 1; i++)arr[i] = false;
        vector<int> answ;
        for(int n : nums)arr[n] = true;
        for(int i = 1; i < nums.size()+1; i++){
            if(!arr[i])answ.push_back(i);
        }
        return answ;
    }
};