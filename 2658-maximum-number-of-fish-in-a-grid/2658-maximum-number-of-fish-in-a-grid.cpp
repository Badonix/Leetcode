class Solution {
public:
    void fish(int x, int y, vector<vector<int>>& grid, int& answ) {
        queue<pair<int, int>> q;
        q.push(make_pair(x, y));
        int count = 0;
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            count += grid[curr.first][curr.second];
            grid[curr.first][curr.second] = 0;
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    if (abs(i) + abs(j) == 2 || curr.first + i < 0 ||
                        curr.second + j < 0 || curr.first + i >= grid.size() ||
                        curr.second + j >= grid[0].size() ||
                        grid[curr.first + i][curr.second + j] == 0)
                        continue;
                    q.push(make_pair(curr.first + i, curr.second + j));
                }
            }
        }
        answ = max(answ, count);
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int answ = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0)
                    fish(i, j, grid, answ);
            }
        }
        return answ;
    }
};