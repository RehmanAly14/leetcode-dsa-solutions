class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int bestmin=nums[0];
        int bestmax=nums[0];
        int n=nums.size();
        int res=nums[0];
        for(int i=1;i<n;i++){
            int v1=nums[i];
            int v2=bestmin*nums[i];
            int v3=bestmax*nums[i];
            bestmin=min(v1,min(v2,v3));
            bestmax=max(v1,max(v2,v3));
            res=max(res,max(bestmin,bestmax));
        }
        return res;
    }
};
