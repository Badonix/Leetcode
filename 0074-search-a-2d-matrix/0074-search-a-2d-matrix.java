class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int top = 0;
        int bottom = matrix.length - 1;
        int lastColIndex = matrix[0].length - 1;
        int rowToSearch = 0;
        while(top <= bottom){
            int middle = top + (bottom - top)/2;
            int middleMin = matrix[middle][0];
            int middleMax = matrix[middle][lastColIndex];
            if(target >= middleMin && target <= middleMax){
                if(target == middleMin || target == middleMax){
                    return true;
                }
                rowToSearch = middle;
                break;
            }

            if(target > middleMax){
                top = middle + 1;
            }else if(target < middleMin){
                bottom = middle - 1;
            }

        }
        return averageBinarySearch(matrix[rowToSearch], target);
    }
    private boolean averageBinarySearch(int[] arr, int target){
        int left = 0;
        int right = arr.length - 1;
        while(left <= right){
            int middle = left + (right - left) / 2;
            if(arr[middle] == target){
                return true;
            }else if(arr[middle] < target){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        return false;
    }
}