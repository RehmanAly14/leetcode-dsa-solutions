class Solution {
  public:
    int totalWays(vector<int>& arr, int target) {
        //  code here
         int n = arr.size();
          int totalsum =0;
          for(int i=0;i<n;i++){
              totalsum=totalsum + arr[i];
          }
          
          if((totalsum+target)%2==1){
              return 0;
          }
          if(abs(target)>totalsum){
              return 0;
          }
         int sum=(target+totalsum)/2;

        vector<vector<int>> dp(n + 1,
                                vector<int>(sum + 1, -1));
        
        for(int j=0;j<=sum;j++){
            dp[n][j]=0;
        }

        dp[n][0] = 1;

        for(int i = n - 1; i >= 0; i--) {
            for(int j = 0; j <= sum; j++) {

                if(arr[i] > j) {
                    dp[i][j] = dp[i + 1][j];
                }
                else {
                    dp[i][j] =
                        dp[i + 1][j - arr[i]]
                        + dp[i + 1][j];
                }
            }
        }

        return dp[0][sum];
    }
};
