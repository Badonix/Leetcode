class Solution {
    public int findMin(int[] nums) {
        int left = 0;
        int right = nums.length - 1;
        int min = nums[0];
        while(left <= right){

            if(nums[left] < nums[right]){
                if(nums[left] < min){
                    min = nums[left];
                    break;
                }            
            }
            int middle = left + (right - left) / 2;
            if(nums[middle] < min){
                min = nums[middle];
            }
            if(nums[middle] >= nums[left]){
                left = middle + 1;
            }else{
                right = middle - 1;
            }
        }
        return min;
    }
}