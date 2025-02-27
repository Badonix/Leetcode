class ProductOfNumbers {

    private ArrayList<Integer> nums;
    private int product = 1;
    public ProductOfNumbers() {
        nums = new ArrayList<>();
    }
    
    public void add(int num) {
        if(num == 0){
            nums = new ArrayList<>();
            product = 1;
            return;
        }
        product *= num;
        nums.add(product);
    }
    
    public int getProduct(int k) {
        if(nums.size() < k){
            return 0;
        }
        int lastEl = nums.get(nums.size() - 1);
        if(nums.size() == k){
            return lastEl;
        } 
        return lastEl / nums.get(nums.size() - 1 - k);
    }
}

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers obj = new ProductOfNumbers();
 * obj.add(num);
 * int param_2 = obj.getProduct(k);
 */