class Solution {
 public:
  int minimumCoins(vector<int>& prices) {
    int n = prices.size();
    vector<int> dp(n + 1, -1);
    function<int(int)> dfs = [&](int cur) -> int {
      if (cur > n)
        return 0;
      if (dp[cur] != -1)
        return dp[cur];

      int sum = INT_MAX;
      for (int i = cur + 1; i <= cur * 2; ++i) {
        sum = min(sum, prices[cur - 1] + dfs(i));
      }
      sum = min(sum, prices[cur - 1] + dfs(2 * cur + 1));

      return dp[cur] = sum;
    };

    return dfs(1);
  }
};
// 98ms
// 20.50MB