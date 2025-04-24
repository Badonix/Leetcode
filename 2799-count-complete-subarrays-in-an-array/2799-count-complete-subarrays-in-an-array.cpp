class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }
        int answ = 0;
        unordered_set<int> dist(nums.begin(), nums.end());
        int distCount = dist.size();
        for (int left = 0; left < nums.size(); ++left) {
            unordered_map<int, int> m;
            int unique = 0;
            for (int right = left; right < nums.size(); ++right) {
                if (m[nums[right]] == 0) {
                    unique++;
                }
                m[nums[right]]++;
                if (unique == distCount) {
                    answ++;
                }
            }
        }
        return answ;
    }
};
