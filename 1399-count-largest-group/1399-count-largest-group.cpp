class Solution {
public:
    int countLargestGroup(int n) {
        unordered_map<int, int> groupCount;
        int maxSize = 0;
        for (int i = 1; i <= n; ++i) {
            int sum = digitSum(i);
            groupCount[sum]++;
            maxSize = max(maxSize, groupCount[sum]);
        }
        int count = 0;
        for (auto& [key, value] : groupCount) {
            if (value == maxSize) {
                count++;
            }
        }
        return count;
    }
private:
    int digitSum(int num) {
        int sum = 0;
        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }
        return sum;
    }
};
