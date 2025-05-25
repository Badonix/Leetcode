class Solution {
public:
    void generate(vector<string>& words, int index, string curr, int& maxSize) {
        if (isPalindrome(curr)) {
            maxSize = max(maxSize, (int)curr.size());
        }
        for (int i = index; i < words.size(); ++i) {
            swap(words[i], words[index]);
            generate(words, index + 1, curr + words[index], maxSize);
            swap(words[i], words[index]);
        }
    }

    int longestPalindrome(vector<string>& words) {
        int maxSize = 0;
        generate(words, 0, "", maxSize);
        return maxSize;        
    }
    bool isPalindrome(string s){
        for(int i = 0; i < s.size() / 2; i++){
            if(s[i] != s[s.size() - i - 1]){
                return false;
            }
        }
        return true;
    }
};