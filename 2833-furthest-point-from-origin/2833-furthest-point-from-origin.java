class Solution {
    public int furthestDistanceFromOrigin(String moves) {
        int leftCounter = 0;
        int rightCounter = 0;
        int underscoreCounter = 0;
        for (int i = 0; i < moves.length(); i++){
            char current = moves.charAt(i);
            if(current == 'L'){
                leftCounter++;
            }else if(current == 'R'){
                rightCounter++;
            }else if(current == '_'){
                underscoreCounter++;
            }
        }
        if(leftCounter > rightCounter){
            leftCounter += underscoreCounter;
            return leftCounter - rightCounter;
        }else{
            rightCounter += underscoreCounter;
            return rightCounter - leftCounter;
        }
    }
}