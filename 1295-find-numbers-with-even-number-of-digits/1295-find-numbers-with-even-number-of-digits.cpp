class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0;
        for(int n : nums){
            if(findSize(n) % 2 == 0){
                count++;
            }
        }
        return count;
    }
    int findSize(int n){
        int len = 0;
        while(n != 0){
            n /= 10;
            len++;
        }
        return len;
    }
};