class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();

    if (n < 2) {
      return 0;
    }

    vector<int> dp(n);

    dp[1] = max(prices[1] - prices[0], 0);

    for (int i = 2; i < n; ++i) {
      dp[i] = dp[i - 1];

      for (int j = 0; j < i; ++j) {
        int prev = j < 2 ? 0 : dp[j - 2];
        dp[i] = max(dp[i], prices[i] - prices[j] + prev);
      }
    }

    return dp[n - 1];
  }
};
// Runtime: 196 ms, faster than 5.58%
// Memory Usage: 11.4 MB, less than 37.76%