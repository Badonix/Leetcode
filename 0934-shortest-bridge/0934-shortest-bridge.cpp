class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1) {
                    set<pair<int, int>> edges = populateIsland(grid, i, j);
                    return findBridge(grid, edges);
                }
            }
        }
        return -9;
    }

    int findBridge(vector<vector<int>>& grid, set<pair<int, int>> edges){
        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        queue<pair<int, int>> q; 
        for(pair<int, int> curr : edges){
            q.push(curr);
        }

        int bridgeLength = 0;
        int size = q.size();
        while(!q.empty()){
            bridgeLength++;
            for(int i = 0; i < size; i++){
                pair<int, int> curr = q.front();
                q.pop();
                for(auto [dr, dc] : directions){
                    int newRow = curr.first + dr;
                    int newCol = curr.second + dc;
                    if(isInBounds(grid, make_pair(newRow, newCol)) && grid[newRow][newCol] != 2){
                        if(grid[newRow][newCol] == 1){
                            return bridgeLength - 1;
                        }else if(grid[newRow][newCol] == 0){
                            q.push(make_pair(newRow, newCol));
                            grid[newRow][newCol] = 2;
                        }
                    }
                }
            }
            size = q.size();
        }
        return -1;        
    } 

    bool isInBounds(vector<vector<int>>& grid, pair<int, int> coords) {
        int row = coords.first;
        int col = coords.second;
        return row >= 0 && row < grid.size() && col < grid[0].size() &&
               col >= 0;
    }

    bool isIslandEdge(vector<vector<int>>& grid, int row, int col) {
        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        for (auto [dr, dc] : directions) {
            int newRow = row + dr;
            int newCol = col + dc;
            if (!isInBounds(grid, make_pair(newRow, newCol))) {
                continue;
            }
            if (grid[newRow][newCol] == 0) {
                return true;
            }
        }
        return false;
    }

    set<pair<int, int>> populateIsland(vector<vector<int>>& grid, int row,
                                       int col) {
        vector<pair<int, int>> directions = {
            {1, 0},
            {-1, 0},
            {0, 1},
            {0, -1},
        };
        queue<pair<int, int>> q;
        set<pair<int, int>> edges;
        pair<int, int> startPair = make_pair(row, col);
        q.push(startPair);
        grid[row][col] = 2;
        if (isIslandEdge(grid, row, col)) {
            edges.insert(startPair);
        }
        while (!q.empty()) {
            pair<int, int> curr = q.front();
            q.pop();

            for (auto [dr, dc] : directions) {
                int newRow = curr.first + dr;
                int newCol = curr.second + dc;
                pair<int, int> newEl = make_pair(newRow, newCol);
                if (isInBounds(grid, newEl) && grid[newRow][newCol] == 1) {
                    q.push(newEl);
                    grid[newRow][newCol] = 2;
                    if (isIslandEdge(grid, newRow, newCol)) {
                        edges.insert(newEl);
                    }
                }
            }
        }
        return edges;
    }
};