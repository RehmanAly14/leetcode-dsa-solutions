class Solution {
public:
    int maxArea(vector<int>& height) {
        int n=height.size();
        int lp=0;
        int rp=n-1;
        int ans=0;
        while(lp<rp){
            int w=rp-lp;
            int h=min(height[lp],height[rp]);
            int currCon=w * h;
             ans=max(currCon,ans);
             if(height[lp]<height[rp]){
                lp++;
             }
             else{
                rp--;
             }
        }
        return ans;
        
    }
};
