class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> answ;
        solve(n, "", 0, 0, answ);
        return answ;
    }
    void solve(int n, string curr, int leftCount, int rightCount, vector<string>& s){
        if(curr.size() == n * 2){
            s.push_back(curr);            
            return;
        }

        // (
        if(leftCount < n){
            solve(n, curr + '(', leftCount + 1, rightCount, s);
        }
        // )        
        if(leftCount > rightCount){
            solve(n, curr + ')', leftCount, rightCount+1, s);
        }
    }
};