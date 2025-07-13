class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int firstEndIndex = nums1.size() - nums2.size() - 1;
        int secondEndIndex = nums2.size() - 1;
        int pointer = nums1.size() - 1;

        while(firstEndIndex >= 0 && secondEndIndex >= 0){
            if(nums1[firstEndIndex] > nums2[secondEndIndex]){
                nums1[pointer] = nums1[firstEndIndex];
                firstEndIndex--;
            }else{
                nums1[pointer] = nums2[secondEndIndex];
                secondEndIndex--;
            }
            pointer--;
        }        
        if(secondEndIndex >= 0){
            while(secondEndIndex >= 0){
                nums1[pointer] = nums2[secondEndIndex];
                secondEndIndex--;
                pointer--;
            }
        }
        if(firstEndIndex >= 0){
            while(firstEndIndex >= 0){
                nums1[pointer] = nums1[firstEndIndex];
                firstEndIndex--;
                pointer--;
            }
        }
    }
};