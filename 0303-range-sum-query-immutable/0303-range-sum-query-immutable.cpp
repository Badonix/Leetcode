class NumArray {
public:
    NumArray(vector<int>& nums) {
        for(int i = 0; i < nums.size(); i++){
            if(i == 0){
                prefix.push_back(nums[i]);
            }else{
                prefix.push_back(nums[i] + prefix[i-1]);
            }
        }
    }
    
    int sumRange(int left, int right) {
        int l = left == 0 ? 0 : prefix[left - 1];
        return prefix[right] - l;
    }
private: 
    vector<int> prefix;
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */