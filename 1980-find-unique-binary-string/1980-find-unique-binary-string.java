class Solution {
    public String findDifferentBinaryString(String[] nums) {
        int max = (int)Math.pow(2,(nums.length)) - 1;
        HashSet<Integer> all = new HashSet<>();
        for(int i = 0; i < nums.length; i++){
            all.add(Integer.parseInt(nums[i], 2));
        }
        for(int i = max; i >= 0; i--){
            if(!all.contains(i)){
                String num = Integer.toBinaryString(i);
                while(num.length() != nums.length){
                    num = "0" + num;
                }
                return num;
            }
        }
        return "0";
    }
}