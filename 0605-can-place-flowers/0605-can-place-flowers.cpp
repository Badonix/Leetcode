class Solution {
public:
    bool rec(vector<int>& v, int n, int index) {
        if (n == 0) {
            return true;
        }
        if (index >= v.size()) {
            return false;
        }
        if (v[index] == 0 && (index == 0 || v[index - 1] == 0) &&
            (index == v.size() - 1 || v[index + 1] == 0)) {
            v[index] = 1;
            if (rec(v, n - 1, index + 2)) {
                return true;
            }
            v[index] = 0;
        }

        return rec(v, n, index + 1);
    }

    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        return rec(flowerbed, n, 0);
    }
};