class Solution {
    public char repeatedCharacter(String s) {
        int[] frequencyArray = new int[26];
        for(int i = 0; i < s.length(); i++){
            char c = s.charAt(i);
            frequencyArray[c-'a']++;
            if(frequencyArray[c-'a'] == 2){
                return c;
            }
        }
        return s.charAt(0);
    }
}