class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int>ans;
        int n=nums1.size();
        int m=nums2.size();
        map<int,int>mpp;
        for(int i=0;i<m;i++){
            mpp[nums2[i]]=i;
        }
        for(int i=0;i<n;i++){
            int val=nums1[i];
            int next=-1;
            for(int j=mpp[val]+1;j<m;j++){
                if(nums2[j]>val){
                    next=nums2[j];
                    break;
                }
            }
            ans.push_back(next);
            
        }
        return ans;
    }
};