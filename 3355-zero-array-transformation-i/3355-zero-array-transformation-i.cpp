class Solution{
public:
    bool isZeroArray(vector<int>&nums,vector<vector<int>>&queries){
        int n=nums.size();
        vector<int>c(n+1);
        for(auto&q:queries){
            c[q[0]]++;
            if(q[1]+1<n)
                c[q[1]+1]--;
        }
        for(int i=1;i<n;i++)
            c[i]+=c[i-1];
        for(int i=0;i<n;i++)
            if(nums[i]>c[i])
                return false;
        return true;
    }
};