class Solution {
    public int maxAbsoluteSum(int[] nums) {
        int min = findMin(nums);
        int max = findMax(nums);
        return Math.max(Math.abs(min), Math.abs(max));
    }
    private int findMax(int[] arr){
        int res = arr[0];
        int maxEnding = arr[0];
        for (int i = 1; i < arr.length; i++) {
            maxEnding = Math.max(maxEnding + arr[i], arr[i]);
            res = Math.max(res, maxEnding);
        }
        return res;
    }
    private int findMin(int[] arr){
        int res = arr[0];
        int maxEnding = arr[0];
        for (int i = 1; i < arr.length; i++) {
            maxEnding = Math.min(maxEnding + arr[i], arr[i]);
            res = Math.min(res, maxEnding);
        }
        return res;
    }
}