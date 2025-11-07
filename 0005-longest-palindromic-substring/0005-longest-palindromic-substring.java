class Solution {
    public String longestPalindrome(String s) {
        String maxSub = "";
        for(int i = 0; i < s.length(); i++){
            for(int j = i; j <= s.length(); j++){
                String sub = s.substring(i, j);
                if(isPalindrome(sub) && sub.length() > maxSub.length()){
                    maxSub = sub;
                }
            }
        }
        return maxSub;
    }

    private boolean isPalindrome(String s){
        int left = 0;
        int right = s.length() - 1;
        while(left < right){
            if(s.charAt(left) != s.charAt(right)){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
}