class Solution {
public:
    bool isSolvable(vector<string>& words, string result) {
        int coef[26] = {0};
        bool leading[26] = {false};

        for (const string& word : words) {
            int n = word.size();
            for (int i = 0; i < n; ++i) {
                coef[word[i] - 'A'] += pow(10, n - i - 1);
            }
            if (n > 1) leading[word[0] - 'A'] = true;
        }

        int n = result.size();
        for (int i = 0; i < n; ++i) {
            coef[result[i] - 'A'] -= pow(10, n - i - 1);
        }
        if (n > 1) leading[result[0] - 'A'] = true;

        vector<int> chars;
        for (int i = 0; i < 26; ++i) {
            if (coef[i] != 0) chars.push_back(i);
        }

        vector<bool> used(10, false);
        return dfs(0, chars, coef, leading, used, 0);
    }

private:
    bool dfs(int idx, vector<int>& chars, int coef[], bool leading[],
             vector<bool>& used, long long currSum) {
        if (idx == chars.size()) {
            return currSum == 0;
        }

        int c = chars[idx];
        for (int d = 0; d < 10; ++d) {
            if (used[d]) continue;
            if (d == 0 && leading[c]) continue;

            used[d] = true;
            if (dfs(idx + 1, chars, coef, leading, used, currSum + coef[c] * d)) {
                return true;
            }
            used[d] = false;
        }
        return false;
    }
};
