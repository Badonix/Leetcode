import java.util.*;

class Solution {
    private HashSet<Integer> used = new HashSet<>();
    
    public int[] constructDistancedSequence(int n) {
        int[] res = new int[2 * n - 1];
        backtrack(0, n, res);
        return res;
    }

    private boolean backtrack(int index, int n, int[] res) {
        while (index < res.length && res[index] != 0) {
            index++;
        }
        if (index == res.length) {
            return true;
        }

        for (int i = n; i >= 1; i--) {
            if (used.contains(i)) {
                continue;
            }
            if (i > 1 && (index + i >= res.length || res[index + i] != 0)) {
                continue;
            }

            used.add(i);
            res[index] = i;
            if (i > 1) {
                res[index + i] = i;
            }

            if (backtrack(index + 1, n, res)) {
                return true;
            }

            used.remove(i);
            res[index] = 0;
            if (i > 1) {
                res[index + i] = 0;
            }
        }
        return false;
    }
}
