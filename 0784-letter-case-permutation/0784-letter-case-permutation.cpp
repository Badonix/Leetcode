class Solution {
public:
    vector<string> letterCasePermutation(string s) {
        vector<string> answ;
        solve(s, 0, answ);
        return answ;
    }
    void solve(string curr, int index, vector<string>& answ){
        if(index == curr.size()){
            answ.push_back(curr);
            return;
        }
        while(index < curr.size() && !isalpha(curr[index])){
            cout << curr << endl;
            index++;
        }
        if(index == curr.size()){
            answ.push_back(curr);
            return;
        }
        char c = curr[index];
        curr[index] = tolower(c);
        solve(curr, index+1, answ);
        curr[index] = toupper(c);
        solve(curr, index+1, answ);
    }
};