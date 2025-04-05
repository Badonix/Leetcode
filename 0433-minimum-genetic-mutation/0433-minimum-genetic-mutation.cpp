class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        char choices[4] = {'A', 'C', 'G', 'T'};
        queue<string> q;
        set<string> bankSet;
        set<string> visited;
        for(string valid : bank){
            bankSet.insert(valid);
        }
        bankSet.insert(startGene);
        visited.insert(startGene);
        q.push(startGene);
        int steps = 0;
        int size = q.size();
        while (!q.empty()) {
            steps++;
            for(int i = 0; i < size; i++){
                string curr = q.front();
                q.pop();
                if(curr == endGene){
                    return steps - 1;
                }
                for(int i = 0; i < curr.size(); i++){
                    // Here i wanna get all valid permutations;
                    for(char c : choices){
                        string newString = curr;
                        newString[i] = c;
                        if(bankSet.contains(newString) && !visited.contains(newString)){
                            q.push(newString);
                            visited.insert(newString);
                        } 
                    }
                }
            }
            size = q.size();
        }
        return -1;
    }
};