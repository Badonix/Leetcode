class Solution {
public:
    void solve(vector<vector<char>>& board) {
        set<pair<int, int>> visited;
        for (int row = 0; row < board.size(); row++) {
            for (int col = 0; col < board[row].size(); col++) {
                pair<int, int> p = make_pair(row, col);
                if (visited.count(p) || board[row][col] == 'X')
                    continue;

                set<pair<int, int>> region;
                if (checkValidity(row, col, board, visited, region)) {
                    for (const auto& pos : region) {
                        board[pos.first][pos.second] = 'X';
                    }
                }
                visited.insert(region.begin(), region.end());
            }
        }
    }

    bool checkValidity(int row, int col, vector<vector<char>>& board,
                       set<pair<int, int>>& globalVisited,
                       set<pair<int, int>>& region) {
        queue<pair<int, int>> q;
        q.push(make_pair(row, col));
        region.insert(make_pair(row, col));
        bool isSurrounded = true;

        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            int r = p.first;
            int c = p.second;

            if (isInEdge(p, board))
                isSurrounded = false;

            vector<pair<int, int>> directions = {
                {1, 0}, {-1, 0}, {0, 1}, {0, -1}
            };

            for (auto& d : directions) {
                int nr = r + d.first;
                int nc = c + d.second;
                pair<int, int> np = {nr, nc};
                if (isInBounds(nr, nc, board) && !region.count(np)) {
                    region.insert(np);
                    q.push(np);
                }
            }
        }

        return isSurrounded;
    }

    bool isInBounds(int row, int col, vector<vector<char>>& board) {
        return row >= 0 && col >= 0 && row < board.size() &&
               col < board[0].size() && board[row][col] == 'O';
    }

    bool isInEdge(pair<int, int> p, vector<vector<char>>& board) {
        int row = p.first;
        int col = p.second;
        return row == 0 || col == 0 || row == board.size() - 1 ||
               col == board[0].size() - 1;
    }
};
