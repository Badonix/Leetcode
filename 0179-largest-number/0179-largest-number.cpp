class Solution {
public:
    string largestNumber(std::vector<int>& nums) {
        bool allZeros = true;
        for (int num : nums) {
            if (num != 0) {
                allZeros = false;
                break;
            }
        }
        if (allZeros) {
            return "0";
        }
        vector<string> strNums;
        for (int num : nums) {
            strNums.push_back(to_string(num));
        }
        sort(strNums.begin(), strNums.end(),
             [](const string a, const string b) { return b + a < a + b; });
        string result;
        for (const string s : strNums) {
            result += s;
        }
        return result;
    }
};