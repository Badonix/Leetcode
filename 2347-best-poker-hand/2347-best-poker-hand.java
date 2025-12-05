class Solution {
    public String bestHand(int[] ranks, char[] suits) {
        HashMap<Integer, Integer> ranksMap = new HashMap<>();
        HashMap<Character, Integer> suitsMap = new HashMap<>();
        for(int rank : ranks){
            ranksMap.put(rank, ranksMap.getOrDefault(rank, 0)+1);
        }
        for(char suit : suits){
            suitsMap.put(suit, suitsMap.getOrDefault(suit, 0)+1);
        }

        if(suitsMap.size() == 1){
            return "Flush";
        }
        for(Integer rank : ranksMap.keySet()){
            if(ranksMap.get(rank) >= 3){
                return "Three of a Kind";
            }
        }
        for(Integer rank : ranksMap.keySet()){
            if(ranksMap.get(rank) == 2){
                return "Pair";
            }
        }
        return "High Card";
    }
}