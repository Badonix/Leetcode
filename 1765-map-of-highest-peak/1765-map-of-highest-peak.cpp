class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        vector<vector<int>> g(isWater.size(), vector<int>(isWater[0].size(), -2));
        set<pair<int, int>> visited;
        queue<pair<int, int>> q;
        for (int i = 0; i < isWater.size(); i++) {
            for (int j = 0; j < isWater[0].size(); j++) {
                if (isWater[i][j]) {
                    g[i][j] = 0;
                    visited.insert(make_pair(i, j));
                    q.push(make_pair(i, j));
                } else {
                    g[i][j] = -1;
                }
            }
        }
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();
            int currRow = curr.first;
            int currCol = curr.second;
            int currValue = g[currRow][currCol];
            for (int i = -1; i <= 1; i++) {
                for (int j = -1; j <= 1; j++) {
                    int newRow = currRow + i;
                    int newCol = currCol + j;
                    if (abs(i) + abs(j) == 2 || !isInBounds(g, newRow, newCol) ||
                        visited.count({newRow, newCol}))
                        continue;
                    g[newRow][newCol] = currValue + 1;
                    q.push({newRow, newCol});
                    visited.insert({newRow, newCol});
                }
            }
        }
        return g;
    }
    bool isInBounds(vector<vector<int>>& grid, int row, int col){
        return row >= 0 && col >= 0 && row < grid.size() && col < grid[0].size();
    }
};