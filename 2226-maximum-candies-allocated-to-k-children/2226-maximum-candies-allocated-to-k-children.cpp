class Solution {
public:
    bool check(vector<int>& candies, int& m, long long& k) {
        long long ans = 0;
        for (int i = 0; i < candies.size(); ++i) {
            ans += candies[i] / m;
        }
        return ans >= k;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int l = 1, r = *max_element(candies.begin(), candies.end());

        while (l <= r) {
            int m = l + (r - l) / 2;
            if (check(candies, m, k))
                l = m + 1;
            else
                r = m - 1;
        }
        return r;
    }
};