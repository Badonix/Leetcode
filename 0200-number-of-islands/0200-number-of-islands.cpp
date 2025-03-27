class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        int count = 0;
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    dfs(grid, visited, i, j);
                    count++;
                }
            }    
        }
        return count;
    }

    void dfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int row, int col){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == '0' || visited[row][col]){
            return;
        }
        visited[row][col] = true;
        dfs(grid, visited, row, col+1);
        dfs(grid, visited, row, col-1);
        dfs(grid, visited, row + 1, col);
        dfs(grid, visited, row - 1, col);
    }
};