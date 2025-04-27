class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> answ;
        vector<string> board(n, string(n, '.'));
        dfs(board, 0, answ);
        return answ;
    }

    void dfs(vector<string>& board, int currCol, vector<vector<string>>& answ){
        if(currCol == board.size()){
            answ.push_back(board);
            return;
        }
        for(int row = 0; row < board.size(); row++){
            if (isSafe(board, row, currCol)) {
                board[row][currCol] = 'Q';
                dfs(board, currCol + 1, answ);
                board[row][currCol] = '.';
            }
        }
    }


    bool isSafe(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < col; i++) {
            if (board[row][i] == 'Q') return false;
        }
        for (int i = row, j = col; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }
        for (int i = row, j = col; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;
    }

};