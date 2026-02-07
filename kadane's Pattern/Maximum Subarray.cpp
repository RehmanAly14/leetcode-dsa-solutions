class Solution {
public:
    int maxSubArray(vector<int>& nums) {
         int bestending=nums[0];
        int ans=nums[0];
        int n=nums.size();
        for(int i=1; i<n;i++){
            int v1=bestending+nums[i];
            int v2=nums[i];
            bestending=max(v1,v2);
            ans=max(ans,bestending);
        }
        return ans;
        
    }
};
