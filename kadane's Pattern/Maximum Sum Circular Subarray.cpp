class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int n=nums.size();
        int bestmin=nums[0];
        int bestmax=nums[0];
        int minsum=nums[0];
        int maxsum=nums[0];
        int res =nums[0];
        int total=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=bestmin+nums[i];
            int v3=bestmax+nums[i];
            bestmin=min(v1,v2);
            minsum=min(minsum,bestmin);
            bestmax=max(v1,v3);
            maxsum=max(maxsum,bestmax);

            total +=nums[i];  
        }
         if(maxsum < 0)
            return maxsum;

        return max(maxsum, total - minsum);
    }
};
