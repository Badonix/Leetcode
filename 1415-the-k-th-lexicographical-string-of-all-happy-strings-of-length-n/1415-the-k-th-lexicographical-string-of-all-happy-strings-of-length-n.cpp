class Solution {
public:
    string getHappyString(int n, int k) {
        vector<string> s;
        vector<string> letters = {"a", "b", "c"};
        solve(letters, "", n, s);
        if(s.size() < k){
            return "";
        }
        return s[k-1];
    }
    void solve(vector<string>& letters, string curr, int n, vector<string>&answ){
        if(curr.size() == n){
            answ.push_back(curr);
            return;
        }        
        for(string l : letters){
            if(curr.size() == 0){
                solve(letters, curr + l, n, answ);
            }else{
                if(l[0] != curr[curr.size() - 1]){
                    solve(letters, curr + l, n, answ);
                }
            }
        }
    }
};