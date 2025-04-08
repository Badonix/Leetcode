class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int steps = 0;

        while (true) {
            map<int, int> freq;
            for (int n : nums) {
                freq[n]++;
            }
            if (isDistinct(freq)) break;
            int removeCount = min(3, (int)nums.size());
            nums.erase(nums.begin(), nums.begin() + removeCount);
            steps++;
        }

        return steps;
    }

    bool isDistinct(map<int, int>& t) {
        for (auto& [key, val] : t) {
            if (val > 1) return false;
        }
        return true;
    }
};
