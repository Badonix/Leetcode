class Solution {
public:
    int maxSum(vector<int>& nums) {
        int answ = 0;
        int maxNum = INT_MIN;
        unordered_map<int, int> m;
        for(int n : nums){
            maxNum = max(maxNum, n);
            if(n <= 0) continue;
            m[n]++;
        }
        if(maxNum <= 0) return maxNum;
        for(pair<int, int> p : m){
            answ += p.first;
        }
        return answ;
    }
};