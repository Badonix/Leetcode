class Solution {
    public char findTheDifference(String s, String t) {
        String[] spltd1 = s.split("");
        String[] spltd2 = t.split("");
        ArrayList<String> letters = new ArrayList<String>();
        ArrayList<String> secondletters = new ArrayList<String>();
        for (String letter : spltd1) {
            letters.add(letter);
        }
        for (String letter : spltd2) {
            secondletters.add(letter);
        }

        for (String letter : letters) {
            secondletters.remove(letter);
        }
        return secondletters.get(0).charAt(0);
    }
}