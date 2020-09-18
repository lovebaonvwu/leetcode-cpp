class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    vector<int> dp(n);

    for (int i = 1; i < n; ++i) {
      for (int j = 0; j < i; ++j) {
        int prev = 0;
        if (j > 0) {
          prev = max(prev, dp[j - 1]);
        }

        int profit = max(prices[i] - prices[j] - fee + prev, dp[i - 1]);

        dp[i] = max(dp[i], profit);
      }
    }

    return dp[n - 1];
  }
};
// Time Limit Exceeded

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    vector<int> buy(n);
    vector<int> sell(n);

    buy[0] = -prices[0];
    sell[0] = 0;

    for (int i = 1; i < n; ++i) {
      buy[i] = max(buy[i - 1], sell[i - 1] - prices[i]);
      sell[i] = max(sell[i - 1], buy[i - 1] + prices[i] - fee);
    }

    return sell[n - 1];
  }
};
// Runtime: 252 ms, faster than 42.20%
// Memory Usage: 59.8 MB, less than 21.45%

class Solution {
 public:
  int maxProfit(vector<int>& prices, int fee) {
    int n = prices.size();

    int buy = -prices[0];
    int sell = 0;

    for (int i = 1; i < n; ++i) {
      buy = max(buy, sell - prices[i]);
      sell = max(sell, buy + prices[i] - fee);
    }

    return sell;
  }
};
// Runtime: 224 ms, faster than 92.79%
// Memory Usage: 55.1 MB, less than 63.74%