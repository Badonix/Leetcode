import java.util.HashMap;

class Solution {
    public long countBadPairs(int[] nums) {
        long count = 0;
        HashMap<Integer, Integer> m = new HashMap<>();
        long total = (long) nums.length * (nums.length - 1) / 2;
        for (int i = 0; i < nums.length; i++) {
            int curr = i - nums[i];
            m.put(curr, m.getOrDefault(curr, 0) + 1);
        }
        for (int key : m.keySet()) {
            int freq = m.get(key);
            if (freq > 1) {
                count += (long) freq * (freq - 1) / 2;
            }
        }
        return total - count;
    }
}
