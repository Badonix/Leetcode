array<vector<int>, 5> freq;
int n;
class Solution {
public:
    static int maxD_ab(int a, int b, int k) {
        int cnt = INT_MIN;
        const int INF=1e8;
        int minFreq[2][2]={{INF, INF},{INF, INF}};
        int freq_a=0, freq_b=0, prev_a=0, prev_b=0;
        for (int l=0, r=k-1; r < n; r++) {
            freq_a=freq[a][r+1], freq_b=freq[b][r+1];
            while( r-l+1>=k && freq_b-prev_b>=2){
                minFreq[prev_a&1][prev_b&1]=min(minFreq[prev_a&1][prev_b&1], prev_a-prev_b);
                prev_a=freq[a][l+1];
                prev_b=freq[b][l+1];
                l++;
            }
            cnt=max(cnt, freq_a-freq_b-minFreq[1-(freq_a&1)][freq_b&1]);
        }
        return cnt;
    }

    static int maxDifference(string& s, int k) {
        n=s.size();
        freq.fill(vector<int>(n+1, 0));
        for (int i=0; i < n; i++) {
            for (int d=0; d <= 4; d++) freq[d][i+1]=freq[d][i];
            freq[s[i]-'0'][i+1]++;
        }

        int ans=INT_MIN;
        for (int a=0; a <= 4; a++) {
            if (freq[a][n] == 0) continue;
            for (int b=0; b<=4; b++) {
                if (a==b || freq[b][n]==0) continue;
                ans=max(ans, maxD_ab(a, b, k));
            }
        }

        return ans;
    }
};