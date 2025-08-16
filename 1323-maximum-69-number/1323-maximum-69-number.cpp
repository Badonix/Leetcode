class Solution {
public:
    int maximum69Number (int num) {
        int reversed = reverseNum(num);
        int numLength = 0;
        int cl = num;
        while(cl){
            cl /= 10;
            numLength++;
        }
        while(reversed){
            int curr = reversed % 10;
            if(curr == 6){
                num += pow(10, numLength - 1) * 3;
                return num;
            }
            reversed /= 10;
            numLength--;
        }
        return num;
    }
    int reverseNum(int n){
        int answ = 0;
        int nLength = 0;
        int cl = n;
        while(cl){
            cl /= 10;
            nLength++;
        }
        for(int i = nLength; i >= 0; i--){
            answ += pow(10, i - 1) * (n % 10);
            n /= 10;
        }
        return answ;
    }
};