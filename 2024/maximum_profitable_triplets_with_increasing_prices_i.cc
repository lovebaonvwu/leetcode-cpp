class Solution {
 public:
  int maxProfit(vector<int>& prices, vector<int>& profits) {
    int n = prices.size();

    vector<int> sums(n);

    for (int j = 1; j < n; ++j) {
      for (int i = 0; i < j; ++i) {
        if (prices[i] < prices[j]) {
          sums[j] = max(sums[j], profits[i] + profits[j]);
        }
      }
    }

    int ans = -1;
    for (int k = 2; k < n; ++k) {
      for (int j = 1; j < k; ++j) {
        if (prices[j] < prices[k] && sums[j] > 0) {
          ans = max(ans, profits[k] + sums[j]);
        }
      }
    }

    return ans;
  }
};
// 282 ms
// 100.00 MB