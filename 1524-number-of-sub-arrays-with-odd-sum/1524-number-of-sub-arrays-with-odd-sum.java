class Solution {
    public int numOfSubarrays(int[] arr) {
        int oddCount = 0, evenCount = 1;
        final int MOD = 1_000_000_007;
        int currSum = 0, result = 0;
        for (int num : arr) {
            currSum += num;
            if (currSum % 2 == 0) {
                result = (result + oddCount) % MOD;
                evenCount++;
            } else {
                result = (result + evenCount) % MOD;
                oddCount++;
            }
        }
        return result;
    }
}