class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> m;
        set<char> leftSet;
        for (char c : s1) {
            m[c]++;
            leftSet.insert(c);
        }

        int left = 0;
        int right = left + s1.size() - 1;
        if (right >= s2.size()) {
            return false;
        }

        for (int i = 0; i <= right; i++) {
            m[s2[i]]--;
            if (m[s2[i]] == 0) {
                leftSet.erase(s2[i]);
            } else if (m[s2[i]] == -1) {
                leftSet.insert(s2[i]);
            }
        }

        if (leftSet.empty()) {
            return true;
        }

        while (right < s2.size() - 1) {
            if (m[s2[left]] == 0) {
                leftSet.insert(s2[left]);
            }
            m[s2[left]]++;
            if (m[s2[left]] == 0) {
                leftSet.erase(s2[left]);
            }
            left++;
            right++;
            m[s2[right]]--;
            if (m[s2[right]] == 0) {
                leftSet.erase(s2[right]);
            } else if (m[s2[right]] == -1) {
                leftSet.insert(s2[right]);
            }
            if (leftSet.empty()) {
                return true;
            }
        }

        return false;
    }
};
