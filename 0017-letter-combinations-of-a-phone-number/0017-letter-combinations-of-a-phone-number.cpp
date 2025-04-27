class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> letters = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> answ;

        dfs(letters, "", digits, answ);
        return answ;
    }
    void dfs(vector<string> & letters, string curr, string target, vector<string>& answ){
        if(target.empty()){
            if(curr == ""){
                return;
            }
            answ.push_back(curr);
            return;
        }
        char currentNumber = target[0] - '0';
        string choices = letters[currentNumber];
        for(char c : choices){
            char t = target[0];
            dfs(letters, curr + c,target.substr(1), answ );
        }
    }
};