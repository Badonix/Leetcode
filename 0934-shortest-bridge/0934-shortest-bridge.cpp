class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        queue<pair<int, int>> q;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    markIsland(i, j, grid, q);
                    return find_shortest(i, j, grid, q);
                }
            }
        }
        return 0;
    }

    int find_shortest(int i, int j, vector<vector<int>>& grid,
                      queue<pair<int, int>>& q) {
        int distance = 0;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                pair<int, int> p = q.front();
                q.pop();
                if (grid[p.first][p.second] == 1)
                    return distance;
                for (int di = -1; di <= 1; di++) {
                    for (int dj = -1; dj <= 1; dj++) {
                        if (abs(di) == abs(dj))
                            continue;
                        if (inBounds(p.first + di, p.second + dj, grid)){
                            if(grid[p.first+di][p.second+dj] == 1){
                                return distance;
                            }else if(grid[p.first+di][p.second+dj] == 0){
                                q.push({p.first + di, p.second + dj});
                                grid[p.first+di][p.second+dj] = 2;
                            }
                        }
                    }
                }
            }
            distance++;
        }
        return distance;
    }

    void markIsland(int i, int j, vector<vector<int>>& grid,
                    queue<pair<int, int>>& q) {
        if (!inBounds(i, j, grid) || grid[i][j] != 1)
            return;
        grid[i][j] = 2;
        q.push({i, j});
        for (int di = -1; di <= 1; di++) {
            for (int dj = -1; dj <= 1; dj++) {
                if (abs(di) != abs(dj))
                    markIsland(i + di, j + dj, grid, q);
            }
        }
    }

    bool inBounds(int new_i, int new_j, vector<vector<int>>& grid) {
        return new_i >= 0 && new_j >= 0 && new_i < grid.size() &&
               new_j < grid[0].size();
    }
};