class Solution {
    public void gameOfLife(int[][] board) {
        int[][] nextGen = new int[board.length][board[0].length];         
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                int neighborCount = countNeighbors(board, i, j);                
                // Dead
                if(board[i][j] == 0){
                    if(neighborCount == 3){
                        nextGen[i][j] = 1;
                    }
                }else{
                    if(neighborCount < 2){
                        nextGen[i][j] = 0;
                    }else if(neighborCount < 4){
                        nextGen[i][j] = 1;
                    }else{
                        nextGen[i][j] = 0;
                    }
                }
            }
        }
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                board[i][j] = nextGen[i][j];
            }
        }
    }
    private int countNeighbors(int[][] board, int y, int x){
        int count = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) continue;
                int newY = y + i;
                int newX = x + j; 
                if(isInBounds(board, newY, newX) && board[newY][newX] == 1){
                    count++;
                }
            }
        }
        return count;
    }

    private boolean isInBounds(int[][]board, int y, int x){
        if(x < 0 || y < 0 || x >= board[0].length || y >= board.length){
            return false;
        }
        return true;
    }
}