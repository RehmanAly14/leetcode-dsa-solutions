class Solution {
public:
    int maximumSum(vector<int>& arr) {
        int nodel=arr[0];
        int onedel=INT_MIN;
        int n=arr.size();
        int res=arr[0];
        for(int i=1;i<n;i++){
            int prevnodel=nodel;
            int prevonedel=onedel;
            nodel=max(arr[i],nodel+arr[i]);
            int v2=0;
            if(prevonedel == INT_MIN){
                v2=arr[i];
            }
            else{
                v2=prevonedel+arr[i];
            }
            onedel=max(v2,prevnodel);
            res=max(res,max(nodel,onedel));
        }
        return res;
    }
};
