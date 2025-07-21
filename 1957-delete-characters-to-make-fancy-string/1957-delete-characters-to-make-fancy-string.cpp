class Solution {
public:
    string makeFancyString(string s) {
        string answ = "";
        answ += s[0];
        int currChar = s[0];
        int currCount = 1;
        for (int i = 1; i < s.size(); i++) {
            if(currChar == s[i]){
                currCount++;
                if(currCount < 3){
                    answ += s[i];
                }
            }else{
                currCount = 1;
                currChar = s[i];
                if(currCount < 3){
                    answ += s[i];
                }
            }
        }
        return answ;
    }
};