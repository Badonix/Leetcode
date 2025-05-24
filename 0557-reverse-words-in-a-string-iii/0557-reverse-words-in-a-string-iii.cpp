class Solution {
public:
    string reverseWords(string s) {
        string answ = "";
        int mark = 0;
        for (int i = 0; i < s.size(); i++) {
            if(s[i] == ' ' || i == s.size() - 1){
                int endIndex = i == s.size() - 1 ? i : i - 1;
                string word = reverseWord(mark, endIndex, s);
                answ += i == s.size() - 1 ? word : word + ' ';
                mark = i + 1;
            }
        }
        return answ;
    }
    string reverseWord(int mark, int end, string s){
        string answ = "";
        for(int i = end; i >= mark; i--){
            answ += s[i];
        }
        return answ;
    }
};