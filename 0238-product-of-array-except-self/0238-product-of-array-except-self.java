class Solution {
    public int[] productExceptSelf(int[] nums) {
        int[] answ = new int[nums.length];
        int product = 1;
        int zeroCount = 0;
        int zeroIndex = -1;
        for(int i = 0; i < nums.length; i++){
            product *= nums[i];
            if(nums[i] == 0){
                zeroCount++;
                zeroIndex = i;
            } 
        }        
        if(zeroCount == 1){
            int product_without_zero = 1; 
            for(int i = 0; i < nums.length; i++){
                answ[i] = 0;
                if(nums[i] != 0) product_without_zero *= nums[i];
            }
            answ[zeroIndex] = product_without_zero;
            return answ;
        }
        for(int i = 0; i < nums.length; i++){
            if(zeroCount > 1){
                answ[i] = 0;
            }else{
                answ[i] = product / nums[i];
            }
        }        
        return answ;
    }
}