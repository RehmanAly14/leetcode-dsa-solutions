class Solution {
public:
    int fun(vector<int>& c, int i, int j, vector<vector<int>>& dp) {

        if (i > j) {
            return 0;
        }

        if (dp[i][j] != -1) {
            return dp[i][j];
        }

        int res = INT_MAX;

        for (int k = i; k <= j; k++) {

            int cost = c[j + 1] - c[i - 1];

            int left = fun(c, i, k - 1, dp);
            int right = fun(c, k + 1, j, dp);

            res = min(res, cost + left + right);
        }

        return dp[i][j] = res;
    }

    int minCost(int n, vector<int>& cuts) {

        cuts.push_back(0);
        cuts.push_back(n);

        sort(cuts.begin(), cuts.end());

        int m = cuts.size();

        vector<vector<int>> dp(m, vector<int>(m, -1));

        return fun(cuts, 1, m - 2, dp);
    }
};
