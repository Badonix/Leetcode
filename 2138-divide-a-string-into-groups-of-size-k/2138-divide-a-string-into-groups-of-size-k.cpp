class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> answ;
        string curr = "";
        for (char c : s) {
            curr += c;
            if(curr.size() == k){
                answ.push_back(curr);
                curr = "";
            }
        }
        if(curr != ""){
            int csize = curr.size();
            for(int i = 0; i <  k - csize; i++){
                curr += fill;
            }
            answ.push_back(curr);
        }
        return answ;
    }
};