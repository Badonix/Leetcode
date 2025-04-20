class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> c;
        int res = 0;
        for (int i : answers){
            c[i]++;
        }
        for (auto i : c){
            res += (i.second + i.first) / (i.first + 1) * (i.first + 1);
        } 
        return res;  
    }
};