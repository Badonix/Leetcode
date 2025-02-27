class Solution {
    public void setZeroes(int[][] matrix) {
        for(int row = 0; row < matrix.length; row++){
            boolean zeroDetected = false;
            for(int col = 0; col < matrix[0].length; col++){
                if(matrix[row][col] == 0){
                    zeroDetected = true;
                    for(int i = 0; i < matrix.length; i++){
                        if(matrix[i][col] != 0){
                            matrix[i][col] = -8734;
                        }
                    }
                    if(zeroDetected){
                        for(int i = 0; i < matrix[0].length; i++){
                            if(matrix[row][i] != 0){
                                matrix[row][i] = -8734;
                            }
                        }
                    }
                }
            }
        }
        for(int row = 0; row < matrix.length; row++){
            for(int col = 0; col < matrix[0].length; col++){
                if(matrix[row][col] == -8734){
                    matrix[row][col] = 0;
                }
            }
        }
    }
}