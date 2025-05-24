class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
       vector<int> answ;
       for(int i = 0; i < words.size(); i++){
        string s = words[i];
        for(char c : s){
            if(c == x){
                answ.push_back(i);
                break;
            }
        }
       } 
       return answ;
    }
};