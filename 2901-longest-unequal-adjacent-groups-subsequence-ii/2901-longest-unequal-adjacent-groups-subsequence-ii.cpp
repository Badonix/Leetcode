class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        unordered_map<string, vector<string>> memo;
        int n = words.size();
        vector<string> best;

        for (int i = 0; i < n; ++i) {
            vector<string> res = {words[i]};
            auto rest = helper(i + 1, groups[i], words[i], words, groups, memo);
            res.insert(res.end(), rest.begin(), rest.end());
            if (res.size() > best.size()) best = res;
        }

        return best;
    }

private:
    vector<string> helper(int i, int lastGroup, string lastWord,
                          vector<string>& words, vector<int>& groups,
                          unordered_map<string, vector<string>>& memo) {
        if (i >= words.size()) return {};
        string key = to_string(i) + "|" + to_string(lastGroup) + "|" + lastWord;
        if (memo.count(key)) return memo[key];

        vector<string> take, skip;
        if (words[i].size() == lastWord.size() &&
            hamming(words[i], lastWord) &&
            groups[i] != lastGroup) {
            take.push_back(words[i]);
            auto temp = helper(i + 1, groups[i], words[i], words, groups, memo);
            take.insert(take.end(), temp.begin(), temp.end());
        }

        skip = helper(i + 1, lastGroup, lastWord, words, groups, memo);
        memo[key] = (take.size() > skip.size()) ? take : skip;
        return memo[key];
    }

    bool hamming(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] != b[i]) diff++;
        }
        return diff == 1;
    }
};