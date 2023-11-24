class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (!prices.size()) {
      return 0;
    }

    int pri = prices[0];
    int ans = 0;

    for (int i = 1; i < prices.size(); ++i) {
      ans = max(prices[i] - pri, ans);
      pri = min(prices[i], pri);
    }

    return ans;
  }
};  // 8ms

class Solution {
 public:
  int maxProfit(vector<int>& prices) {
    if (!prices.size()) {
      return 0;
    }

    int max = 0;

    for (int i = 0; i < prices.size() - 1; ++i) {
      for (int j = i + 1; j < prices.size(); ++j) {
        if (prices[j] - prices[i] > max) {
          max = prices[j] - prices[i];
        }
      }
    }

    return max;
  }
};  // 820ms