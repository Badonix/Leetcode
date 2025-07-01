class Solution {
public:
    int possibleStringCount(string word) {
        int answ = 1;
        for(int i = 0; i < word.size(); i++){
            int j = i+1;
            int len = 1;
            while(j < word.size()){
                if(word[j] == word[i]){
                    len++;
                }else{
                    break;
                }
                j++;
            }
            if(len > 1) answ += len - 1;
            i = j-1;
        }
        return answ;
    }
};