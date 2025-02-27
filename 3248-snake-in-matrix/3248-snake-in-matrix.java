class Solution {
    public int finalPositionOfSnake(int n, List<String> commands) {
        int x = 0;
        int y = 0;
        for(String direction : commands){
            if(direction.equals("RIGHT")){
                x++;
            }else if(direction.equals("LEFT")){
                x--;
            }else if(direction.equals("DOWN")){
                y++;
            }else{
                y--;
            }
        }
        return y*n+x;
    }
}