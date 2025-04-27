class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int sum = 0;
        for (int n : matchsticks) {
            sum += n;
        }
        if (sum % 4) {
            return false;
        }
        sort(matchsticks.begin(), matchsticks.end());
        int a = 0, b = a, c = a, d = a;

        if (solve(matchsticks, matchsticks.size() - 1, a, b, c, d, sum / 4)) {
            return true;
        }
        return false;
    }
    bool solve(vector<int>& matchsticks, int pos, int a, int b, int c, int d, int side) {
        if(a > side || b > side || c > side || d > side){
            return false;
        }
        if (pos == -1) {
            if (a == b && b == c && c == d) {
                return true;
            }
            return false;
        }
        int curr = matchsticks[pos];
        pos--;
        return solve(matchsticks, pos, a + curr, b, c, d, side) ||
               solve(matchsticks, pos, a, b + curr, c, d, side) ||
               solve(matchsticks, pos, a, b, c+curr, d, side) ||
               solve(matchsticks, pos, a, b, c, d + curr, side);
    }
};