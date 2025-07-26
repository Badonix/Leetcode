class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& coordinates) {
        int x1 = coordinates[0][0];
        int y1 = coordinates[0][1];
        int x2 = coordinates[1][0];
        int y2 = coordinates[1][1];

        bool isVertical = (x2 == x1);
        double k = isVertical ? 0 : (double)(y2 - y1) / (x2 - x1);
        double b = isVertical ? x1 : y1 - k * x1;

        for(int i = 1; i < coordinates.size() - 1; i++){
            int currx1 = coordinates[i][0];
            int curry1 = coordinates[i][1];
            int currx2 = coordinates[i+1][0];
            int curry2 = coordinates[i+1][1];

            bool currVertical = (currx2 == currx1);
            double currk = currVertical ? 0 : (double)(curry2 - curry1) / (currx2 - currx1);
            double currb = currVertical ? currx1 : curry1 - currk * currx1;

            if(isVertical != currVertical) return false;
            if(!isVertical){
                if(abs(currk - k) > 1e-6 || abs(currb - b) > 1e-6) return false;
            } else {
                if(currx1 != x1) return false;
            }
        } 
        return true;
    }
};
