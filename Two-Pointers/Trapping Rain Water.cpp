// Time : O(n)
// Space : O(1)

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        int l=0;
        int r=n-1;
        int total=0;
        int lMax=height[l];
        int rMax=height[r];
        while(l<r){
            if(height[l]<height[r]){
                lMax=max(lMax,height[l]);
                if(lMax-height[l]>0){
                    total=total+lMax-height[l];
                }
                l++;
            }
            else{
                rMax=max(rMax,height[r]);
                if(rMax-height[r]>0){
                    total=total+rMax-height[r];
                }
                r--;
            }
        }
        return total;
    }
};
