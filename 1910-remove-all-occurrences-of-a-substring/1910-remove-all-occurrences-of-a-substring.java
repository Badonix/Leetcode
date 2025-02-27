class Solution {
    public String removeOccurrences(String s, String part) {
        StringBuilder sb = new StringBuilder(s);
        int sbstrSize = part.length();
        for(int i = 0; i < sb.length(); i++){
            if(i+sbstrSize - 1 < sb.length() && sb.substring(i, i+sbstrSize).toString().equals(part)){
                sb = sb.delete(i, i+sbstrSize);
                if(i - sbstrSize < 0){
                    i = - 1;
                }else{
                    i = i - sbstrSize - 1;
                }
            }
        }
        return sb.toString();
    }
}