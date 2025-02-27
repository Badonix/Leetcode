class Solution {
    public int[] searchRange(int[] nums, int target) {
        int[] answ = {-1, -1};
        answ[0] = findFirst(nums, target);
        answ[1] = findLast(nums, target);
        return answ;
    }

    private int findFirst(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int index = -1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] >= target) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
            if (nums[middle] == target) index = middle;
        }
        return index;
    }

    private int findLast(int[] nums, int target) {
        int left = 0, right = nums.length - 1;
        int index = -1;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            if (nums[middle] <= target) {
                left = middle + 1;
            } else {
                right = middle - 1;
            }
            if (nums[middle] == target) index = middle;
        }
        return index;
    }
}
