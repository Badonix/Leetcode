class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
       vector<string> answ;
       solve(s,"",0, 0, answ);
       return answ; 
    }
    void solve(string s, string curr, int index, int size, vector<string>& answ){
        if(index == s.size()){
            if(size == 4){
                curr.pop_back();
                answ.push_back(curr);
            }
            return;
        }
        if(s[index] == '0'){
            solve(s, curr + "0.", index + 1,size + 1, answ);
            return;
        }
        solve(s, curr + s[index] + '.', index + 1, size+1,answ);
        if(index + 1 < s.size()){
            solve(s, curr + s[index] + s[index+1] + '.', index + 2,size+1, answ);
        }
        if(index + 2 < s.size()){
            int num = (s[index] - '0') * 100 + (s[index+1] - '0') * 10 + s[index+2]-'0';
            if(num >255){
                return;
            }
            solve(s, curr + s[index] + s[index+1] + s[index+2] + '.', index + 3,size+1, answ);
        }
    }
};