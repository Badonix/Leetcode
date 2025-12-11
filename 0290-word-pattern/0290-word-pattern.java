import java.util.*;
class Solution {
    public boolean wordPattern(String pattern, String s) {
        StringTokenizer st = new StringTokenizer(s);
        int index = 0;
        HashMap<Character, String> mapping = new HashMap<>();
        if(st.countTokens() != pattern.length()) return false;
        while(st.hasMoreTokens()){
            String currToken = st.nextToken();
            char c = pattern.charAt(index);
            ++index;
            if(mapping.containsKey(c)){
                if(mapping.get(c).equals(currToken)){
                    continue;
                }else{
                    return false;
                }
            }else if(mapping.containsValue(currToken)){
                return false;
            }
            mapping.put(c, currToken);
        }
        return true;
    }
}