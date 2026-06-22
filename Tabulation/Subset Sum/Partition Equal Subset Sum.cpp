class Solution {
  public:
    bool equalPartition(vector<int>& arr) {
        // code here
          int n = arr.size();
          int sum =0;
          for(int i=0;i<n;i++){
              sum=sum +arr[i];
          }
          
          if(sum%2==1){
              return 0;
          }
          sum=sum/2;

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
                        || dp[i + 1][j];
                }
            }
        }

        return dp[0][sum];
    }
};
