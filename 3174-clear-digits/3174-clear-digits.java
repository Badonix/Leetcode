class Solution {
    public String clearDigits(String s) {
        StringBuilder str = new StringBuilder(s);
        while (true) {
            boolean found = false;
            for (int i = 0; i < str.length(); i++) {
                if (Character.isDigit(str.charAt(i))) {
                    found = true;
                    for (int j = i - 1; j >= 0; j--) {
                        if (!Character.isDigit(str.charAt(j))) {
                            str.deleteCharAt(i);
                            str.deleteCharAt(j);
                            break;
                        }
                    }
                    break;
                }
            }
            if (!found) {
                break;
            }
        }
        return str.toString();
    }
}
