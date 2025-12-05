class Solution {
    public char repeatedCharacter(String s) {
        boolean[] freq = new boolean[26];
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            if(freq[c-'a']) return c;
            freq[c-'a'] = true;
        }
        return s.charAt(0);
    }
}