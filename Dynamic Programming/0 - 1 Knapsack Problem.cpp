class Solution {
  public:
  int fun(vector<int>&val,vector<int>&wt,int n,int i,int cap,vector<vector<int>>& dp){
      if(i==n){
          return 0;
      }
      if(dp[i][cap]!= -1){
          return dp[i][cap];
      }
      if(wt[i] > cap){
          return dp[i][cap]=fun(val,wt,n,i+1,cap,dp);
      }
      int yes = val[i] + fun(val,wt,n,i+1,cap-wt[i],dp);
      int no = fun(val,wt,n,i+1,cap,dp);
      
      return dp[i][cap]=max(yes,no);
  }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // code here
        int n= val.size();
        vector<vector<int>>dp(n);
        for(int i=0;i<n;i++){
            vector<int>t(W+1,-1);
            dp[i]=t;
        }
        return fun(val,wt,n,0,W,dp);
    }
};
