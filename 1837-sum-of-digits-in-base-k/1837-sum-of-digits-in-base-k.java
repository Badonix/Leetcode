class Solution {
    public int sumBase(int n, int k) {
        String base = "";
        while(true){
            if(n == 0){
                break;
            }
            base += n % k;
            n /= k;
        }
        int sum = 0;
        for(int i = 0; i < base.length(); i++){
            sum += base.charAt(i) - '0';
        }
        return sum;
    }
}