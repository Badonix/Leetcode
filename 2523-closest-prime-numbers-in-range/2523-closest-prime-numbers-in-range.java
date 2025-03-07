class Solution {
    public int[] closestPrimes(int left, int right) {
       boolean[] sieve = new boolean[right + 1]; 
       sieve[0] = true;
       sieve[1] = true;
       
       for(int i = 0; i * i <= right; i++){
        if(!sieve[i]){
            for(int j = i * i; j <= right; j += i){
                sieve[j] = true;
            }
        }
       }
       ArrayList<Integer> primes = new ArrayList<>();

       for(int i = left; i <= right; i++){
        if(!sieve[i]){
            primes.add(i);
        }
       }

       int minDistance = Integer.MAX_VALUE;
       int[] answ = new int[]{-1, -1};
       if(primes.size() < 2){
        return answ;
       } 

       for(int i = 1; i < primes.size(); i++){
        int gap = primes.get(i) - primes.get(i-1);
        if(gap < minDistance){
            minDistance = gap;
            answ[0] = primes.get(i-1);
            answ[1] = primes.get(i);
        }
       }
       return answ;
    }
}