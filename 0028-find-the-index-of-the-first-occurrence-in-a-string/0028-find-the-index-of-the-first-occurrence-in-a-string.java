class Solution {
    public int strStr(String haystack, String needle) {
        int answ = -1;
        for(int i = 0; i <= haystack.length() - needle.length(); i++){
            String currSubstring = haystack.substring(i, i+needle.length());
            if(currSubstring.equals(needle)){
                return i;
            }
        }
        return answ;
    }
}