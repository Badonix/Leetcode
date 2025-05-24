class Solution {
public:
    int appendCharacters(string s, string t) {
        int sPointer = 0, tPointer = 0;
        while(sPointer < s.size()){
            if(tPointer == t.size()){
                return 0;
            }
            if(s[sPointer] == t[tPointer]){
                tPointer++;
            }
            sPointer++;
        }         
        return t.size() - tPointer;
    }
};