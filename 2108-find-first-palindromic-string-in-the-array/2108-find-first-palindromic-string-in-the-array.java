class Solution {
    public String firstPalindrome(String[] words) {
        for(String word : words){
            if(isPalindrome(word)){
                return word;
            }
        }
        return "";
    }
    private boolean isPalindrome(String str){
        StringBuilder sb = new StringBuilder(str);
        return sb.reverse().toString().equals(str);
    }
}