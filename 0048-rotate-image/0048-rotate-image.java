class Solution {
    public void rotate(int[][] matrix) {
        for(int i = 0; i < matrix.length; i++){
            for(int j = 0; j < matrix[0].length; j++){
                if(i < j){
                    swap(matrix, i, j);
                }
            }
        }
        reverseCols(matrix);
    }

    private void reverseCols(int[][] matrix){
        for(int i = 0; i < matrix.length; i++){
            reverseArray(matrix[i]);
        }
    }
    private void swap(int[][] matrix, int i, int j){
        int temp = matrix[i][j];
        matrix[i][j] = matrix[j][i];
        matrix[j][i] = temp;
    }
    private void reverseArray(int[] arr) {
        int left = 0, right = arr.length - 1;
        while (left < right) {
            int temp = arr[left];
            arr[left] = arr[right];
            arr[right] = temp;
            left++;
            right--;
        }
    }
}
