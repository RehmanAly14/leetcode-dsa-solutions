class Solution {
public:

    int fun(vector<int>& a, int n, int i, int free,
            vector<vector<int>>& dp) {

        if (i >= n) return 0;

        if (dp[i][free] != -1) {
            return dp[i][free];
        }

        if (free == 0) {
            return dp[i][free] = fun(a, n, i + 1, 1, dp);
        }

        int c1 = a[i] + fun(a, n, i + 1, 0, dp);
        int c2 = fun(a, n, i + 1, 1, dp);

        return dp[i][free] = max(c1, c2);
    }

    int solve(vector<int>& arr) {

        int n = arr.size();

        vector<vector<int>> dp(n, vector<int>(2, -1));

        return fun(arr, n, 0, 1, dp);
    }

    int rob(vector<int>& nums) {

        int n = nums.size();
        if (n == 1) return nums[0];
        vector<int> case1(nums.begin(), nums.end() - 1); // exclude last
        vector<int> case2(nums.begin() + 1, nums.end()); // exclude first

        return max(solve(case1), solve(case2));
    }
};
