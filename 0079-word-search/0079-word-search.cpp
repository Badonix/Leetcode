class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size();
        int cols = board[0].size();

        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (board[i][j] == word[0] && dfs(board, i, j, 0, word)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool dfs(vector<vector<char>>& board, int row, int col, int index, string& word) {
        if (index == word.size()){
            return true;
        }
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';

        bool found = dfs(board, row + 1, col, index + 1, word) ||
                     dfs(board, row - 1, col, index + 1, word) ||
                     dfs(board, row, col + 1, index + 1, word) ||
                     dfs(board, row, col - 1, index + 1, word);

        board[row][col] = temp;
        return found;
    }
};
