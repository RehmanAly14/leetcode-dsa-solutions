class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int bestmin=nums[0];
        int bestmax=nums[0];  
        int globalMin = nums[0];
        int globalMax = nums[0];
        int n=nums.size();

        for(int i =1;i<n;i++){
            int v1=nums[i];
            int v2=bestmin+nums[i];
            int v3=bestmax+nums[i];
            bestmin=min(v1,v2);
            bestmax=max(v1,v3);

            globalMin = min(globalMin, bestmin);
            globalMax = max(globalMax, bestmax);
            
        }
        return max(abs(globalMin),abs(globalMax));
        
    }
};
