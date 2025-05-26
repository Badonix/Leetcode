class Solution {
public:
    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        vector<vector<pair<int, int>>> grid2Islands;
        for (int i = 0; i < grid2.size(); i++) {
            for (int j = 0; j < grid2[i].size(); j++) {
                if (grid2[i][j] == 1) {
                    exploreIsland(i, j, grid2, grid2Islands);
                }
            }
        }
        int answ = 0;

        for(vector<pair<int, int>> island : grid2Islands){
            checkValidSubislands(grid1, island, answ);
        }
        return answ;
    }

    void checkValidSubislands(vector<vector<int>>& grid, vector<pair<int, int>>& s, int& answ){ 
        for(pair<int, int>& coord : s){
            if(grid[coord.first][coord.second] != 1){
                return;
            }
        }
        answ++;
    }
    void exploreIsland(int r, int c, vector<vector<int>>& grid,
                       vector<vector<pair<int, int>>>& answ) {
        set<pair<int, int>> visited;
        vector<pair<int, int>> currentIsland;
        queue<pair<int, int>> q;
        pair<int, int> f;
        f.first = r;
        f.second = c;

        q.push(f);
        visited.insert(f);
        currentIsland.push_back(f);
        while (!q.empty()) {
            pair<int, int> current = q.front();
            q.pop();
            int row = current.first;
            int col = current.second;
            grid[row][col] = 0;
            if (isValid(row - 1, col, visited, grid) && grid[row - 1][col] == 1) {
                pair<int, int> p;
                p.first = row - 1;
                p.second = col;
                q.push(p);
                currentIsland.push_back(p);
                visited.insert(p);
            }

            if (isValid(row + 1, col, visited, grid) && grid[row + 1][col] == 1) {
                pair<int, int> p;
                p.first = row + 1;
                p.second = col;
                q.push(p);
                currentIsland.push_back(p);
                visited.insert(p);
            }
            if (isValid(row, col - 1, visited, grid) && grid[row][col-1] == 1) {
                pair<int, int> p;
                p.first = row;
                p.second = col - 1;
                q.push(p);
                currentIsland.push_back(p);
                visited.insert(p);
            }
            if (isValid(row, col + 1, visited, grid) && grid[row][col + 1] == 1) {
                pair<int, int> p;
                p.first = row;
                p.second = col + 1;
                q.push(p);
                currentIsland.push_back(p);
                visited.insert(p);
            }
        }
        answ.push_back(currentIsland);
    }

    bool isValid(int row, int col, set<pair<int, int>>& visited,
                 vector<vector<int>>& grid) {
        pair<int, int> temp;
        temp.first = row;
        temp.second = col;
        if (visited.count(temp) != 0) {
            return false;
        }
        if (row < 0 || col < 0 || row >= grid.size() ||
            col >= grid[row].size()) {
            return false;
        }
        return true;
    }
};