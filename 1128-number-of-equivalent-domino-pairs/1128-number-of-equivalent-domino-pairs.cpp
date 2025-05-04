class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        int count = 0;
        map<string, int> m;
        for(int i = 0; i < dominoes.size(); i++){
            string curr = "";
            if(dominoes[i][0] > dominoes[i][1]){
                swap(dominoes[i][0], dominoes[i][1]);
            }
            curr += dominoes[i][0] - '0';
            curr += dominoes[i][1] - '0';
            m[curr]++;
        }
        for(pair<string, int> c : m){
            cout << c.first << " " << c.second << endl;
            count += c.second * (c.second - 1)/2;
        }
        return count;
    }
};