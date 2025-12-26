class Solution {
public:
    int bestClosingTime(string customers) {
        // Penalty = N-s at left + Y-s at right
        vector<int> nPrefix(customers.size());
        vector<int> yPrefix(customers.size());
        if (customers[0] == 'N') {
            nPrefix[0] = 1;
        } else {
            yPrefix[0] = 1;
        }
        for (int i = 1; i < nPrefix.size(); i++) {
            nPrefix[i] = nPrefix[i - 1];
            yPrefix[i] = yPrefix[i - 1];
            if (customers[i] == 'N') {
                nPrefix[i]++;
            } else {
                yPrefix[i]++;
            }
        }
        int minPenalty = INT_MAX;
        int minTime = INT_MAX;
        for(int i = 0; i < nPrefix.size(); i++){
            int nsLeft = 0;
            int ysRight = 0;
            if(i != 0){
                nsLeft = nPrefix[i-1];
            }
            if(i != nPrefix.size() - 1){
                ysRight = yPrefix[yPrefix.size() - 1];
                if(i != 0){
                    ysRight -= yPrefix[i-1];
                }
            }
            cout << nsLeft << " " << ysRight << endl;
            if(nsLeft + ysRight < minPenalty){
                minTime = i;
                minPenalty = nsLeft + ysRight;
            }
        }
        if(minTime == nPrefix.size() - 1){
            if(customers[minTime] == 'Y'){
                minTime++;
            }
        }
        return minTime;
    }
    // YYNY -> 0011, 1223
};