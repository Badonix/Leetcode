class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp;
        for(int i = 0; i < nums.size(); i++) if(nums[i] >= 0) temp.push_back(nums[i]);
        for(int i = 0; i < nums.size(); i++) if(nums[i] >= 0) temp.push_back(nums[i]);
        if(temp.size() < 2) return nums;
        k %= temp.size() / 2;
        vector<int> rotated;
        for(int i = k; i < k + temp.size() / 2; i++){
            rotated.push_back(temp[i]);
        }
        int j = 0;
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] >= 0) {
                nums[i] = rotated[j];
                j++;
            }
        }
        return nums;
    }
    // 1 2 3 1 2 3
    // 1 2 3 
    // 2 3 1
    // 3 1 2
    // 1 2 3
};