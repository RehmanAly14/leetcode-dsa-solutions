// User function Template for C++

class Solution {
  public:
    int smallestSumSubarray(vector<int>& a) {
        // Code here
        int bestending=a[0];
        int ans=a[0];
        int n=a.size();
        for(int i=1; i<n;i++){
            int v1=bestending+a[i];
            int v2=a[i];
            bestending=min(v1,v2);
            ans=min(ans,bestending);
        }
        return ans;
        
    }
};
