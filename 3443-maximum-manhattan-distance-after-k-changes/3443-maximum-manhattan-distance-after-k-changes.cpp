class Solution {
public:
    int maxDistance(string p, int k) {
        int answ = 0;
        int n = 0, s = 0, w = 0, e = 0;
        for(int i = 0; i < p.size(); i++){
            char c = p[i];
            if(c == 'N')n++;
            if(c == 'S')s++;
            if(c == 'W')w++;
            if(c == 'E')e++;
            int x = abs(n - s);
            int y = abs(w - e);
            int distance = x + y;
            int possible = distance + min(2*k, i + 1 - distance);
            answ = max(answ, possible);
        }
        return answ;
    }
};