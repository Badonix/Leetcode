class Solution {
    public boolean isArraySpecial(int[] nums) {
        boolean firstOdd = nums[0] % 2 != 0;
        
        for (int i = 0; i < nums.length; i++) {
            if ((i % 2 == 0 && (nums[i] % 2 != (firstOdd ? 1 : 0))) ||
                (i % 2 == 1 && (nums[i] % 2 != (firstOdd ? 0 : 1)))) {
                return false;
            }
        }
        return true;
    }
}
