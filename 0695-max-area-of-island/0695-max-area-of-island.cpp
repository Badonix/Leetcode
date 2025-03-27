class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] && !visited[i][j]) {
                    maxArea = max(maxArea, bfs(grid, visited, i, j));
                }
            }
        }
        return maxArea;
    }

private:
    int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int row,
            int col) {
        if (row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() ||
            !grid[row][col] || visited[row][col]) {
            return 0;
        }
        visited[row][col] = true;
        return 1 + bfs(grid, visited, row + 1, col) +
               bfs(grid, visited, row - 1, col) +
               bfs(grid, visited, row, col - 1) +
               bfs(grid, visited, row, col + 1);
    }
};