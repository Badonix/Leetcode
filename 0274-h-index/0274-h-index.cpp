class Solution {
public:
    int hIndex(vector<int>& citations) {
        vector<int> bucket(citations.size() + 1, 0);
        for(int n : citations){
            n < bucket.size() ? bucket[n]++ : bucket[citations.size()]++;
        }

        int countSum = 0;
        for(int i = bucket.size() - 1; i > 0; i--){
            countSum += bucket[i];
            if(countSum >= i){
                return i;
            }
        }
        return citations[0] == 0 ? 0 : 1;
    }
};
