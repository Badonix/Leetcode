class Solution {
public:
    int firstUniqChar(string s) {
        vector<int> freq(26, 0);
        queue<int> q;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            freq[c - 'a']++;
            if (freq[c - 'a'] == 1)
                q.push(i);
            while (!q.empty() && freq[s[q.front()] - 'a'] > 1)
                q.pop();
        }

        return q.empty() ? -1 : q.front();
    }
};