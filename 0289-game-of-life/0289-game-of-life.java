class Solution {
    public void gameOfLife(int[][] board) {
        int[][] temp = new int[board.length][board[0].length];
        for(int i = 0; i < board.length; i++){
            for(int j = 0; j < board[0].length; j++){
                int neighborsCount = countNeighbors(board, i ,j);
                if(board[i][j] == 1){
                    if(neighborsCount < 2){
                        temp[i][j] = 0;
                    }
                    if(neighborsCount == 2 || neighborsCount == 3){
                        temp[i][j] = 1;
                        continue;
                    }
                    if(neighborsCount > 3){
                        temp[i][j] = 0;
                    }
                }else{
                    if(neighborsCount == 3){
                        temp[i][j] = 1;
                    }
                }
            } 
        }        

        for(int i = 0; i < temp.length; i++){
            for(int j = 0; j < temp[0].length; j++){
                board[i][j] = temp[i][j];
            }
        }
    }

    // (1, 1)
    // -------
    // (0, 0)
    // (0, 1)
    // (1, 1)
    // (1, 0)
    // (1, 1)
    private int countNeighbors(int[][] board, int y, int x){
        int count = 0;
        for(int i = -1; i <= 1; i++){
            for(int j = -1; j <= 1; j++){
                if(i == 0 && j == 0) continue;
                int newY = y + i;
                int newX = x + j;
                if(newX >= 0 && newX < board[0].length && newY >= 0 && newY < board.length)
                {
                    if(board[newY][newX] == 1)count++;
                }
            }
        }
        return count;
    }
}
