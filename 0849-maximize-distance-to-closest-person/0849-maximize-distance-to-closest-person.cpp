class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int maxDist = 0;
        for (int i = 0; i < seats.size(); i++) {
            if (seats[i] == 0) {
                int count = 0;
                int start = i;
                while (i < seats.size() && seats[i] == 0) {
                    count++;
                    i++;
                }
                if (start == 0 || i == seats.size()) {
                    maxDist = max(maxDist, count);
                } else {
                    maxDist = max(maxDist, (count + 1) / 2);
                }
                i--;
            }
        }
        return maxDist;
    }
};
