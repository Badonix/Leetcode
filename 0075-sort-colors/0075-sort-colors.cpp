class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        for(int n : nums){
            m[n]++;
        }
        int start = 0;
        for(pair<int, int> p : m){
            for(int i = 0; i < p.second; i++){
                nums[start+i] = p.first;
            }
            start += p.second;
        }
    }
};