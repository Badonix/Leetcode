class Solution {
    public boolean check(int[] nums) {
        int n = nums.length;
        int[] doub = new int[n * 2];

        for (int i = 0; i < n; i++) {
            doub[i] = nums[i];
            doub[i + n] = nums[i];
        }

        for (int start = 0; start < n; start++) {
            int[] curr = new int[n];
            System.arraycopy(doub, start, curr, 0, n);
            
            if (isSorted(curr)) {
                return true;
            }
        }
        return false;
    }

    private boolean isSorted(int[] arr) {
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] > arr[i + 1]) {
                return false;
            }
        }
        return true;
    }
}
