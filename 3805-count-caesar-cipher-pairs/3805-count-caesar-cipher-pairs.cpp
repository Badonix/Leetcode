class Solution {
public:
    void cyph(string& w, int shift){
        for(int i = 0; i < w.size(); i++){
            w[i] = w[i] + shift;
            if(w[i] < 'a'){
                w[i] = 'z' - ('a' - w[i]) + 1;                                
            }
        }
    }
    long long countPairs(vector<string>& words) {
        unordered_map<string, long long> map;
        for(string& w : words){
            int shift = 'a' - w[0];
            cyph(w, shift);
            map[w]++;
        }
        long long count = 0;
        string sm = "zg";
        cyph(sm, (int)('a'-sm[0]));
        for(pair<string, long long> p : map){
            if(p.second > 1){
                count += p.second*(p.second-1)/2;
            }
        }
        return count;
    }
};