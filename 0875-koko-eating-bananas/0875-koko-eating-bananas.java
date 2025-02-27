class Solution {
    public int minEatingSpeed(int[] piles, int h) {
        int max = 0;
        for (int pile : piles) {
            max = Math.max(max, pile);
        }

        int left = 1, right = max;
        while (left <= right) {
            int middle = left + (right - left) / 2;
            int k = middle;
            
            long timeTook = 0;
            for (int pile : piles) {
                timeTook += (pile + k - 1) / k;
            }
            
            if (timeTook <= h) {
                right = middle - 1;
            } else {
                left = middle + 1;
            }
        }
        return left;
    }
}
