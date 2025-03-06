class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {
        int[] frequency = new int[grid.length * grid.length + 1];
        for(int i = 0; i < grid.length; i++){
            for(int j = 0; j < grid.length; j++){
                frequency[grid[i][j]]++;
            }   
        }
        int[] answ = new int[2];
        for(int i = 0; i < frequency.length; i++){
            if(frequency[i] == 0){
                answ[1] = i;
            }else if(frequency[i] == 2){
                answ[0] = i;
            }
        }
        return answ;
    }
}