class Solution {
public:
    bool isPalindrome(string s) {
        string b = "";
        for(char c : s){
            if(isalpha(c) || isdigit(c)){
                b += tolower(c);
            }
        }
        s = b;
        if(s.size() == 1){
            return true;
        }
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }        
        return true;
    }
};