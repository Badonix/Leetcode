class Solution {
    public boolean reportSpam(String[] message, String[] bannedWords) {
        HashSet<String> bannedSet = new HashSet<>();
        int counter = 0;
        for (String banned: bannedWords){
            bannedSet.add(banned);
        }
        for(String word : message){
            if(bannedSet.contains(word)){
                counter++;
                if(counter == 2){
                    return true;
                }
            }
        }
        return false;
    }

}