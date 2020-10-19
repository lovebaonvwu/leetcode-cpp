class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int firstBuy = INT_MAX;
    int firstStockProfit = 0;
    int secondBuy = INT_MAX;
    int secondStockProfit = 0;

    for (auto p : prices) {
      firstBuy = min(firstBuy, p);
      firstStockProfit = max(firstStockProfit, p - firstBuy);
      secondBuy = min(secondBuy, p - firstStockProfit);
      secondStockProfit = max(secondStockProfit, p - secondBuy);
    }

    return secondStockProfit;
  }
};
// Runtime: 16 ms, faster than 59.39%
// Memory Usage: 13.2 MB, less than 67.38%

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int n = prices.size();
    vector<vector<int>> dp(3, vector<int>(n));

    for (int i = 1; i < 3; ++i) {
      int tmpMax = dp[i - 1][0] - prices[0];
      for (int j = 1; j < n; ++j) {
        dp[i][j] = max(dp[i][j - 1], prices[j] + tmpMax);
        tmpMax = max(tmpMax, dp[i - 1][j] - prices[j]);
      }
    }

    return dp[2][n - 1];
  }
};
// Runtime: 252 ms, faster than 88.26%
// Memory Usage: 87.9 MB, less than 5.07%