class Solution {
 public:
  int maxProfit(int k, vector<int>& prices) {
    if (k == 0 || prices.empty()) {
      return 0;
    }

    int n = prices.size();

    if (k * 2 >= n) {
      int ans = 0;
      for (int i = 1; i < n; ++i) {
        ans += prices[i] > prices[i - 1] ? prices[i] - prices[i - 1] : 0;
      }

      return ans;
    }

    vector<vector<int>> dp(k + 1, vector<int>(n));

    for (int i = 1; i <= k; ++i) {
      int tmpMax = dp[i - 1][0] - prices[0];

      for (int j = 1; j < n; ++j) {
        dp[i][j] = max(dp[i][j - 1], prices[j] + tmpMax);
        tmpMax = max(tmpMax, dp[i - 1][j] - prices[j]);
      }
    }

    return dp[k][n - 1];
  }
};
// Runtime: 12 ms, faster than 72.51%
// Memory Usage: 13.3 MB, less than 6.44%