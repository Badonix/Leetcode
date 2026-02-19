class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> v;
        for(int i = 0; i < s.size(); i++){
            int counter = 0;
            int j = i;
            while(j < s.size() && s[i] == s[j]){
                counter++;
                j++;
            }
            i = j - 1;
            v.push_back(counter);
        }
        int answer = 0;
        for(int i = 0; i < v.size() - 1; i++){
            answer += min(v[i], v[i+1]);
        }
        return answer;
    }
};