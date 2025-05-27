class Solution {
public:
    int differenceOfSums(int n, int m) {
        int num1Count = n / m;
        int lastNum1 = (n / m ) * m;
        int divisibleSum = (m + lastNum1)*num1Count / 2;         
        return (1 + n)*n/2 - 2 * divisibleSum;
    }
};
