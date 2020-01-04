class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int i = 0;
    int n = prices.size() - 1;
    int buy = 0;
    int sell = 0;

    int ans = 0;

    while (i < n) {
      while (i < n && prices[i + 1] <= prices[i])
        ++i;
      buy = prices[i];

      while (i < n && prices[i + 1] > prices[i])
        ++i;
      sell = prices[i];

      ans += sell - buy;
    }

    return ans;
  }
};
// Runtime: 8 ms, faster than 60.93%
// Memory Usage: 9.4 MB, less than 100.00%

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    int ans = 0;

    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1]) {
        ans += prices[i] - prices[i - 1];
      }
    }

    return ans;
  }
};
// Runtime: 12 ms, faster than 8.73%
// Memory Usage: 9.5 MB, less than 88.89%

class Solution {
 public:
  int maxProfit(vector<int>& prices) { return dfs(prices, 0); }

  int dfs(vector<int>& prices, int buy) {
    int ans = 0;
    for (int i = buy; i < prices.size(); ++i) {
      for (int j = i; j < prices.size(); ++j) {
        if (prices[j] > prices[i]) {
          ans = max(ans, prices[j] - prices[i] + dfs(prices, j + 1));
        }
      }
    }

    return ans;
  }
};
// Time Limit Exceeded