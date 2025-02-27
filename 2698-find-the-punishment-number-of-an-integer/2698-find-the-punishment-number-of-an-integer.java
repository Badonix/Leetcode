class Solution {
    public int punishmentNumber(int n) {
        int punishment = 0;
        for(int i = 1; i <= n; i++){
            int sq = i*i;
            if(checkIsOkay(sq + "", 0, i)){
                punishment += sq;
            }
        }
        return punishment;
    }

    private boolean checkIsOkay(String num, int index, int target) {
        if (index == num.length()) return target == 0;

        int sum = 0;
        for (int i = index; i < num.length(); i++) {
            sum = sum * 10 + (num.charAt(i) - '0');
            if (sum > target) break;
            if (checkIsOkay(num, i + 1, target - sum)) return true;
        }
        return false;
    }
}