class Solution {
public:
    int maxDifference(string s) {
        unordered_map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        vector<int> oddFreqs;
        vector<int> evenFreqs;

        for (auto& [ch, count] : freq) {
            if (count % 2 == 0) {
                evenFreqs.push_back(count);
            } else {
                oddFreqs.push_back(count);
            }
        }

        int maxDiff = INT_MIN;
        for (int odd : oddFreqs) {
            for (int even : evenFreqs) {
                maxDiff = max(maxDiff, odd - even);
            }
        }

        return maxDiff;
    }
};
