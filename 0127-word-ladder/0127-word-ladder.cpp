class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {
        if(beginWord.size() != endWord.size()){
            return 0;
        }
        set<string> dict;
        for (string word : wordList) {
            dict.insert(word);
        }
        queue<vector<string>> q;
        set<string> visited;
        visited.insert(beginWord);
        vector<string> start = {beginWord};
        q.push(start);

        while(!q.empty()){
            vector<string> curr = q.front();
            q.pop();
            string currentWord = curr[curr.size() - 1];
            if(currentWord == endWord){
                return curr.size();
            }
            for(int i = 0; i < beginWord.size(); i++){
                for(char c = 'a'; c < 'z'; c++){
                    string newString = currentWord;
                    newString[i] = c;
                    if(visited.contains(newString) || !dict.contains(newString)){
                        continue;
                    }
                    visited.insert(newString);
                    vector<string> newCurr = curr;
                    newCurr.push_back(newString);
                    q.push(newCurr);
                }
            }
        }
        return 0;
    }
};