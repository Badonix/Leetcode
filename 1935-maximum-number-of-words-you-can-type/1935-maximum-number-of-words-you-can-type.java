class Solution {
    public int canBeTypedWords(String text, String brokenLetters) {
        int count = 0;
        String[] arr = text.split(" ");
        for(String word : arr){
            boolean isPossible = true;
            for(int i = 0; i < word.length(); i++){
                if(brokenLetters.indexOf(word.charAt(i)) != -1){
                    isPossible = false;
                    break;
                }
            }
            if(isPossible){
                count++;
            }
        }
        return count;
    }
}