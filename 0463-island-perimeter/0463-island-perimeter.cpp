class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (int k = 0; k < 4; k++) {
                        int newx = i + dx[k];
                        int newy = j + dy[k];
                        if (newx < 0 || newx >= n || newy < 0 || newy >= m ||
                            grid[newx][newy] == 0) {
                            cnt++;
                        }
                    }
                }
            }
        }
        return cnt;
    }
};