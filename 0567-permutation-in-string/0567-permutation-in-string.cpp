class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int size1 = s1.size(), size2 = s2.size();
        if (size1 > size2) return false;      
        vector<int> freq1(26, 0), freq2(26, 0);
        for (int i = 0; i < size1; i++) {
            freq1[s1[i] - 'a']++;
            freq2[s2[i] - 'a']++;
        }      
        int index = size1;
        while (true) {
            int d = 0;
            for (int i = 0; i < 26; i++) {
                d += abs(freq1[i] - freq2[i]);
            }
            if (d == 0) return true;      
            int jump = d / 2;
            if (index + jump > size2) return false;       
            for (int i = 0; i < jump; i++) {
                freq2[s2[index + i] - 'a']++;
                freq2[s2[index + i - size1] - 'a']--;
            }
            index += jump;
        }
        return false;
    }
};