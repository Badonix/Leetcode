class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }

    bool solve(vector<vector<char>>& board) {
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    for (char num = '1'; num <= '9'; num++) {
                        if (tryNumber(row, col, num, board)) {
                            board[row][col] = num;
                            if (solve(board)){
                                return true;
                            } 
                            board[row][col] = '.';
                        }
                    }
                    return false; 
                }
            }
        }
        return true;
    }

    bool tryNumber(int row, int col, char num, vector<vector<char>>& board) {
        for (int i = 0; i < board.size(); i++) {
            if (board[row][i] == num) {
                return false;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            if (board[i][col] == num) {
                return false;
            }
        }
        int box = (row / 3) * 3 + (col / 3);
        int startRow = (box / 3) * 3;
        int startCol = (box % 3) * 3;
        return isValidBox(startRow, startCol, num, board);
    }
    bool isValidBox(int startRow, int startCol, char num, vector<vector<char>>& board) {
        for (int r = startRow; r < startRow + 3; ++r) {
            for (int c = startCol; c < startCol + 3; ++c) {
                if(board[r][c]== num){
                    return false;
                }
            }
        }
        return true;
    }
};